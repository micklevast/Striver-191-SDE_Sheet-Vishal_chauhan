#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int i = 0, j = 0, c = 0;
        int mid = (l1 + l2) / 2;
        int prev=0, current=0;

        while (c <= mid && i < l1 && j < l2) {
            prev = current;
            if (nums1[i] < nums2[j]) {
                current = nums1[i];
                i++;
            } else {
                current = nums2[j];
                j++;
            }
            c++;
        }

        while (c <= mid && i < l1) {
            prev = current;
            current = nums1[i];
            i++;
            c++;
        }

        while (c <= mid && j < l2) {
            prev = current;
            current = nums2[j];
            j++;
            c++;
        }

        if ((l1 + l2) % 2 == 0) {
            return (prev + current) / 2.0;
        } else {
            return current;
        }
    }
};