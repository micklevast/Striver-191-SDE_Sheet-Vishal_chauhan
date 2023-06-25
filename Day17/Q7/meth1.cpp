#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void find(Node *root,vector<int> &ans){
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,int> mp;
        while(!q.empty()){
            Node *temp=q.front().first;
            int line=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            
            mp[line]=temp->data;
            if(temp->left)q.push({temp->left,{line-1,lvl+1}});
            if(temp->right)q.push({temp->right,{line+1,lvl+1}});
        }
        for(auto val:mp){
            ans.push_back(val.second);
            // cout<<val.first<<" ->"<<val.second<<" | ";
        }
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        find(root,ans);
        return ans;
    }
};