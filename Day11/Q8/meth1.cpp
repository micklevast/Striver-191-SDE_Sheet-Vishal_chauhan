#include<bits/stdc++.h>
using namespace std;
// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// Output
// For each test case output one integer: the largest minimum distance.
bool pos(vector<int> stall,int mid,int n,int c){
    int nc=1;
    int dist=0;
    for(int i=0;i<n;i++){
        if(stall[i]>mid)return false;
        if(dist+stall[i]>mid){
            nc++;
            dist=stall[i];
        }
        else{
            dist+=stall[i];
        }
    }
    if(nc>c)return false;
    else return true;
}

int find(vector<int> stall,int n,int c){
    int l=stall[0];
    int h=stall[n-1];
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(pos(stall,mid,n,c)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    };
    return ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> stall(n);
        for(int i=0;i<n;i++){
            cin>>stall[i];
        }
        sort(stall.begin(),stall.end());
        int maxDis=find(stall,n,c);
        cout<<maxDis<<endl;
    }
}