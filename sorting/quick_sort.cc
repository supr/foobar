#include <iostream>
#include <vector>
#include "sort.h"

unsigned int quick_sort_partition(std::vector<int>& arr, unsigned int start,
                                  unsigned int end) {
        int pivot = arr[end];
        unsigned int i = start - 1;
        for (unsigned int j = start; j <= end - 1; j++) {
                if (arr[j] <= pivot) {
                        i += 1;
                        int tmp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = tmp;
                }
        }

        int tmp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = tmp;

        return i + 1;
}

void quick_sort_internal(std::vector<int>& arr, unsigned int start,
                         unsigned int end) {
        if (start < end) {
                unsigned int part = quick_sort_partition(arr, start, end);
                if (part > 0) {
                        quick_sort_internal(arr, start, part - 1);
                        quick_sort_internal(arr, part, end);
                }
        }
}

void quick_sort(std::vector<int>& arr) {
        quick_sort_internal(arr, 0u, (unsigned int)(arr.size() - 1));
}
