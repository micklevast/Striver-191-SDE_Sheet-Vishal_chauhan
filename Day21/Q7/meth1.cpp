
#include <climits>
// #include <iostream>

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// O(n^2)
class Solution {
public:

    void findSum(TreeNode *root,int &ans){
        if(root==NULL)return;
        ans+=root->val;
        findSum(root->left,ans);
        findSum(root->right,ans);

    }

    bool checkBST(TreeNode* root, int mini, int maxi) {
        if (root == nullptr) return true;
        if (root->val >= maxi || root->val <= mini) return false;
        bool l = checkBST(root->left, mini, root->val);
        bool r = checkBST(root->right, root->val, maxi);
        return (l && r);
    }

    void inorder(TreeNode *root, int &ans) {
        if (root == nullptr) return;
        if (checkBST(root, INT_MIN, INT_MAX)) {
            int tempAns=0;
            findSum(root, tempAns);
            ans=max(ans,tempAns);
        }
        inorder(root->left, ans);
        inorder(root->right, ans);
    }

    int maxSumBST(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = INT_MIN;
        inorder(root, ans);
        return ans == INT_MIN ? 0 : ans < 0 ? 0 : ans;
    }
};
