#include <bits/stdc++.h> 
class Solution {
public:
    bool isPal(string s){
        int i=0;int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    void find(string s,string &ans,int i,int j){
        if(i<0 || j>=s.length() || i>j)return;
        if(s[i]==s[j]){
            string str=s.substr(i,j-i+1);
            // cout<<"str:"<<str<<" | ";
            if(isPal(str)){
                if(ans.length()<str.length())
                ans=str;
            }
            find(s,ans,i,j-1);
            find(s,ans,i+1,j);
        }
        else{
            string str=s.substr(i,j-i+1);
            // cout<<"str:"<<str<<" || ";
            find(s,ans,i,j-1);
            find(s,ans,i+1,j);
        }

    }
    string longestPalindrome(string s) {
        int i=0;
        int l=s.length();
        string ans="";
        find(s,ans,i,l-1);
        return ans;
    }
};