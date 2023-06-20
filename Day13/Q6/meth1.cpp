#include <bits/stdc++.h> 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(auto val:nums1){
            int i=0;
            while(i<nums2.size()){
                if(nums2[i]==val){
                    i++;
                    // try to find next greater ele if possible
                    if(i>=nums2.size())ans.push_back(-1);
                    else
                    {
                        int flag=0;
                        while(i<nums2.size()){
                            if(nums2[i]>val){
                                flag++;
                                ans.push_back(nums2[i]);
                                break;
                            }
                            i++;
                        }
                        if(flag==0)ans.push_back(-1);
                    }
                }
                i++;
            }
        }
        return ans;
    }
};