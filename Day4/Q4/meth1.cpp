#include <bits/stdc++.h>
using namespace std;
// i am getting wrong answer using this -->tryin to improving this
class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        int ans = 0;
        int target = 5; // Update the target value to 5
        int sum = 0;
        int i = 0;
        int j = 0;
        while (i < n) {
            sum += A[i++];
            if (sum < target) {
                // Move i forward
                // Uncomment the line below
                // i++;
            } else if (sum > target) {
                // Move j forward and subtract A[j] from sum
                // Uncomment the line below
                sum -= A[j++];
            } else {
                // Found a subarray with sum equal to target
                ans = max(ans, i - j);
                // Move j forward and subtract A[j] from sum
                // Uncomment the line below
                sum -= A[j++];
            }
        }
        return ans;
    }
};
