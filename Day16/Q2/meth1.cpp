#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    return s.find(p)!=string::npos?1:0;
}