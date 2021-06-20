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
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

void del(PNode& node, int x) {
    if (!node) return;
    if (node->key == x) {
        node = merge(node->l, node->r);
    }
    else if (node->key > x) {
        del(node->l, x);
        update(node);
    }
    else {
        del(node->r, x);
        update(node);
    }
}

int exists(PNode node, int x) {
    if (!node) return 0;
    if (node->key == x) {
        return 1 + getW(node->l);
    }
    else if (node->key > x) {
        return exists(node->l, x);
    }
    else {
        int w = exists(node->r, x);
        return w ? w + getW(node->l) + 1 : w;
    }
}

PNode insert(PNode node, int x) {
    if (exists(node, x)) {
        return node;
    }
    auto tmp1 = split(node, x);
    auto tmp2 = merge(tmp1.first, new Node(x));
    return merge(tmp2, tmp1.second);
}

void print_tree(PNode node) {
    if (node) {
        print_tree(node->l);
        cout << node->key << "(" << node->w << ") ";
        print_tree(node->r);
    }
}

int sum(PNode root, int l, int r) {
    auto tmp1 = split(root, l);
    auto tmp2 = split(tmp1.second, r + 1);
    return getSum(tmp2.first);
}

int main() {
    gen.seed((int)time(0));

    PNode root = nullptr;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;

        if (s[0] == 'i') {
            root = insert(root, x);
        }
        else if (s[0] == 'e') {
            cout << (exists(root, x) ? "true" : "false") << '\n';
        }
        else if (s[0] == 'd') {
            del(root, x);
        }
    }
}
