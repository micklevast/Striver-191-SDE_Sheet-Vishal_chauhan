#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

class StockSpanner {
public:
    stack<int> st;
    StockSpanner() {
        
    }
    void find(int p,int &ans){
        if(st.empty() || p<st.top() )return;
        int tp=st.top();
        st.pop();
        ans++;
        find(p,ans);
        st.push(tp);
    }
    int next(int price) {
        st.push(price);
        int ans=0;
        find(price,ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */