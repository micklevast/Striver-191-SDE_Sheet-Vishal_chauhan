#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// here i have used an extra space of  SC:numRows*(sum of 1 to numRows)=n*n
// TC=SC



// void printVector(const vector<int>& vec) {
//     for (int num : vec) {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// void findPermutations(int n) {
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         nums[i] = i + 1;
//     }

//     do {
//         printVector(nums);
//     } while (next_permutation(nums.begin(), nums.end()));

//     // The next_permutation function is a part of the <algorithm> library in C++. It rearranges the elements in the range [first, last)
//     //  into the next lexicographically greater permutation. It returns true if such a permutation exists and modifies the range accordingly.
//     //  If there are no more permutations, it returns false and leaves the range unmodified
// }

// int main() {
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;

//     findPermutations(n);

//     return 0;
// }
// --------------------------------
// /* taking reference of above we can simply get the answer*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (next_permutation(nums.begin(), nums.end())) {
            return;
        } else {
            // If no next permutation exists, revert to the first permutation
            sort(nums.begin(), nums.end());
            return;
        }
    }
};
