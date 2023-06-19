#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0;int c=0;
        int ans=0;
        while(c<k && i<n && j<m){
            if(arr1[i]<arr2[j]){
                ans=arr1[i];
                i++;
                c++;
            }
            else //if(arr1[i]>arr2[j])
            {
                ans=arr2[j];
                j++;
                c++;
            }
        }
        while(c<k && i<n){
            ans=arr1[i++];
            c++;
        }
        while(c<k && j<m){
            ans=arr2[j++];
            c++;
        }
        return ans;
    }
};