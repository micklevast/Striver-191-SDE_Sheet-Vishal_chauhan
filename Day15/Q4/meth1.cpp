#include <bits/stdc++.h> 
class Solution {
public:
    int romanToInt(string s) {
        int i=0;int j=s.length()-1;
        unordered_map<char,int> mp;
        mp['I']=1,mp['V']=5,mp['X']=10,mp['L']=50,mp['C']=100,mp['D']=500,mp['M']=1000;
        int ans=0;
        while(j>=0){
            int l=1;
            char c=s[j];
            while(j-1>=0 && s[j]==s[j-1]){
                l++;
                j--;
            }
            if(l>1){
                if(c=='I') //1
                {
                    ans+=(l*1);
                }
                else if(c=='X') //10
                {
                    ans+=(l*10);
                }
                else if(c=='C') //100
                {
                    ans+=(l*100);
                }
                else if(c=='M') //1000
                {
                    ans+=(l*1000);
                }
                j--;
            }
            else{

                if(j-1>=0 && c=='V' && s[j-1]=='I')ans+=4,j--;
                else if(j-1>=0 && c=='X' && s[j-1]=='I')ans+=9,j--;
                else if(j-1>=0 && c=='L' && s[j-1]=='X')ans+=(40),j--;
                else if(j-1>=0 && c=='C' && s[j-1]=='X')ans+=(90),j--;
                else if(j-1>=0 && c=='D' && s[j-1]=='C')ans+=(400),j--;
                else if(j-1>=0 && c=='M' && s[j-1]=='C')ans+=(900),j--;
                else{

                    ans+=mp[c];
                }
                j--;
            }
            // cout<<"ans:"<<ans<<"  j:"<<j<<endl;
        }
        return ans;
    }
};