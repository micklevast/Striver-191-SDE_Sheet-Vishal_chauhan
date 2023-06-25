#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.

    vector<vector<int>> ans;
    if(root==NULL)return ans;
    vector<int> ino,preo,posto;
    stack<pair<BinaryTreeNode<int>*,int>> st;
    st.push({root,0});
    while(!st.empty()){
        BinaryTreeNode<int> *temp=st.top().first;
        int whichOne=st.top().second;
        st.pop();
        if(whichOne==0){
            ino.push_back(temp->data);
            st.push({temp,whichOne+1});
            if(temp->left)
            st.push({temp->left,0});
        }
        else if(whichOne==1 ){
            preo.push_back(temp->data);
            st.push({temp,whichOne+1});
            if(temp->right)
            st.push({temp->right,0});
        }
        else{
            posto.push_back(temp->data);
            
        }
    }
    ans.push_back(preo);
    ans.push_back(ino);
    ans.push_back(posto);
    return ans;

}