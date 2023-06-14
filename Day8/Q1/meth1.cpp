
// Define a comparison function comp that compares two pairs (start, end) based on their end times (second element of the pair). The function ensures that if the end times are different, the pair with the smaller end time comes first. If the end times are the same, it compares the start times (first element of the pair) and ensures the pair with the smaller start time comes first.

// Create a vector of pairs vec to store the start and end times of the meetings. Iterate through the given start and end arrays and populate vec with pairs (start[i], end[i]).

// Sort the vec vector using the sort function, passing the comp comparison function as the third argument. This will sort the meetings based on their end times in ascending order.

// Initialize a variable last with the end time of the first meeting in the sorted vector vec. Initialize a variable ans with a value of 1, representing the first meeting.

// Iterate through the sorted vec vector starting from the second meeting. For each meeting, check if its start time is greater than the last (end time of the previous meeting). If it is, update the last with the end time of the current meeting and increment the ans by 1.

// After iterating through all the meetings, return the final value of ans, which represents the maximum number of non-overlapping meetings that can be scheduled.

// The time complexity of this code is dominated by the sorting operation, which has a complexity of O(n log n), where n is the number of meetings. The rest of the operations, such as creating the vector and iterating through it, have a linear time complexity of O(n). Therefore, the overall time complexity of this code is O(n log n).

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