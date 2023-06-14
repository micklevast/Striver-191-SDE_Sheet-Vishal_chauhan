#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        right[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(h[i],right[i+1]);
        }
        left[0]=h[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],h[i]);
        }
        int ans=0;

        for(int i=0;i<n;i++){
                int minn=min(right[i],left[i]);
                ans+=(minn-h[i]);
        }
        return ans;
    }
};