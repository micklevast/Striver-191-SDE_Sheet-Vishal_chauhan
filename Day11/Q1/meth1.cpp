#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

long long int power(long long int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent % 2 == 0) {
        long long int temp = power(base, exponent / 2);
        return temp * temp;
    } else {
        return base * power(base, exponent - 1);
    }
}
// n*log(m*10^precision)
int find(int n, int m) {
    int l = 1, r = m;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (pow(mid,n) < 1e-9 || pow(mid,n) ==m) {
            return mid;
        } else if (pow(mid,n) < m) {
            l = mid+1 ;
        } else {
            r = mid-1 ;
        }
    }
    return -1;
}

int NthRoot(int n, int m) {
    int a = find(n, m);
    long long int p = power(a, n);
    return (abs(p - m) < 1e-9) ? a : -1;
}