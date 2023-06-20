#include <bits/stdc++.h> 
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.size()==0)return false;
                else{
                    if((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{') ){
                        st.pop();
                    }
                    else
                    return false;
                }
            }
        }
        return st.size()==0;
    }
};