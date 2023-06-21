#include<bits/stdc++.h>
using namespace std;
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> ans(n,-1);
    if(n==0)return ans;
    stack<int> st;
    ans[0]=-1;
    st.push(A[0]);int i=1;
    while(!st.empty() && i<n){
        while(st.size()>0 && st.top()>=A[i])st.pop();
        if(st.size()>0)ans[i]=st.top();
        else ans[i]=-1;
        st.push(A[i]);
        i++;
    }
    return ans;
}
