#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> st,s;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(s.empty() || val<=s.top()){
            s.push(val);
        }

    }

    
    void pop() {
        if(st.size()>0)
        {
            if( st.top()==s.top()){
            st.pop();
            s.pop();
            }
            else{
                st.pop();
            }
        }
        else return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if (s.empty()) {
            return -1; // or any other value to indicate an empty stack
        }
        return s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */