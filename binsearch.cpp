#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> a(n);
	//input
	int y; 
	int l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (a[m] <= y) {
		// if (a[m] >= y)
			l = m;
			// r = m;
		}
		else {
			r = m;
			// l = m;
		}
	}
	int ans = l; // a[l] <= y
	// int ans = r; a[r] >= y
}
