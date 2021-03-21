#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dividers(int x) {
	vector<int> ans;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			ans.push_back(i);
			if (i * i != x) {
				ans.push_back(x / i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {

}
