#include <bits/stdc++.h> 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort(strs.begin(),strs.end());
        // for(auto val:strs)cout<<val<<" ";
        int flag=0;
        string ans="";
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<strs.size();j++){
                if((strs[j].length()<=i && i!=j)|| (strs[0][i]!=strs[j][i])){
                    // cout<<"at i:"<<i<<" j:"<<j<<" | str:"<<strs[j].length()<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag)break;
            else ans+=strs[0][i];
        }
        return ans;
    }
};