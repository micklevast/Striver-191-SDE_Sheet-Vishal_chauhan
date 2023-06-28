#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode *makeBST(vector<int> &preorder,int idx,int maxi){
        if(idx>=preorder.size() || preorder[idx]>maxi)return NULL;
        TreeNode *nr=new TreeNode(preorder[idx]);
        idx++;
        nr->left=makeBST(preorder,idx,nr->val);
        nr->right=makeBST(preorder,idx,maxi);

        return nr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        int maxi=INT_MAX;
        return makeBST(preorder,idx,maxi);
    }
};