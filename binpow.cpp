#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll binpow(ll a, ll n, ll Mod) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		ll res = binpow(a, n / 2, Mod);
		return (res * res) % Mod;
	}
	else {
		ll res = binpow(a, n - 1, Mod);
		return (res * a) % Mod;
	}
}

// a ^ n % Mod

int main() {
	ll a, n, Mod;
	cin >> a >> n >> Mod;
	cout << binpow(a, n, Mod);
}
