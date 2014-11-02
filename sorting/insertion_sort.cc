#include <vector>
#include "sort.h"

void insertion_sort(std::vector<int>& arr) {
        for (int j = 1, i; j < arr.size(); j++) {
                int key = arr[j];
                i = j - 1;
                while (i >= 0 && key < arr[i]) {
                        arr[i + 1] = arr[i];
                        i = i - 1;
                }
                arr[i + 1] = key;
        }
}
