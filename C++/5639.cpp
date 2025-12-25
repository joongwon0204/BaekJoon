// https://www.acmicpc.net/problem/5639
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}

    void setLeft(Node* node) {
        left = node;
    }

    void setRight(Node* node) {
        right = node;
    }
};

class BST {
public:
    Node* root;

    BST() : root(NULL) {}

    void insert(int key) {
        Node* x = root;
        Node* y = NULL;

        while (x != NULL) {
            y = x;
            if (key < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        if (y == NULL) root = new Node(key);
        else if (key < y->value) {
            y->setLeft(new Node(key));
        } else {
            y->setRight(new Node(key));
        }
    }

    void doPostWalk() {
        postWalk(root);
    }

    void postWalk(Node* root) {
        if (root == NULL) return;
        postWalk(root->left);
        postWalk(root->right);
        cout << root->value << "\n";
    }
};

int main() {
    BST tree;
    int tmp;
    while (cin >> tmp) {
        tree.insert(tmp);
    }
    tree.doPostWalk();
    return 0;
}