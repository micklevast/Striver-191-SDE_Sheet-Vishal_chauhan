
#include <bits/stdc++.h>

// bool knows(int A, int B);

int findCelebrity(int n) {
    int c = 0;
    for (int i = 1; i < n; i++) {
        if (knows(c, i))
            c = i;
    }
    for (int i = 0; i < n; i++) {
        if (i != c && (knows(c, i) || !knows(i, c)))
            return -1;
    }
    return c;
}
