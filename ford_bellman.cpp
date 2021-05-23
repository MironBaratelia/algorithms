#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

const int INF = 1e9;

struct Edge {
	int u, v, w; // из вершины u в вершину v за w
	Edge() {}
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(Edge(u - 1, v - 1, w));
	}
	vector<int> d(n, INF);
	d[0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (auto& e : edges) {
			if (d[e.u] != INF && d[e.v] > d[e.u] + e.w) {
				d[e.v] = d[e.u] + e.w;
			}
		}
	}
	vector<int> old = d;

	for (int i = 0; i < n - 1; ++i) {
		for (auto& e : edges) {
			if (d[e.u] != INF && d[e.v] > d[e.u] + e.w) {
				d[e.v] = d[e.u] + e.w;
			}
		}
	}

	if (old != d) {
		cout << "Cycle\n";
	}
	else {
		cout << d[i] << "\n";
	}
}
