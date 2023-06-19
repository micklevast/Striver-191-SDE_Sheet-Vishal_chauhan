#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool ifPos(vector<int> A, int mid, int k, int& ttlS,int &maxi) {
    int sc=1;
    int Asum = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]>mid)return false;
        if(A[i]+Asum> mid){
            sc++;
            Asum=A[i];
        }
        else
        Asum+=A[i];
    }
    if(sc>k)return false;
    else return true;
    
}

int Solution::books(vector<int>& A, int B) {
    if (B > A.size()) {
        // Not enough books for each student
        return -1;
    }
    
    ll l = A[0], r = 0;
    for (auto val : A) {
        l = max(l, (ll)val);
        r += val;
    }
    
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int ttlS = 0;
        if (ifPos(A, mid, B, ttlS,ans)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return ans;
}
