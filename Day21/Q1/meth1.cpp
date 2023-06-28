#include<bits/stdc++.h>
using namespace std;
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans=INT_MIN;
    while(root){
        if(root->val >X){
            
            root=root->left;
        }
        else if(root->val < X){
            ans=root->val;
            root=root->right;
        }
        else{
            ans=root->val;
            break;
        }
    }
    return ans;
}