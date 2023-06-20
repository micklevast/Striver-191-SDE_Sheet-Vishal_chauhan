#include <bits/stdc++.h> 
class MyStack {
public:
queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> tq;
        while(!q.empty()){
            tq.push(q.front());
            q.pop();
        }
        int s=tq.size();
        s--;
        while(s-- && tq.size()>0){
            q.push(tq.front());
            tq.pop();
        }
        return tq.front();
    }
    
    int top() {
        queue<int> tq=q;
        int s=q.size();s--;
        while(s>0 && !q.empty()){
            cout<<"ele:"<<q.front()<<" ";
            q.pop();
            s--;
        }
        cout<<endl;
        int ans=q.front();
        q=tq;
        return ans;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */