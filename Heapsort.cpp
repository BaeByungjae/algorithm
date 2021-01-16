//2017029743_배병재_A
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int* heap;
void heapify(int* arr, int size, int mid) {
    int parent_node = mid;
    int left_node = parent_node * 2 + 1;
    int right_node = parent_node * 2 + 2;
    int largest_node = parent_node;
    int temp;
    if (left_node < size && arr[left_node] < arr[largest_node]) {
        largest_node = left_node;
    }
    if (right_node < size && arr[right_node] < arr[largest_node]) {
        largest_node = right_node;
    }
    if (parent_node != largest_node) {
        temp = arr[largest_node];
        arr[largest_node] = arr[parent_node];
        arr[parent_node] = temp;
        heapify(arr, size, largest_node);
    }
}
void buildMaxHeap(int* arr, int size) {
    int mid = size / 2 - 1;
    for (mid; mid >= 0; mid--) {
        heapify(arr, size, mid);
    }
}
void heapSort(int* arr, int size, int k)
{
    int n = size;
    buildMaxHeap(arr, size);
    int temp;
    while (size > 1) {
        temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;
        heapify(arr, size, 0);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i + 1 == k)printf("\n");
    }
}
int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    int size = n;
    heap = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heap[i]);
    }
    heapSort(heap, size, k);
    return 0;
}