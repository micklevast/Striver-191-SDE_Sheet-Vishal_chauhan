#include<bits/stdc++.h>
using namespace std;
// log(n)
class Solution {
public:
int findd(vector<int> nums, int l, int r) {
    if (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return mid;
        } else {
            int temp = 0;
            if(mid-2>=0)
            temp=findd(nums, l, mid - 1);
            if (temp != 0) {
                return temp;
            } else {
                return findd(nums, mid + 1, r);
            }
        }
    }
    return 0;
}

int singleNonDuplicate(vector<int>& nums) {
    if(nums.size()==1)return nums[0];
        int low = 0;
        int high = nums.size()-1;
        
        if (nums[0]!= nums[1]) return nums[0];
 
        if (nums[high]!= nums[high- 1]) return nums[high];
    return nums[findd(nums, 0, nums.size() - 1)];
}

};