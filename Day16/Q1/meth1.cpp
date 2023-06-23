#include<iostream>
#include<bits/stdc++.h>
// not getting correct answer!
using namespace std;

bool match(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int zAlgorithm(string s, string p, int n, int m) {
    unordered_map<char, int> mp;
    for (int i = 0; i < p.length(); i++) {
        mp[p[i]]++;
    }
    int i = 0;
    int j = 0;
    int c = mp.size();
    int k = p.length();
    int ans = 0;
    while (j < s.length()) {
        if (j - i + 1 < k) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    c--;
                    mp.erase(s[j]);
                }
            }
            j++;
        }
        else {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    c--;
                    mp.erase(s[j]);
                }
            }
            // calculate ans
            if (c == 0 && match(p, s.substr(i, k))) {
                ans++;
            }

            // slide the window
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
            }
            else {
                mp[s[i]]++;
                c++;
            }
            i++;
            j++;
        }
    }
    return ans;
}
