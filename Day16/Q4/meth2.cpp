#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])!=mp.end())//exit n map
            {
                mp[t[i]]--;
                if(mp[t[i]]==0)mp.erase(t[i]);
            }
            else
            return false;
        }
        return  mp.size()==0;
    }
};