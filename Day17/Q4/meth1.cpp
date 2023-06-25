#include<bits/stdc++.h>
using namespace std;#include <iostream>
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void morris(TreeNode* root, vector<int>& ans) {
        while (root) {
            if (root->left == nullptr) {
                ans.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        morris(root, ans);
        return ans;
    }
};

// int main() {
//     TreeNode* root = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->right->left = new TreeNode(3);

//     Solution solution;
//     vector<int> result = solution.inorderTraversal(root);

//     cout << "Inorder Traversal: ";
//     for (int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }
