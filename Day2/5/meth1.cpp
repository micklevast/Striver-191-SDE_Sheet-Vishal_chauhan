#include <bits/stdc++.h>
using namespace std;
int findDuplicate(const vector<int>& nums, int l, int h) {
    // cout << "l: " << l << " h: " << h << endl;
    while (l <= h) {
        int mid = (l + h) / 2;
        int cnt = 0;
        for (auto val : nums) {
            if (val <= mid)
                cnt++;
        }
        if (cnt <= mid) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    // cout << "l: " << l << endl;
    return l;
}

vector<int> repeatedNumber(const vector<int>& A) {
    int n = A.size();
    // cout<<"n:"<<n<<endl;
    int dupli = findDuplicate(A, 1, n - 1);
    long sum = 0;
    for (auto val : A) {
        sum += val;
    }
    long total = ((n) * (n + 1)) / 2;
    // cout<<"ttl:"<<total<<" sum:"<<sum<<"  dupli:"<<dupli<<endl;
    int missing = (total+ dupli) - (sum);
    return {dupli, missing};
}