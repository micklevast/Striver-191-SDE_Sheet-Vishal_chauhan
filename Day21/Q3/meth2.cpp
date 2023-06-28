
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void find(TreeNode *root,int& k,int& i,int &ans){
        if(root==NULL)return ;
        find(root->left,k,i,ans);
        i++;
        if(i==k){ans=root->val;return;}
        find(root->right,k,i,ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans=-1;
        find(root,k,i,ans);
        return ans;
    }
};