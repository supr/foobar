#include <vector>
#include "sort.h"

void merge_internal(std::vector<int>& all, const std::vector<int>& left,
                    const std::vector<int>& right) {
        unsigned int nl = 0, nr = 0, nk = 0;

        while (nl < left.size() && nr < right.size()) {
                if (left[nl] <= right[nr]) {
                        all[nk] = left[nl];
                        nl += 1;
                } else {
                        all[nk] = right[nr];
                        nr += 1;
                }

                nk += 1;
        }

        while (nl < left.size()) {
                all[nk++] = left[nl++];
        }

        while (nr < right.size()) {
                all[nk++] = right[nr++];
        }
}

void merge_sort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;

        std::vector<int>::iterator middle = arr.begin() + (arr.size() / 2);

        std::vector<int> left(arr.begin(), middle);
        std::vector<int> right(middle, arr.end());

        merge_sort(left);
        merge_sort(right);

        merge_internal(arr, left, right);
}
