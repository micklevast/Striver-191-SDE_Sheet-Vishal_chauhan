#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
        if (root == nullptr) {
            return true;
        }

        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
            return false;
        }

        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};