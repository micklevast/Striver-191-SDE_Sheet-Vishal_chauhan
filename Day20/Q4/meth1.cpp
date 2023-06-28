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
    TreeNode *BST(vector<int> &preorder,int &idx,int maxi,int mini){
        if(idx>=preorder.size() || maxi<preorder[idx] || mini>preorder[idx] )return nullptr;
        TreeNode *ptr=new TreeNode(preorder[idx]);
        idx++;
        ptr->left=BST(preorder,idx,(ptr->val-1),mini);
        ptr->right=BST(preorder,idx,maxi,(ptr->val));

        return ptr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        int max=INT_MAX,min=INT_MIN;
        return BST(preorder,idx,max,min);
    }
};