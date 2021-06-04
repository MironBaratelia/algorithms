#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
 
using namespace std;
 
vector<int> pref(string s) {
    vector<int> p(s.size());
    p[0] = 0;
    int k = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (k > 0 && s[k] != s[i]) {
            k = p[k - 1];
        }
        if (s[k] == s[i]) {
            ++k;
        }
        p[i] = k;
    }
    return p;
}
 
int main() {
    string s;
    cin >> s;
    vector<int> p = pref(s);
    for (int x : p) {
        cout << x << ' ';
    }
    return 0;
}
