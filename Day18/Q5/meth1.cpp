#include <bits/stdc++.h> 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(vector<int> &ans, TreeNode *root, TreeNode *nd) {
        if (root == NULL || nd == NULL)
            return false;
        if (root->val == nd->val) {
            ans.push_back(root->val);
            return true;
        }

        bool l = find(ans, root->left, nd);
        bool r = find(ans, root->right, nd);
        if (l || r) {
            ans.push_back(root->val);
            return true;
        } else
            return false;
    }

    vector<int> r2nPath(TreeNode *root, TreeNode *nd) {
        vector<int> ans;
        bool status = find(ans, root, nd);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<int> p1 = r2nPath(root, p);
        vector<int> p2 = r2nPath(root, q);
        for(auto val:p1)cout<<val<<" ";cout<<endl;
        for(auto val:p2)cout<<val<<" ";cout<<endl;
        int i = 0, j = 0;
        int ans = p1[0];
        int l = min(p1.size(), p2.size());
        while (i < p1.size() && j < p2.size() && i < l && j < l && p1[i]==p2[j]) {
            ans=p1[i];
            i++;
            j++;
        }
    
        // Find the lowest common ancestor node in the tree based on the value
        TreeNode *lca = findNode(root, ans);
        return lca;
    }
    
    TreeNode* findNode(TreeNode* root, int val) {
        if (root == NULL || root->val == val)
            return root;
        TreeNode *left = findNode(root->left, val);
        TreeNode *right = findNode(root->right, val);
        return left ? left : right;
    }
};
