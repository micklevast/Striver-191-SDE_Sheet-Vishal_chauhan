#include <bits/stdc++.h> 
class Solution {
public:
    bool isNum(char c){
        
        if((c-'0')>=0 && (c-'0')<=9)return true;
        else return false;
    }
    int myAtoi(string s) {
        int sign=1;

        long long int ans=0;
        int i=0;
        while(s[i]==' ')i++;
        if(s[i]=='-' )i++,sign=-1;
        else if(s[i]=='+')i++;

        // cout<<"i:"<<i<<" char:"<<s[i]<<endl;
        int flag=1;
        // ans=sign*ans;
        while(i<s.length() && isNum(s[i])){
            if(ans>INT_MAX ){
                if(sign>0)return INT_MAX;
                else return INT_MIN;
            }
            int val=(s[i]-'0');

            ans=ans*10+val;
            // cout<<" at:"<<i<<"  ans:"<<ans<<endl;
            i++;
        }
        if(sign<0){
            ans=-1*ans;
            if(ans<INT_MIN)return INT_MIN;
            return ans;
        }
        else{
            if(ans>INT_MAX)return INT_MAX;
            return ans;
        }
    }
};