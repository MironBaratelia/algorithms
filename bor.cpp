#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
	int cnt;
	int sum;
	vector<Node*> kids;
	Node() {
		cnt = 0;
		sum = 0;
		kids.resize(26, nullptr);
	}
};

void add(Node* v, const string& s, int pos) {
	if (pos == s.size()) {
		v->cnt++;
		v->sum++;
		return;
	}
	v->sum++;
	int kid = s[pos] - 'a';
	if (v->kids[kid] == nullptr) {
		v->kids[kid] = new Node();
	}
	add(v->kids[kid], s, pos + 1);
}


bool del(Node* v, const string& s, int pos) {
	if (pos == s.size()) {
		if (v->cnt == 0) {
			return 0;
		}
		else {
			v->cnt--;
			v->sum--;
			return 1;
		}
	}
	int kid = s[pos] - 'a';
	if (v->kids[kid] == nullptr) {
		return 0;
	}
	bool res = del(v->kids[kid], s, pos + 1);
	if (res) {
		v->sum--;
	}
	if (v->kids[kid]->sum == 0) {
		delete v->kids[kid];
		v->kids[kid] = nullptr;
	}
	return res;
}

int main() {
	Node* root = new Node();

	string s; 
	cin >> s;

	add(root, s, 0);
}
