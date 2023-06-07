#include<bits/stdc++.h>
using namespace std;

// here i have used an extra space of  SC:O(1)
// TC=O(n)+O(n)+O(n)
class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void reverse(vector<int> &arr,int idx){
        int i=idx;
        int j=arr.size()-1;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        // finding the first position which is statifying the condition nums[i]<nums[i+1]
        while(i>=0 && nums[i]>=nums[i+1])i--;
        if(i>=0){
            // if any nunber exit that fullfilled above case then
            // find the index j, which is nums[i]<nums[j] from the last
            int j=nums.size()-1;
            while(j>i && nums[j]<=nums[i])j--;
            // swap smallest possible number index i,j 
            swap(nums[i],nums[j]);
        }
        // reverse all value from index i,to get next smallest possible number
        reverse(nums,i+1);
    }
};