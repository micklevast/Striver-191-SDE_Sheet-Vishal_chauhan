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
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if (root == nullptr)
            return;

        if (root->key == key) {
            // If the key is found in the tree
            // Predecessor will be the maximum value in the left subtree
            if (root->left) {
                pre = root->left;
                while (pre->right)
                    pre = pre->right;
            }

            // Successor will be the minimum value in the right subtree
            if (root->right) {
                suc = root->right;
                while (suc->left)
                    suc = suc->left;
            }
            return;
        }

        // If the key is smaller than the root value, search in the left subtree
        if (key < root->key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        // If the key is larger than the root value, search in the right subtree
        else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};
