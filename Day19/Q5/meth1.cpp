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
//  --------method 1-------using morris traversal-----------


    void flatten(TreeNode* root) {
        // morris traversal is iterative traversal
        if(root==NULL)return ;
        while(root){
            if(root->left==NULL){
                root=root->right;
            }
            else{
                TreeNode *temp=root->left;
                while(temp->right && temp->right!=root){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=root->right;
                    root->right=root->left;
                    root->left=NULL;
                    root=root->right;
                }
                else if(temp->right==root){
                    root = root->right;
                }
            }
        }
    }
};