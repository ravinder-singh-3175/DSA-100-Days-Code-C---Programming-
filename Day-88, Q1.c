int canPlace(int* pos, int n, int m, int dist) {
    int count = 1;          // first ball at pos[0]
    int last = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
            if (count == m) return 1;
        }
    }
    return 0;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), cmp);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;          // mid works, try bigger
            low = mid + 1;
        } else {
            high = mid - 1;     // mid too big
        }
    }
    return ans;
}
