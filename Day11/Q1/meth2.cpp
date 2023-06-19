#include <iostream>
#include <vector>
#include <string>

#include<bits/stdc++.h>
using namespace std;

double mul(int n,double mid){
    double ans=1.0;
    while(n--){
        ans*=mid;
    }
    return ans;
}

double NthRoot(int n, int m) {
    double l=1,h=m;
    double pres=1e-6;
    while(h-l>1e-6){
        double mid=(l+h)/2.0;
        // cout<<"mid:"<<mid<<endl;
        if(mul(n,mid)<m){
            l=mid;
        }
        else{
            h=mid;
        }
    }
    return l;
}

int main(){
    cout<<NthRoot(5,16);
}