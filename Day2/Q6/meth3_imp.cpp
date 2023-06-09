#include <bits/stdc++.h> 

void merging(long long* arr, int l, int mid, int r, int& ans) {
    vector<long long> temp(r - l + 1);
    int i = l;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            ans += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int x = 0; x < k; x++) {
        arr[l + x] = temp[x];
    }
}

void mergeSort(long long* arr, int l, int r, int& ans) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid, ans);
        mergeSort(arr, mid + 1, r, ans);
        merging(arr, l, mid, r, ans);
    }
}

long long getInversions(long long* arr, int n) {
    int ans = 0;
    mergeSort(arr, 0, n - 1, ans);
    return ans;
}