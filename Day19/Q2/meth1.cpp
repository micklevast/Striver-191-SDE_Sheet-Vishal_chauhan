#include<bits/stdc++.h>
using namespace std;

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
    TreeNode* make(vector<int>& preorder,int ps,int pe, vector<int>& inorder,int is,int ie,unordered_map<int,int> &mp){
        if(ps>pe || is>ie)return NULL;
         TreeNode *nd=new TreeNode(preorder[ps]);
         int inorderRootIndex=mp[preorder[ps]];
         int leftSize=inorderRootIndex-is;

         nd->left=make(preorder,ps+1,ps+leftSize,inorder,is,inorderRootIndex-1,mp);
         nd->right=make(preorder,ps+leftSize+1,pe,inorder,inorderRootIndex+1,ie,mp);

         return nd;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size())return NULL;
        // making a map to get index of root in O(1)
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        TreeNode *ans=make(preorder,0,preorder.size()-1,inorder,0,inorder.size(),mp);
        return ans;
    }
};