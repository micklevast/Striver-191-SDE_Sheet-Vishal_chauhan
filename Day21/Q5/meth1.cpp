#include <stack>
#include <unordered_set>

class GetSmall {
public:
    stack<TreeNode*> st;
    GetSmall(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* nd = st.top();
        st.pop();
        if (nd->right) {
            TreeNode* node = nd->right;
            pushAll(node);
        }
        return nd->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};

class GetLarge {
public:
    stack<TreeNode*> st;
    GetLarge(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* nd = st.top();
        st.pop();
        if (nd->left) {
            TreeNode* node = nd->left;
            pushAll(node);
        }
        return nd->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root || (!root->left && !root->right)) return false;
        GetSmall small(root);
        GetLarge large(root);
        int l = small.next();
        int r = large.next();
        int sum = l + r;
        while (small.hasNext() && large.hasNext()) {
            if (sum == k &&(l!=r)) {
                return true;
            } else if (sum < k) {
                l = small.next();
            } else {
                r = large.next();
            }
            sum = l + r;
        }
        return false;
    }
};