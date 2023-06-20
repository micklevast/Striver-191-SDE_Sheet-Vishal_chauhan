#include <bits/stdc++.h> 
class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> s;
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        int ans=s.top();
        s.pop();
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return ans;

    }
    
    int peek() {
        stack<int> s=st;
        int size=st.size();size--;
        while(!st.empty() && size>0){
            st.pop();
            size--;
        }
        int ans=st.top();
        st=s;
        return ans;       
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */