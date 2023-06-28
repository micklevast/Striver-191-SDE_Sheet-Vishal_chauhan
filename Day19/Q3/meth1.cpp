
#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& ino, int is, int ie, vector<int>& posto, int ps, int pe, unordered_map<int, int>& hm) {
        if (is > ie || ps > pe) {
            return NULL;
        }

        TreeNode* root = new TreeNode(posto[pe]);
        int inoRootIndex = hm[posto[pe]];
        int leftSize = inoRootIndex - is;

        root->left = buildTreeHelper(ino, is, is + leftSize-1, posto, ps, ps + leftSize - 1, hm);
        root->right = buildTreeHelper(ino, is + leftSize+1 , ie, posto, ps + leftSize, pe - 1, hm);

        return root;
    }

    TreeNode* buildTree(vector<int>& ino, vector<int>& posto) {
        unordered_map<int, int> hm;
        for (int i = 0; i < ino.size(); i++) {
            hm[ino[i]] = i;
        }

        return buildTreeHelper(ino, 0, ino.size() - 1, posto, 0, posto.size() - 1, hm);
    }
};
