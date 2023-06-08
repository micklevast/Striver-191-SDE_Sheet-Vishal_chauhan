#include <bits/stdc++.h>
using namespace std;

    // intusion is very simple
    // find-->a-b  (where a and b is duplicate and missing number)
    // finid a^2-b^2 
    // then find a+b using above both
    // then just add and substract a-b and a+b to get duplicate and missing number
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long sum = 0;
    long long squareSum = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];
        squareSum += (long long)A[i] * (long long)A[i];
    }

    long long totalSum = (long long)n * (n + 1) / 2;
    long long totalSquareSum = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long diffSum = totalSum - sum;
    long long diffSquareSum = totalSquareSum - squareSum;

    long long duplicateMinusMissing = diffSquareSum / diffSum;
    int duplicate = (int)((diffSum + duplicateMinusMissing) / 2);
    int missing = (int)(duplicateMinusMissing - duplicate);

    vector<int> result;
    int d=duplicate;
    int m=missing;
    for(auto val:A){
        if(val==duplicate || val==missing){
            duplicate=val;
        }
    }
    if(duplicate==d){;}
    else{
        missing=d;
    }
    result.push_back(duplicate);
    result.push_back(missing);
    return result;
}
