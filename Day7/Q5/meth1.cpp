#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)return n;

        int j=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                // do nothing
            }
            else{
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};