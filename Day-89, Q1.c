#include <stdio.h>

int isPossible(int *arr, int n, int m, int limit) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > limit) return 0;  // cannot allocate

        if (pages + arr[i] <= limit) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];

            if (students > m) return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}
