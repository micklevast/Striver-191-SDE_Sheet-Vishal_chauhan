
class Solution {
public:
    int ans = -1;

    void find(Node* root, int k, int& i) {
        if (root == nullptr)
            return;

        find(root->right, k, i);

        i++;
        if (k == i) {
            ans = root->data;
            return;
        }

        find(root->left, k, i);
    }

    int kthLargest(Node* root, int K) {
        int i = 0;
        find(root, K, i);
        return ans;
    }
};
