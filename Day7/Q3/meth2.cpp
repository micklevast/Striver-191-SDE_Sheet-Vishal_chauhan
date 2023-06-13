#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n < 3 || nums[0] > 0)
            return ans;
        
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            int s=nums[i];
            while(j<k){
                s+=nums[j]+nums[k];
                // cout<<"at: i"<<i<<" j:"<<j<<" k:"<<k<<" sum:"<<s<<endl;
                if(s==0){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                else if(s>0)k--;
                else j++;
                s=nums[i];
            }
        }
        for(auto val:st){
            ans.push_back(val);
        }
        return ans;
        
    }
};