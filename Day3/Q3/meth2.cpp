#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ans)cnt++;
            else{
                cnt--;
                if(cnt==0){
                    ans=nums[i];
                    cnt=1;
                }
            }
        }

        // checking if there is actual majority ele present or not
        if(cnt>0){ // that is here can be possible majority but not 100 percent
            int count=0;
            for(auto val:nums){
                if(val==ans)count++;
            }
            if(count>(nums.size()/2))return ans;
        }
        return -1;
    }
};