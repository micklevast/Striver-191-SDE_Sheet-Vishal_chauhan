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
    TreeNode* preorder(TreeNode *root,int val){
        if(root==NULL)return NULL;

        if(root->val==val)return root;
        TreeNode *lt=preorder(root->left,val);
        if(lt!=NULL)return lt;
        TreeNode *rt=preorder(root->right,val);
        return rt;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)return root;
        // writting preorder traversal
        return preorder(root,val);
    }
};