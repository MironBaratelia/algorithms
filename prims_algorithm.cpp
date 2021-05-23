#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <set>

using namespace std;

const int INF = 1e9;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> gr(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		gr[u - 1].push_back({ v - 1, w });
		gr[v - 1].push_back({ u - 1, w });
	}
	vector<int> d(n, INF);
	d[0] = 0;
	set<pair<int, int>> s;
	s.insert({ 0, 0 });
	long long minost = 0;
	vector<bool> added(n, 0);
	for (int i = 0; i < n; ++i) {
		int v = s.begin()->second;
		added[v] = 1;
		minost += s.begin()->first;
		s.erase(s.begin());
		for (auto& i : gr[v]) {
			int u = i.first, w = i.second;
			if (d[u] > w and !added[u]) {
				s.erase({ d[u], u });
				d[u] = w;
				s.insert({ d[u], u });
			}
		}
	}
}
