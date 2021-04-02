#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> w(n + 1), c(n + 1);
	for (int i = 1; i <= n; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) cin >> c[i];
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	vector<vector<bool>> p(n + 1, vector<bool>(m + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = dp[i - 1][j];
			p[i][j] = 0;
			if (j >= w[i] && dp[i - 1][j - w[i]] + c[i] > dp[i][j]) {
				dp[i][j] = dp[i - 1][j - w[i]] + c[i];
				p[i][j] = 1;
			}
		}
	}
	int cur_x = n, cur_y = m;
	vector<int> ans;
	while (cur_x > 0) {
		if (p[cur_x][cur_y]) {
			ans.push_back(cur_x);
			cur_y -= w[cur_x];
		}
		cur_x--;
	}
	reverse(ans.begin(), ans.end());
	for (int e : ans) {
		cout << e << '\n';
	}
}
