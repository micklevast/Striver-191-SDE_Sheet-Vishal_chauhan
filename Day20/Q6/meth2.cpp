#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* left;
	struct Node* right;

	Node(int x) {
		key = x;
		left = NULL;
		right = NULL;
	}
};

class Solution {
    Node* findPre(Node* root, int key) {
        Node* pre = NULL;
        while (root) {
            if (root->key >= key) {
                root = root->left;
            } else {
                pre = root;
                root = root->right;
            }
        }
        return pre;
    }

    Node* findSuc(Node* root, int key) {
        Node* suc = NULL;
        while (root) {
            if (root->key <= key) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }

public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        pre = findPre(root, key);
        suc = findSuc(root, key);
    }
};
