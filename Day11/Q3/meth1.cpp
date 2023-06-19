#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int>& nums, int i, int j) {
        if (i <= j) {
            int mid = i + (j - i) / 2;
            cout << "i: " << i << " j: " << j << " mid: " << mid << endl;
            if (mid - 1 >= i && nums[mid] == nums[mid - 1]) {
                int x = find(nums, i, mid - 2);
                if (x != -1)
                    return x;
                else {
                    int c = find(nums, mid + 1, j);
                    if (c != -1)
                        return c;
                }
            } else if (mid + 1 <= j && nums[mid] == nums[mid + 1]) {
                int x = find(nums, mid + 2, j);
                if (x != -1)
                    return x;
                else {
                    int c = find(nums, i, mid - 1);
                    if (c != -1)
                        return c;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }

    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size() - 1;
        return find(nums, i, n);
    }
};
