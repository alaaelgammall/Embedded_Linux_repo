#include <stdio.h>

int binary_search(int arr[], int low, int high, int key);

int binary_search(int arr[], int low, int high, int key) {
    while (high >= low) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int result = binary_search(arr, 0, size - 1, key);
    printf("%d", result);
    return 0;
}
