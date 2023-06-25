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
//  time complexity of the code is O(n), and the space complexity is O(n).
class Solution {
public:
    int hgt(TreeNode *root,int &ans){
        if(root==NULL)return 0;
        int lh=hgt(root->left,ans);
        int rh=hgt(root->right,ans);
        ans=max(ans,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int ans=0;
        hgt(root,ans);
        return ans;
    }
};