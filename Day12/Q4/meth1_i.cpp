#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> pq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        int size=pq.size();
        int p=(size-1)/2;
        priority_queue<int> q=pq;;
        while(p--){
            q.pop();
        }
        if(size%2==0){
            int f=q.top();q.pop();
            int s=q.top();
            return ((double)f+(double)s)/2.0;
        }

        return q.top();
    }
};