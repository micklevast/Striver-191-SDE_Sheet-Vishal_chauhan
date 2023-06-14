#include<bits/stdc++.h>
using namespace std;

bool comp(Job j1,Job j2){
    if(j1.profit==j2.profit)return j1.dead>j2.dead;
    return j1.profit>j2.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int maxDead=INT_MIN;
        for(int i=0;i<n;i++){
            // cout<<arr[i].id<<" :"<<arr[i].dead<<": "<<arr[i].profit<<endl;
            maxDead=max(maxDead,arr[i].dead);
        }
        // cout<<"maxDead:"<<maxDead<<endl;
        vector<int> visited(maxDead+1,0);
        int ans=0;
        int ttlDone=0;
        for(int i=0;i<n;i++){
            int j=arr[i].dead;
            // if(visited[j])continue;
            int jobNo=arr[i].id;
            // cout<<"job:"<<jobNo<<" | ";
            while(j>=1){
                if(!visited[j]){
                    visited[j]=jobNo;
                    ans+=arr[i].profit;
                    // cout<<"selected:"<<arr[i].profit<<" | ";
                    ttlDone++;
                    break;
                }
                j--;
            }
        }
        // for(auto val:visited)cout<<val<<" ";cout<<endl;
        return {ttlDone,ans};
    } 
};