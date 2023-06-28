
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void change(BinaryTreeNode < int > * root){
    if(root==nullptr)return;
    int sum=0;
    sum+=root->data;
    if(root->left )sum+=root->left->data;
    if(root->right)sum+=root->right->data;
    if(sum>= root->data)root->data=sum;
    else //if(sum<(root->data))
    {
        if(root->left)root->left->data=root->data;
        if(root->right)root->right->data=root->data;
    }
    
    change(root->left);
    change(root->right);

    int suma=0;
    suma+=root->data;
    if(root->left )suma+=root->left->data;
    if(root->right)suma+=root->right->data;    
    if(root->left || root->right) root->data=suma;

}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    change(root);
    

}  