#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

struct Node {
    int l, r;
    vector<int> v;
    Node *left, *right;
    Node(const vector<int>& v, int l, int r,
         Node *left = nullptr, Node *right = nullptr) :
        v(v), l(l), r(r), left(left), right(right) {}
};
typedef Node* PNode;

vector<int> merge_sort(const vector<int>& a,
                       const vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<int> c(n + m);

    int i = 0, j = 0;
    for (int q = 0; q < n + m; ++q) {
        if (i == n) {
            c[q] = b[j];
            ++j;
        } else if (j == m || a[i] < b[j]) {
            c[q] = a[i];
            ++i;
        } else {
            c[q] = b[j];
            ++j;
        }
    }
    return c;
}

PNode build(const vector<int>& a, int l = 0, int r = -1) {
    if (r == -1) r = a.size();

    if (l >= r) return nullptr;
    if (l + 1 == r) {
        return new Node({a[l]}, l, r);
    }

    int m = (l + r) / 2;
    PNode left = build(a, l, m);
    PNode right = build(a, m, r);

    vector<int> s = merge_sort(left->v, right->v);

    return new Node(s, l, r, left, right);
}

// количество элементов на отрезке [l; r) значение пренадлежащее [a; b)
int get_cnt(const PNode& node, int l, int r, int a, int b) {
    if (!node) return 0;
    if (node->l >= r || node->r <= l) {
        return 0;
    }
    if (l <= node->l && node->r <= r) {
        int l_ind = lower_bound(node->v.begin(), node->v.end(), a) - node->v.begin();
        int r_ind = lower_bound(node->v.begin(), node->v.end(), b) - node->v.begin();
        return r_ind - l_ind;
    }
    int cnt1 = get_cnt(node->left, l, r, a, b);
    int cnt2 = get_cnt(node->right, l, r, a, b);
    return cnt1 + cnt2;
}

int main() {
    vector<int> a = {1, 4, 7, 3, 5, 2, 8, 6, 7, 7, 7, 3, 4, 5, 2, 9, 5, 0};
    PNode root = build(a);
    cout << get_cnt(root, 0, 10, 2, 7);
}
