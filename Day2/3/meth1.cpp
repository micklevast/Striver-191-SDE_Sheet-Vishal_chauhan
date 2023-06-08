class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        int a=intervals[0][0],b=intervals[0][1];
        int i=0;
        for(auto vec:intervals){
            if(i==0){
                i++;
                continue;
            }
            int x=vec[0],y=vec[1];
            if(b>=x){
                // merging
                b=max(y,b);
            }
            else{
                // getting new interval
                ans.push_back({a,b});
                a=x,b=y;
            }
        }
        ans.push_back({a,b});
        return ans;
    }
};