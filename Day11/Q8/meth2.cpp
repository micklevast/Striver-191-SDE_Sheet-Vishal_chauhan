#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// Output
// For each test case output one integer: the largest minimum distance.

    bool pos(vector<int> arr, int mid, int n, int k) {
        int cCow = 1;
        int lastPos = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] - lastPos >= mid) {
                cCow++;
                lastPos = arr[i];
                if (cCow >= k) return true;
            }
        }
        return false;
    }

    int findMaxDistance(vector<int> stall, int n, int c) {
        int l = 0;
        int h = stall[n - 1] - stall[0];  // Update the range of search
        int ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (pos(stall, mid, n, c)) {
                ans = mid;
                l = mid + 1;  // Adjust the lower bound to search for a larger distance
            } else {
                h = mid - 1;  // Adjust the upper bound to search for a smaller distance
            }
        }
        return ans;
    }

    int solve(int n, int k, vector<int>& stalls) {
        sort(stalls.begin(), stalls.end());
        return findMaxDistance(stalls, n, k);
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
        int maxDis=solve(n,c,stall);
        cout<<maxDis<<endl;
    }
}