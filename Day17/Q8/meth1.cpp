#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void find(Node *root,vector<int> &ans){
        map<int,int> mp;
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            Node *temp=q.front().first;
            int line=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            if(mp.find(line)==mp.end())mp[line]=temp->data;
            
            if(temp->left)q.push({temp->left,{line-1,lvl+1}});
            if(temp->right)q.push({temp->right,{line+1,lvl+1}});
        }
        for(auto val:mp){
            ans.push_back(val.second);
        }
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        find(root,ans);
        return ans;
    }

};