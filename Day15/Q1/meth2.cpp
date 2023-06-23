#include <bits/stdc++.h> 
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stringstream ss(s);
        string str;
        while(ss>>str){

            ans=str+" "+ans;
        }
        ans.erase(ans.length()-1,1);
        return ans;
    }
};