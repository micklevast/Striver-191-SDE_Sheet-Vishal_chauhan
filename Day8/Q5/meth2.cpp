#include <vector>
#include <climits>

class Solution {
public:
    int minCoins(int coins[], int M, int V) {
        std::vector<int> dp(V + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < M; j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return (dp[V] == INT_MAX) ? -1 : dp[V];
    }
};
