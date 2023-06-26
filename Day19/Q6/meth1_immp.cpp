
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
    void find(Node* root) {
        if (root == NULL)
            return;

        find(root->left);
        find(root->right);

        // Swap the left and right child nodes
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    void mirror(Node* node) {
        find(node);
    }
};