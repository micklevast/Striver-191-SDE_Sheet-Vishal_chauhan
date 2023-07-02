
#include <bits/stdc++.h> 
using namespace std;
class Kthlargest {
public:
    // priority_queue<int> pq;//max heap
    priority_queue<int,vector<int>,greater<int>> pq;
    int kk;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       kk=k;
       for(auto val:arr){
           if(pq.size()<kk){
               pq.push(val);
           }
           else{
               if(pq.top()<val){
                   pq.pop();
                   pq.push(val);
               }
           }
       }
    }

    void add(int num) {
        // Write your code here.
        if(pq.size()<kk){
            pq.push(num);
        }
        else{
            if(pq.top()<num){
                pq.pop();
                pq.push(num);
            }
        }
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top();
    }

};