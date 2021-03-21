#include <iostream>

using namespace std;

bool isPrime(int x) {
	if (x % 2 == 0) {
		return 0;
	}
	for (int i = 3; i * i < x; i += 2) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	
}
