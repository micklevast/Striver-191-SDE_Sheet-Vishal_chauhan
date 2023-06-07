#include <bits/stdc++.h>
using namespace std;
// TC:O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=INT_MIN;
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxi<prices[i]){
                maxi=prices[i];
            }
            else{
                ans=max(ans,maxi-prices[i]);
            }
        }
        return ans==INT_MIN? 0: ans;
    }
};