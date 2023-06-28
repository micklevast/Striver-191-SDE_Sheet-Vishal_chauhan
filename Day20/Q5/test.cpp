#include<iostream>
using namespace std;
int main()
{
    // In C++, the logical AND operator returns true if both operands are non-zero, and false if at least one operand is zero.
    cout<< (9 && -5)<<endl;
    cout<< (9 && 5)<<endl;
    cout<< (-9 && -5)<<endl;
    cout<< (0 && -5)<<endl;

// To summarize:
// (9 || -5), (9 || 5), and (-9 || -5) all evaluate to true (1).
// (0 || -5) evaluates to true (1).
// In C++, the logical OR operator returns true if at least one operand is non-zero, and false if both operands are zero.

}