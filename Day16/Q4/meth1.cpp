#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        vector<int> a(27,0);
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(int i=0;i<27;i++){
            if(a[i]!=0)return false;
        }
        return true;
    }
};