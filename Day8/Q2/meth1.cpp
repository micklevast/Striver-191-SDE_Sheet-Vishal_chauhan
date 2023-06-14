
#include <vector>
#include <algorithm>

class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        std::sort(arr, arr + n);
        std::sort(dep, dep + n);
        int ans = 1;
        
        int maxi = 1;
        int i = 1;
        int j = 0;
        while (i < n && j < n) {
            if (arr[i]<=dep[j]) {
                i++;
                ans++;
            } else {
                j++;
                ans--;
            }
            maxi = std::max(maxi, ans);
        }
        return std::max(maxi, ans);
    }
};