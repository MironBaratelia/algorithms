#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> p;

inline int get(int i, int j) {
	if (i < 0 || j < 0) {
		return 0;
	}
	return dp[i][j];
}

int main() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i;
	}
	cin >> m;
	vector<int> b(m);
	for (int& i : b) {
		cin >> i;
	}
	dp.resize(n, vector<int>(m, 0));
	p.resize(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = get(i - 1, j - 1) + 1;
				p[i][j] = 1;
			}
			else {
				if (get(i - 1, j) > get(i, j - 1)) {
					dp[i][j] = get(i - 1, j);
					p[i][j] = 2;
				}
				else {
					dp[i][j] = get(i, j - 1);
					p[i][j] = 3;
				}
			}
		}
	}
	int cur_i = n - 1;
	int cur_j = m - 1;
	vector<int> ans;
	while (get(cur_i, cur_j)) {
		if (p[cur_i][cur_j] == 1) {
			ans.push_back(a[cur_i]);
			--cur_i;
			--cur_j;
		}
		else if (p[cur_i][cur_j] == 2) {
			--cur_i;
		}
		else {
			--cur_j;
		}
	}
	cout << dp[n - 1][m - 1];
	reverse(ans.begin(), ans.end());
	for (int& i : ans) {
		cout << i << ' ';
	}
}
