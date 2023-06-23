#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// i am geting wrong answer for some of the testcases

class Solution {
public:
    bool isMatch(string a, string b) {

        unordered_map<char, int> mp;
        for (int i = 0; i < a.length(); i++) {
            mp[a[i]]++;
        }
        // cout<<"finding:"<<a<<" and b:"<<b<<endl;
        for (int i = 0; i <= b.length(); i++) {
            if (mp.find(b[i]) != mp.end()) {
                if (mp[b[i]] <= 0) {
                    return false;
                }
                mp[b[i]]--;
            }
        }
        return true;
    }

    int repeatedStringMatch(string a, string b) {

        int hashCode = 0;

        for (int i = 0; i < a.length(); i++) {
            hashCode += (((a[i] - 'a') + 1) * 27);
        }
        cout << "code: " << hashCode << endl;

        int i = 0, j = 0;
        int calHash = 0, ans = 0;

        while (j < b.length()) {
            if (j - i + 1 < a.length()) {
                calHash += (((b[j] - 'a') + 1) * 27);
                j++;
            } else {
                calHash += (((b[j] - 'a') + 1) * 27);
                if (calHash == hashCode) {
                    if (isMatch(a, b.substr(i,j-1+1))) {
                        ans++;
                    }
                }

                // Slide
                calHash -= (((b[i] - 'a') + 1) * 27);
                i++;
                j++;
            }
        }

        return (ans > 0) ? ans : -1;
    }
};
