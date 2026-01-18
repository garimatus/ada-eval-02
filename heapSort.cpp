//
// Created by gari on 17-01-26.
//
#include <iostream>

void heapify(int **arr, const int n, const int i, const int index) {
    if (!arr || i >= n || index < 0) return;

    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // If left child is smaller than root
    if (l < n && arr[l][index] < arr[smallest][index])
        smallest = l;
    // If right child is smaller than smallest so far
    if (r < n && arr[r][index] < arr[smallest][index])
        smallest = r;
    // If smallest is not root
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest, index);
    }
}

void heapSort(int **arr, int n, int index) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, index);
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0, index);
    }
}