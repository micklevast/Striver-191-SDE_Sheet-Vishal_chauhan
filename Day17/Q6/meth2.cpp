#include<bits/stdc++.h>
using namespace std;


void find(Node *root,vector<int> &ans){
    if(root==NULL)return ;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node *temp=q.front();
            if(i==0)ans.push_back(temp->data);
            
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   int lvl=0;

    find(root,ans);
   return ans;
}