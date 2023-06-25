#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(TreeNode *root,vector<int> &ans){
        if(root==NULL)return;
        find(root->left,ans);
        ans.push_back(root->val);
        find(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        find(root,ans);
        return ans;
    }
};