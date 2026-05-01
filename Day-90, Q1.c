#include <stdio.h>

int countPainters(int* boards, int n, long long maxLen) {
    long long curr = 0;
    int painters = 1; // at least one painter
    for (int i = 0; i < n; i++) {
        if (curr + boards[i] > maxLen) {
            painters++;
            curr = boards[i];
        } else {
            curr += boards[i];
        }
    }
    return painters;
}

int painterPartition(int* boards, int n, int k) {
    long long left = boards[0], right = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > left) left = boards[i]; // max board length
        right += boards[i];                     // total length
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;
        int painters = countPainters(boards, n, mid);
        if (painters > k) {
            left = mid + 1; // too many painters → increase allowed length
        } else {
            right = mid;    // feasible → try smaller length
        }
    }
    return (int)left;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int boards[n];
    for (int i = 0; i < n; i++) scanf("%d", &boards[i]);

    printf("%d\n", painterPartition(boards, n, k));
    return 0;
}
