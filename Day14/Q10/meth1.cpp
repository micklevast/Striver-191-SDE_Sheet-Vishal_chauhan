
#include <bits/stdc++.h>

bool knows(int A, int B); //have been given initernally in code studio

int findCelebrity(int n) {
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(i);
    }
    while (st.size() > 1) {
        int p1 = st.top();
        st.pop();
        int p2 = st.top();
        st.pop();
        if (knows(p1, p2)) {
            st.push(p2);
        } else {
            st.push(p1);
        }
    }
    int celebrity = st.top();

    // Check if the remaining candidate is a celebrity
    for (int i = 0; i < n; i++) {
        if (i != celebrity && (knows(celebrity, i) || !knows(i, celebrity))) {
            return -1; // No celebrity found
        }
    }

    return celebrity;
}
