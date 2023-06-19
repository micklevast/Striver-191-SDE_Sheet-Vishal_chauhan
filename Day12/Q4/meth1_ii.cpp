#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    vector<int> pq;
    int c;
    MedianFinder() {
        c=0;
    }
    
    void addNum(int num) {
        pq.push_back(num);
        c++;
    }
    
    double findMedian() {
        sort(pq.begin(),pq.end());
        if(c%2==0){
            return (pq[(c/2)-1]+pq[(c/2)])/2.0;
        }
        else return pq[(c/2)];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */