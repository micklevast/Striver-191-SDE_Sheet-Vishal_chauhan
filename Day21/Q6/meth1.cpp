#include<bits/stdc++.h>
using namespace std;
class BSTIterator {
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *nd=st.top();
        st.pop();
        if(nd->right){
            TreeNode *node=nd->right;
            pushAll(node);
        }
        return nd->val;
    }
    
    bool hasNext() {
        return st.size()==0?false:true;
    }
    void pushAll(TreeNode *root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};
