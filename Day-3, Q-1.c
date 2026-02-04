#include <stdio.h>

int main() {
    int n, k;
    int i;
    int count = 0;
    int found = 0;
    int arr[100];

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter element to search: ");
    scanf("%d", &k);

    // Linear search
    
    for (i = 0; i < n; i++) {
        count++;              // comparison made
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", count);

    return 0;
}