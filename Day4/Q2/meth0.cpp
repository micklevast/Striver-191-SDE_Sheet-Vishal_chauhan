
#define ll long long int
#include <bits/stdc++.h>
using namespace std;
// O(N^3)  & O(N)
class Solution {
public:
vector<vector<ll>> fourSum(vector<ll> &nums, ll target)
{
    set<vector<ll>> ans;
    ll n = nums.size();
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[nums[i]] = i;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            for (ll k = j + 1; k < n; k++)
            {
                ll sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                ll r = target - sum;
                if (mp.find(r) != mp.end())
                {
                    auto ptr = mp.find(r);
                    cout << "founded val:" << ptr->first << endl;
                    if (ptr->second != i && ptr->second != j && ptr->second != k)
                    {
                        vector<ll> temp{nums[i], nums[j], nums[k], nums[ptr->second]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<ll>> vec_ans;
    for (auto val : ans)
    {
        vec_ans.push_back(val);
    }
    return vec_ans;
}
};