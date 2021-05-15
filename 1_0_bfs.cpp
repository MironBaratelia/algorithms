#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <deque>

using namespace std;

const int INF = 1e9;

int main() {
	int n, m; 
	cin >> n >> m;
	vector<vector<pair<int, int>>> gr(n);
	for (int i = 0; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		gr[u].push_back({ v, w });
		gr[v].push_back({ u, w });
	}
	int s;
	cin >> s;
	s--;
	deque<int> q;
	vector<int> d(n, INF);
	q.push_back(s);
	d[s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop_front;
		for (auto& i : gr[v]) {
			int u = i.first, w = i.second;
			if(d[u] > d[v] + w) {
				d[u] = d[v] + w;
				if (w == 0) {
					q.push_front(u);
				}
				else {
					q.push_back(u);
				}
			}
		}
	}
}
