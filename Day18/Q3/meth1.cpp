#include <bits/stdc++.h> 

Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//   time complexity of the code is O(n^2), and the space complexity is O(n).
class Solution {
public:
    int hgt(TreeNode *root){
        if(root==NULL)return 0;
        return 1+max(hgt(root->left),hgt(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int lh=hgt(root->left);
        int rh=hgt(root->right);
        int dia=lh+rh+1;
        return max(dia-1,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};