#include <bits/stdc++.h> 
#include <stack>
#include <vector>

std::vector<int> findNextGreaterElementCircular(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> stack;

    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];

        while (!stack.empty() && num > nums[stack.top()]) {
            result[stack.top()] = num;
            stack.pop();
        }

        if (i < n)
            stack.push(i);
    }

    return result;
}

