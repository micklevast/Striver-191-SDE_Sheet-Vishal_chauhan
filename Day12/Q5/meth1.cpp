// space complexity (SC) of the code is O(K),
// The time complexity (TC) of the code is O(N log K), where N is the total number of elements across all arrays and K is the number of arrays.
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<k;i++){
     pq.push({kArrays[i][0],{0,i}}); //{node,(index and whicharray)}
   
    }
    vector<int> ans;
    while(!pq.empty()){
        int nd=pq.top().first;
        int idx=pq.top().second.first;
        int carray=pq.top().second.second;
        pq.pop();
        if(idx+1<kArrays[carray].size()){
            pq.push({kArrays[carray][idx+1],{idx+1,carray}});

        }
        ans.push_back(nd);
    }
    return ans;
    
}
