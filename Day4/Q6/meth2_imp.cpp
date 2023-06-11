
#include <bits/stdc++.h>
using namespace std;

// TC=O(N)  and SC=O(N)
// intuinsion is very simmple just inisert into set until gotted uniquechar ,once repeating char then try to
//  removed char from left side(from i) of string until got unique char to j
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0;
        int len = s.length();
        int ans = 0;
        unordered_set<char> st;

        while (j < len)
        {
            if (st.count(s[j]) > 0)
            {
                st.erase(s[i++]);
            }
            else
            {
                st.insert(s[j++]);
                ans = max(ans, j - i);
            }
        }

        return ans;
    }
};
