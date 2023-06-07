#include <bits/stdc++.h>
using namespace std;
// TC:O(N)
// SC:O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> futuremax(n,0);
        futuremax[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            futuremax[i]=max(prices[i],futuremax[i+1]);
        }
        // for(auto val:futuremax)cout<<val<<" ";cout<<endl;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max((futuremax[i]-prices[i]),ans);
        }
        return ans;
    }
};