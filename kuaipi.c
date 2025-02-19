#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pos = partition(a, low, high);
        quickSort(a, low, pos - 1);
        quickSort(a, pos + 1, high);
    }
}

int main() {
    int a[8] = {50, 40, 70, 90, 80, 10, 20, 60};
    int low = 0;
    int high = 7;
    quickSort(a, low, high);
    
    printf("快速排序的结果为： ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    getchar();
    return 0;
}