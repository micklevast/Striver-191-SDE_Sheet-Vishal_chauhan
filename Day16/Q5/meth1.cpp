#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string cas(int n){
        if(n==1)return "1";

        string sub=cas(n-1);

        char counting=sub[0];
        int c=1;
        string ans="";
        for(int i=1;i<sub.length();i++){
            if(sub[i]==counting){
                c++;
            }
            else{
                ans+=(to_string(c)+counting);
                counting=sub[i];
                c=1;
            }
        }
        ans+=(to_string(c)+counting);
        return ans;
    }
    string countAndSay(int n) {
        if(n==1)return "1";

        string ans=cas(n);
        return ans;
    }
};