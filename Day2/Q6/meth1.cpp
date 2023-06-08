#include <bits/stdc++.h>
using namespace std;

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans=0;
    int j=n-1;
    while(j>0){
        int i=0;
        while(i<j){
             if(arr[i]>arr[j])ans++;
             i++;
        }
        j--;
    }
    return ans;
}