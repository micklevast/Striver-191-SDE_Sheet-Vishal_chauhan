#include <iostream>
#include <cmath>
// helper to find the duplicate number ---------to find the first set bit in number----------
// int findFirstSetBit1(int num) {
//     if (num == 0) {
//         return -1;
//     } else {
//         int position = log2(num ^ (num & (num - 1))) + 1;
//         return position;
//     }
// }


// int findFirstSetBit2(int num) {
//     if (num == 0) {
//         return -1;
//     } else {
//         int position = log2(num & (-num)) + 1;
//         return position;
//     }
// }



// int main() {
//     int number = 18;
//     int firstSetBit = findFirstSetBit1(number);
//     int firstSetBit2 = findFirstSetBit2(number);

//     std::cout << "Number: " << number << std::endl;
//     std::cout << "Position of the first set bit: " << firstSetBit << std::endl;
//     std::cout << "Position of the first set bit: " << firstSetBit2 << std::endl;
//     return 0;
// }

// --------first brute force------------

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ind = 0;
		
		// sort the vector
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
			// if two consecutive elements are equal
			// you have find a duplicate
			// break the loop
            if(nums[i] == nums[i+1])
            {
                ind = nums[i];
                break;
            }
        }
        // return duplicate value
        return ind;
    }

};

// --------2nd brute force------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		// initialise cnt vector of size nums with 0
        vector<int> cnt(nums.size(),0);
        int ind =  0;
		
		// store the cnt of each value in the cnt vector
        for(int i = 0; i<nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        
        for(int i = 0; i<cnt.size(); i++)
        {
            if(cnt[i] > 1)
            {
                ind  = i;
                break;
            }
        }
        
        return ind;
    }
};