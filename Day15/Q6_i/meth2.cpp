#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Repeated String Match
        // Check if string b is a substring of the concatenated string
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();

        // Concatenate string a until its length is at least equal to string b
        string temp = a;
        int count = 1;
        while (temp.length() < m) {
            temp += a;
            count++;
        }

        // Check if string b is a substring of the concatenated string
        if (temp.find(b) != string::npos) {
            return count;
        }

        // Append one more time and check again
        temp += a;
        count++;

        if (temp.find(b) != string::npos) {
            return count;
        }

        return -1; // No match found
    }
};
