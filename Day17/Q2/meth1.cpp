#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string prev = countAndSay(n - 1);
        string ans = "";
        
        int count = 1;
        char curr = prev[0];
        
        for (int i = 1; i < prev.length(); i++) {
            if (prev[i] == curr) {
                count++;
            } else {
                ans += to_string(count) + curr;
                count = 1;
                curr = prev[i];
            }
        }
        
        ans += to_string(count) + curr;
        
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 5;
    string result = sol.countAndSay(n);
    cout << "Count and Say sequence for n = " << n << ": " << result << endl;
    
    return 0;
}
