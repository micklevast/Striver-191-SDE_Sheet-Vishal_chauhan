#include <bits/stdc++.h>
using namespace std;

// TC=O(N)  and SC=O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        unordered_map<char,int> mp;
        int ans=0;
        for(int i=0;i<len;){
            mp[s[i]]++;
            int j=i+1;
            while(j<len && mp.find(s[j])==mp.end()){
                mp[s[j]]++;
                j++;
            }
            ans=max(ans,j-i);
            // cout<<" at:"<<i<<" ans:"<<ans<<endl;
            i++;
            mp.clear();
        }
        return ans;
    }
};