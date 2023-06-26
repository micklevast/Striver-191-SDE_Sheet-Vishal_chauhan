// function Template for C++

// A binary tree node has data, pointer to left child
//    and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
public:
    // Function to convert a binary tree into its mirror tree.
    Node* find(Node* root) {
        if (root == NULL)
            return NULL;

        Node* leftSubtree = find(root->left);
        Node* rightSubtree = find(root->right);

        root->left = rightSubtree;
        root->right = leftSubtree;

        return root;
    }

    void mirror(Node* node) {
        Node *ans=find(node);
        node=ans;
    }
};
