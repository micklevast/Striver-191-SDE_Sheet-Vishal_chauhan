#include <bits/stdc++.h>
using namespace std;

// binary search
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int l = 1;
        int h = nums.size() - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int cnt = 0;
            for (auto val : nums)
            {
                if (val <= mid)
                    cnt++;
            }
            // if cnt is less than equal to mid then there is no duplicate value present in left  side so we have to move over right side
            if (cnt <= mid)
            {
                l = mid + 1;
            }
            else
            { // as mid<cnt  therefore there will be an extra duplicate nmber will be present to the left side
                h = mid - 1;
            }
        }
        // l-->will be our duplicate number
        return l;
    }
};