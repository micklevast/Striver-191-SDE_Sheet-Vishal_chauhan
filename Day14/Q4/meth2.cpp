
#include<bits/stdc++.h>
// O(1)
class MinStack {
public:
    long long int mini = INT_MAX;
    stack<long long int> st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.size() == 0) {
            mini = val;
            st.push(val);
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            st.push(2 * (long long int)val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if (!st.empty()) {
            if (st.top() >= mini) {
                st.pop();
            }
            else {
                mini = 2 * mini - st.top();
                st.pop();
            }
        }
    }
    
    int top() {
        if (!st.empty()) {
            if(st.top()>=mini)return st.top();
            else return mini;
        }
        return -1;
    }
    
    int getMin() {
        return mini;
    }
};