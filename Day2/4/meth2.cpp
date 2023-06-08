#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        int duplicate = 0;
        for(auto i= 0; i<nums.size(); ++i)
        ++m[nums[i]];
        
        for(auto i : m)
        {
            if(i.second > 1)
            {
                duplicate = i.first;
                break;
            }
        }
        return duplicate;
    }
};

// ----------5th methd will be using set


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        int duplicate = 0;
        for(auto i= 0; i<nums.size(); ++i)
        {
            if(st.find(nums[i])==st.end())st.insert(nums[i]);
            else return nums[i];
        }
        return -1;;
    }

};