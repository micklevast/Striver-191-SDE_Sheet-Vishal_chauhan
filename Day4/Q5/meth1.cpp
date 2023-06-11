#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <vector>
// solution is simliar to Q4 as maximum length of subarray having sum=0

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> xorFreq;  // Map to store cumulative XOR values and their frequencies
    int count = 0;  // Variable to keep track of the total count of subarrays
    
    int xorSum = 0;  // Cumulative XOR value
    
    for (int i = 0; i < A.size(); i++) {
        xorSum ^= A[i];  // Calculate the cumulative XOR value
        
        if(xorSum==B)count++;
        if(xorFreq.find(xorSum^B)!=xorFreq.end()){
            count+=xorFreq[xorSum^B];
        }
        
        
        xorFreq[xorSum]++;  // Increment the frequency of the cumulative XOR value
    }
    
    return count;
}
