#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        // if(j==0)return (target==nums[0])?0:-1;
        // if(j==1)return (target==nums[0])?0:(target==nums[1])?1:-1;
        while(i<=j){
            int mid=(i+j)/2;
            cout<<"mid:"<<mid<<endl;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>= nums[0]) //left part sorted
            {
                if(target>=nums[0] && target<=nums[mid]) 
                {//if target exit in this range then only earch i the range
                j=mid-1;}
                else
                i=mid+1;
            }
            else{ //right part is sorted
                if(target>=nums[mid] && target<=nums[nums.size()-1]){
                    i=mid+1;
                }
                else
                j=mid-1;
            }   
        }
    return -1;
    }
};
