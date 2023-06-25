#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<pair<TreeNode*, long long>> q;
        long long ans = 0;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long l = q.front().second;
            long long r = l;
            long long sub = q.front().second * 2 + 1;

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front().first;
                long long cnt = q.front().second;
                q.pop();

                if (i == size - 1) {
                    r = cnt;
                }

                if (temp->left) {
                    q.push({temp->left, cnt * 2 + 1 - sub});
                }

                if (temp->right) {
                    q.push({temp->right, cnt * 2 + 2 - sub});
                }
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};