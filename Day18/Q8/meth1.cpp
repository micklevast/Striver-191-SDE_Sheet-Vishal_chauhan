#include <bits/stdc++.h> 
#include <bits/stdc++.h>

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool leaf(TreeNode<int>* root) {

    if (root && root->left == NULL && root->right == NULL)
        return true;
    else
        return false;
}

void left(TreeNode<int>* root, std::vector<int>& ans) {
    if(root)
    root=root->left;
    while (root && !leaf(root)) {
        ans.push_back(root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}

void allLeaf(TreeNode<int>* root, std::vector<int>& ans) {
    if (root == NULL)
        return;
    if (leaf(root))
        ans.push_back(root->data);
    allLeaf(root->left, ans);
    allLeaf(root->right, ans);
}

void right(TreeNode<int>* root, std::vector<int>& ans) {
    stack<int> st;
    if(root)root=root->right;
    while (root && !leaf(root)) {
        st.push(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

std::vector<int> traverseBoundary(TreeNode<int>* root) {
    std::vector<int> ans;
    if(root && !leaf(root)){
        ans.push_back(root->data);
    }

    left(root, ans);
    allLeaf(root, ans);
    right(root, ans);
    return ans;
}
