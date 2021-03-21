#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<bool> isprime(n + 1, true);
	vector<int> primes;
	for (int i = 2; i <= n; ++i) {
		if (isprime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				isprime[j] = false;
			}
		}
	}
}
