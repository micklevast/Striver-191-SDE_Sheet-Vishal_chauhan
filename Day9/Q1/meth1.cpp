#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void find(vector<int> arr,int i,int n,vector<int> &ans,int &sum){
        if(i>=n){ans.push_back(sum);return;}

        int inc=sum+arr[i];
        find(arr,i+1,n,ans,inc);
        find(arr,i+1,n,ans,sum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int i=0;int sum=0;
        find(arr,i,N,ans,sum);
        // vector<int> out;
        // for(auto val:ans){
        //     out.push_back(val);
        // }
        return ans;
    }
};