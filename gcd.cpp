#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (a != 0) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int main() {

}
