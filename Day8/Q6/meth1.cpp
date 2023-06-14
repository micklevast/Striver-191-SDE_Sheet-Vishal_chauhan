
#include <vector>
#include <algorithm>

class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        if(p1.second!=p2.second)return p1.second<p2.second;
        else return p1.second < p2.second;
    }
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({start[i],end[i]});
        }
        sort(vec.begin(),vec.end(),comp);
        // for(auto val:vec)cout<<val.first<<" ";cout<<endl;
        // for(auto val:vec)cout<<val.second<<" ";cout<<endl;
        int last=vec[0].second;int ans=1;
        for(int i=1;i<n;i++){
            if(last<vec[i].first){
                last=vec[i].second;
                ans++;
            }
        }
        return ans;
    }
};