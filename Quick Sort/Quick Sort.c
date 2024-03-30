#include <stdio.h>

//החלפה בין שני האלמנטים
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//מחלק את המערך ומחזיר את המיקום במערך של נקודת הציר
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

//פונקציה רקורסיבית המבצעת את הסידור
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        //מחלק את המערך ומקבל את נקודת הציר
        int pivotIndex = partition(arr, low, high);

        //באופן רקורסיבי מחלק את תת המערך
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    size_t numElements = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (size_t i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, numElements - 1);

    printf("\nSorted array: ");
    for (size_t i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
