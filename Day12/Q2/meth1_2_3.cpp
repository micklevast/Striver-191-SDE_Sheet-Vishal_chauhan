#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// O(nlog(n)) and SC:O(K)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;//min heap
        for(auto val:nums){
            if(pq.size()<k)
            pq.push(val);
            else{
                if(pq.top()<val){
                    pq.pop();
                    pq.push(val);
                }
            }
        }
        return pq.top();
    }
};
// -->Onlog(n)  and O(1)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         return nums[nums.size()-k];
//     }
// };

// -->// O(nlog(n)) and SC:O(n)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq(nums.begin(),nums.end()); //max heap
//         while(k!=1)
//         {
//             int y=pq.top();
//             pq.pop();
//             k--;
//         }
//         return pq.top();
//     }
//     };