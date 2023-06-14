
#include <climits>

class Solution {
public:
    int findMinCoins(int coins[], int M, int V) {
        if (V <= 0)
            return 0;

        int minCoins = INT_MAX;

        for (int i = 0; i < M; i++) {
            if (coins[i] <= V) {
                int subproblem = findMinCoins(coins, M, V - coins[i]);
                if (subproblem != INT_MAX)
                    minCoins = std::min(minCoins, subproblem + 1);
            }
        }

        return minCoins;
    }

    int minCoins(int coins[], int M, int V) {
        int result = findMinCoins(coins, M, V);
        return (result == INT_MAX) ? -1 : result;
    }
};