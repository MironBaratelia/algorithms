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

int getSum(PNode node) {
    return node ? node->sum : 0;
}

int getW(PNode node) {
    return node ? node->w : 0;
}

void update(PNode node) {
    node->sum = getSum(node->l) + getSum(node->r) + node->key;
    node->w = getW(node->l) + getW(node->r) + 1;
}

pair<PNode, PNode> split(PNode node, int x) {
    if (!node) {
        return { nullptr, nullptr };
    }
    if (node->key > x) {
        auto tmp = split(node->l, x);
        node->l = tmp.second;
        update(node);
        return { tmp.first, node };
    }
    else {
        auto tmp = split(node->r, x);
        node->r = tmp.first;
        update(node);
        return { node, tmp.second };
    }
}

PNode merge(PNode l, PNode r) {
    if (!l || !r) {
        return l ? l : r;
    }
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    }
    else {
        r->l = merge(r->l, l);
        update(r);
        return r;
    }
}

int sum(PNode root, int l, int r) {
    auto tmp1 = split(root, l);
    auto tmp2 = split(tmp1.second, r + 1);
    int ans = getSum(tmp2.first);
    tmp1.second = merge(tmp2.first, tmp2.second);
    root = merge(tmp1.first, tmp1.second);
    return ans;
}

int main() {
    gen.seed((int)time(0));

    PNode root = nullptr;
    for (int i = 0; i <= 10; ++i) {
        PNode tmp = new Node(i);
        root = merge(root, tmp);
    }
    cout << sum(root, 0, 9) << '\n';
}
