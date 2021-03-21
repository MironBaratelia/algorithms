#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> lp(n + 1, 0);
	vector<int> primes;
	for (int i = 2; i <= n; ++i) {
		if (lp[i] == 0) {
			primes.push_back(i);
			lp[i] = i;
		}
		for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && primes[j] * i <= n; ++j) {
			lp[primes[j] * i] = primes[j];
		}
	}
}
