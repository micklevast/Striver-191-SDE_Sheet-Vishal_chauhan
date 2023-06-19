#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    priority_queue<int ,vector<int> ,greater<int>> pq; //min heap
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            if(pq.size()<C){
                pq.push(A[i]+B[j]);
            }
            else{
                if(pq.top()<(A[i]+B[j])){
                    pq.pop();
                    pq.push(A[i]+B[j]);
                }
                else break;
            }
        }
    }
    vector<int> ans;
    while(pq.size()!=0){
        ans.push_back(pq.top());pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

