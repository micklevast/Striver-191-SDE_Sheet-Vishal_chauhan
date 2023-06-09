#include <bits/stdc++.h>
using namespace std;
// TC:O(log(n))
class Solution {
public:

    // meth2 O(log(N))
    double posPower(double x,int n){
        if(n==1)return x;
        if(n==0)return 1;
        if(n%2){
            return x*myPow(x,n/2)*myPow(x,n/2);
        }
        else{
            return myPow(x,n/2)*myPow(x,n/2);
        }
    }
   
    double myPow(double x, int n) {
        double ans=posPower(x,n);
        if(n>0)
        return ans;
        else
        return 1.0/ans;
    }
};