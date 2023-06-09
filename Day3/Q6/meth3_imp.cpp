#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merging(vector<int> &arr,int l,int mid,int r,int &ans){
        vector<int> temp(arr.size(),-1);
        int k=l;
        for(int i=l;i<=mid;i++){
            int j=mid+1;
            while(j<=r && arr[i]>(2*(long)arr[j])){
                j++;
            }
            ans+=j-(mid+1);
        }
        int i=l, j=mid+1;

        while(i<=mid && j<=r){
            if(arr[i]>arr[j]){
                temp[k++]=arr[j++];
            }
            else{
                temp[k++]=arr[i++];
            }
        }
        while(i<=mid){
                temp[k++]=arr[i++];
        }
        while(j<=r){
            temp[k++]=arr[j++];
        }
        for(int x=l;x<=r;x++){
            arr[x]=temp[x];
        }
    }
    void mergeSort(vector<int>& arr,int l,int r,int &ans){

        if(l<r){
            int  mid = l + (r - l) / 2;
            mergeSort(arr,l,mid,ans);
            mergeSort(arr,mid+1,r,ans);
            merging(arr,l,mid,r,ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};