#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int x, y;
	int g = gcd(a, b, x, y);
	int sign_a = 1, sign_b = 1;
	if (a < 0) sign_a = -1;
	if (b < 0) sign_b = -1;
	a = abs(a); b = abs(b);
	if (c % g != 0) {
		cout << "No solution\n";
		return 0;
	}
	a *= sign_a;
	b *= sign_b;
	x *= (c / g) * sign_a;
	y *= (c / g) * sign_b;

	cout << a << " * " << x << " + " << b << " * " << y << " = " << c;
}
