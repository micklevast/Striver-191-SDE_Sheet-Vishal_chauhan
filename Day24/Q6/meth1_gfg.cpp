#include<bits/stdc++.h>
using namespace std;
/*Complete the functions below*/
int find(int A[], int X) {
    if (A[X] == X)
        return X;
    
    return A[X] = find(A, A[X]);
}

void unionSet(int A[], int X, int Z) {
    int parx = find(A, X);
    int parz = find(A, Z);
    // here A act as containg the Parent vector
    if (parx != parz)
        A[parx] = parz;
}