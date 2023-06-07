#include <bits/stdc++.h>
using namespace std;
// TC:O(N)
class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(j<=k){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;j++;
            }
            else if(nums[j]==1){
               j++;
            }
            else{
                swap(nums[j],nums[k]);
                k--;
            }
        }
    }
};