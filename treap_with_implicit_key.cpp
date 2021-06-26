#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen;

struct Node {
    int key, prior, sum, w;
    Node* l, * r;
    Node(int key) : key(key), sum(key), w(1), prior(gen()), l(nullptr), r(nullptr) {}
};
typedef Node* PNode;

void print(PNode node) {
    if (!node) return;
    print(node->l);
    cout << node->key << ' ';
    print(node->r);
}

int get_w(PNode node) {
    return node ? node->w : 0;
}

int get_sum(PNode node) {
    return node ? node->sum : 0;
}

void update(PNode node) {
    if (!node) return;
    node->w = get_w(node->l) + get_w(node->r) + 1;
    node->sum = get_sum(node->l) + get_sum(node->r) + node->key;
}

pair<PNode, PNode> split(PNode node, int k) {
    if (!node) {
        return {nullptr, nullptr};
    }
    if (get_w(node->l) + 1 <= k) {
        auto res = split(node->r, k - get_w(node->l) - 1);
        node->r = res.first;
        update(node);
        return {node, res.second};
    } else {
        auto res = split(node->l, k);
        node->l = res.second;
        update(node);
        return {res.first, node};
    }
}

PNode merge(PNode left, PNode right) {
    if (!left || !right) {
        return (left ? left : right);
    }
    if (left->prior > right->prior) {
        left->r = merge(left->r, right);
        update(left);
        return left;
    } else {
        right->l = merge(left, right->l);
        update(right);
        return right;
    }
}

PNode build(vector<int>& els) {
    if (els.empty()) {
        return nullptr;
    }
    PNode root = new Node(els[0]);
    int n = els.size();
    for (int i = 1; i < n; ++i) {
        PNode node = new Node(els[i]);
        root = merge(root, node);
    }
    return root;
}

int sum(PNode node, int l, int r) {     // [l; r)
    auto tmp1 = split(node, r);
    auto tmp2 = split(tmp1.first, l);
    int res = tmp2.second->sum;
    tmp1.first = merge(tmp2.first, tmp2.second);
    node = merge(tmp1.first, tmp2.second);
    return res;
}

int sum2(PNode node, int l, int r) {
    if (!node) return 0;
    int k = node->w;
    if (l > 0 || r < k) {
        int d = get_w(node->l) + 1;
        return sum2(node->l, l, r) +
               sum2(node->r, l - d, r - d) +
               (d > l && d <= r ? node->key : 0);
    } else if (r <= 0 || l >= k) {
        return 0;
    } else {
        return node->sum;
    }
}

int main() {
    gen.seed((int)time(0));

    PNode root = nullptr;

    int l = 1, r = 3;

    vector<int> a = {1, 5, 2, 7, 11, 5, 5, 2, 8};
    for (int i = 0; i < 50; ++i) {
        root = build(a);
        cout << sum(root, l, r) << ' ';
    }
    cout << "\n";
    for (int i = 0; i < 50; ++i) {
        root = build(a);
        cout << sum2(root, l, r) << ' ';
    }

}
