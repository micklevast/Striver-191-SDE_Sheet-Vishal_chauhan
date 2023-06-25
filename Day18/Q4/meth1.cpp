#include <bits/stdc++.h> 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int hgt(TreeNode *root){
        if(root==NULL)return 0;
        int lh=hgt(root->left);
        int rh=hgt(root->right);
        return 1+max(lh,rh);
    }
    // bool isBalanced(TreeNode* root) {
    //     if(root==NULL)return true;
    //     int lh=hgt(root->left);
    //     int rh=hgt(root->right);
    //     if(abs(lh-rh)>1)return false;

    //     bool l=isBalanced(root->left);
    //     bool r=isBalanced(root->right);
    //     if(l==false || r==false)return false;
    //     else return true;
    // }

    // -----------------or------------------

        bool isBalanced(TreeNode* root) {
        
        if (root == NULL) return true;
        int lh = hgt(root->left);
        int rh = hgt(root->right);
        if (abs(lh - rh) > 1) return false;

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        return l && r;  // Return the logical AND of l and r
    }
};