
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
    bool find(TreeNode* root, long long int minVal, long long int maxVal) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return find(root->left, minVal, root->val) && find(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        long long int minVal = LLONG_MIN;
        long long int maxVal = LLONG_MAX;

        return find(root, minVal, maxVal);
    }
};

