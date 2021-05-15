#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <deque>
#include <set>

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
	int start;
	cin >> start;
	start--;
	vector<int> d(n, INF);
	vector<bool> used(n, 0);
	d[start] = 0;
	set<pair<int, int>> s;
	s.insert({ 0, start });
	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());
		for (auto& i : gr[v]) {
			int u = i.first, w = i.second;
			if (d[u] > d[v] + w) {
				s.erase({ d[u], u });
				d[u] = d[v] + w;
				s.insert({ d[u], u });
			}
		}
	}
}
