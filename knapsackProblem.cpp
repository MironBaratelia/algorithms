#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int n, W;
	cin >> n >> W;
	vector<int> w(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	vector<int> c(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(W + 1));
	vector<vector<int>> p(n + 1, vector<int>(W + 1, -1));
	dp[1][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= W; ++j) {
			dp[i][j] = dp[i - 1][j];
			p[i][j] = 0;
			if (w[i] <= j && dp[i - 1][j - w[i]] > dp[i][j]) {
				dp[i][j] = dp[i - 1][j - w[i]];
				p[i][j] = 1;
			}
		}
	}
	int pos = 0;
	for (int i = 0; i < W; ++i) {
		if (dp[n][i] > dp[n][pos]) {
			pos = i;
		}
	}
	int cur_i = n, cur_j = pos;
	vector<int> ans;
	while (cur_i > 0) {
		if (p[cur_i][cur_j] == 0) {
			cur_i--;
		}
		else {
			ans.push_back(cur_i);
			cur_j -= w[cur_i];
			cur_i--;
		}
	}
}
