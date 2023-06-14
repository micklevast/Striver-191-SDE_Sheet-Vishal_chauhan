#include<bits/stdc++.h>
using namespace std;
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(pair<double,pair<int,int>> p1,pair<double,pair<int,int>> p2){
        return p1.first>p2.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,pair<int,int>>> items(n);
        for(auto i=0;i<n;i++){
            int val=arr[i].value;
            int wgh=arr[i].weight;
            double ratio=double(val)/double(wgh);
            items[i]={ratio,{val,wgh}};
        }
        sort(items.begin(),items.end(),cmp);
        double ans=0;
        for(auto val:items){
            if(W>val.second.second){
                W-=val.second.second;
                ans+=val.second.first;
            }
            else{
                double can=(double(W)/double(val.second.second))*val.second.first;
                ans+=can;
                break;
            }
        }
        return ans;
    }
        
};