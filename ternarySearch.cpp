#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> a;

double f(double x) {
	return x * x - 3 * x + 2;
}

int main() {
	double l = -100, r = 100;
	for (int it = 0; it < 100; ++it) {
		double m1 = l + (r - l) / 3;
		double m2 = m1 + (r - l) / 3;
		if (f(m1) < f(m2)) {
			r = m2;
		}
		else {
			l = m1;
		}
	}
	cout.precision(10);
	cout << l << '\n';
}
