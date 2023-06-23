#include <bits/stdc++.h> 
// getting TL
class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    string findPalindrome(string s, int start, int end) {
        if (start == end)
            return s.substr(start, 1);
        
        if (s[start] == s[end] && isPalindrome(s, start + 1, end - 1))
            return s.substr(start, end - start + 1);
        
        string left = findPalindrome(s, start, end - 1);
        string right = findPalindrome(s, start + 1, end);
        
        return (left.length() > right.length()) ? left : right;
    }
    
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        
        int n = s.length();
        return findPalindrome(s, 0, n - 1);
    }
};
