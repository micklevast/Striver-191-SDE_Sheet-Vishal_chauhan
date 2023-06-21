#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findL(vector<int> &NearestLeftMinI,vector<int>& heights){
        stack<int> st;
        int n=heights.size();
        st.push(0);
        NearestLeftMinI[0]=-1;
        int i=1;
        while(!st.empty() && i<n){
            while(st.size()>0 && heights[st.top()]>=heights[i])st.pop();
            if(st.size()>0)NearestLeftMinI[i]=st.top();
            else NearestLeftMinI[i]=-1;
            st.push(i); 
            i++;

        }
    }
    void findR(vector<int> &NearestRightminI,vector<int>& heights){
        stack<int> st;
        int n=heights.size();
        st.push(n-1);
        NearestRightminI[n-1]=n;
        int i=n-2;
        while(!st.empty() && i>=0){
            while(st.size()>0 && heights[st.top()]>=heights[i])st.pop();
            if(st.size()>0)NearestRightminI[i]=st.top();
            else NearestRightminI[i]=n;
            st.push(i); 
            i--;

        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> NearestLeftMinI(n,-1),NearestRightminI(n,-1);
        findL(NearestLeftMinI,heights);
        findR(NearestRightminI,heights);
    // for(auto val:NearestLeftMinI)cout<<val<<" ";cout<<endl;
    //  for(auto val:NearestRightminI)cout<<val<<" ";cout<<endl;
     int ans=0;

     for(int i=0;i<n;i++){
         int cal=(heights[i]*(abs(NearestRightminI[i]-NearestLeftMinI[i])-1));
         if(cal>ans)ans=cal;
     }

     return ans;

    }
};