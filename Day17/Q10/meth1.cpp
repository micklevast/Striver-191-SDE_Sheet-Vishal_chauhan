#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
                // map<int,map<int,multiset<int>>> mp;
        // queue<pair<TreeNode*,pair<int,int>>> q;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp;
        while(!q.empty()){
            TreeNode *temp=q.front().first;
            int line=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            mp[line][lvl].insert(temp->val);

            if(temp->left){
                q.push({temp->left,{line-1,lvl+1}});
            }
            if(temp->right){
                q.push({temp->right,{line+1,lvl+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto line:mp){
            vector<int> temp;
            for(auto lvl:line.second){
                for(auto val:lvl.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};