#include<bits/stdc++.h>
using namespace std;

// -----------below method is not giving right answer for----------
                        // 5
                    // 6        7
                // null null   8  9
//Function to return a list containing elements of left view of the binary tree.
// void find(Node *root,vector<int> &ans){
//     if(root==NULL)return;
//     while(root){
//         ans.push_back(root->data)  ;
//         if(root->left)root=root->left;
//         else root=root->right;
//     }
// }
// ------------------------------------------------------
void finding(Node *root,vector<int> &ans,int lvl){
    if(root==NULL)return;
    if(lvl==ans.size())ans.push_back(root->data);
    finding(root->left,ans,lvl+1);
    finding(root->right,ans,lvl+1);
    
}
vector<int> leftView(Node *root)
{
  // Your code here
//   find(root,ans);
   vector<int> ans;
   int lvl=0;
    finding(root,ans,lvl);
   return ans;
}