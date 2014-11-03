#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <cmath>
#include <exception>

#define TIME(str, oper)                                                      \
        do {                                                                 \
                auto data_start = std::chrono::high_resolution_clock::now(); \
                oper;                                                        \
                auto data_end = std::chrono::high_resolution_clock::now();   \
                std::cout                                                    \
                    << #str " Took: "                                        \
                    << std::chrono::duration_cast<std::chrono::nanoseconds>( \
                           data_end - data_start).count() << "ns"            \
                    << std::endl;                                            \
        } while (0);

#include "sort.h"

void print_vector(std::vector<int>& arr) {
        for (unsigned int i = 0; i < arr.size(); i++) {
                std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
}

int main(int argc, char* argv[]) {

        unsigned int size = 100;

        if (argc > 1) {
                size = std::atoi(argv[1]);
                if (!size) {
                        size = 1;
                }
        }

        std::random_device rd;
        std::vector<int> arr = std::vector<int>(size);
        std::default_random_engine dre(rd());
        std::uniform_int_distribution<int> di(0, 999);

        for (unsigned int i = 0; i < arr.size(); i++) {
                arr[i] = di(dre);
        }

        // Insertion Sort
        auto isort_future = std::async(std::launch::async, [=] {
                std::vector<int> isort_data(arr);
                TIME(Insertion Sort, insertion_sort(isort_data));
        });
        // print_vector(isort_data);

        // Merge Sort
        auto msort_future = std::async(std::launch::async, [=] {
                std::vector<int> msort_data(arr);
                TIME(Merge Sort, merge_sort(msort_data));
        });
        // print_vector(msort_data);

        // Quick Sort
        auto qsort_future = std::async(std::launch::async, [=] {
                std::vector<int> qsort_data(arr);
                TIME(Quick Sort, quick_sort(qsort_data));
        });
        // print_vector(qsort_data);

        try {
                msort_future.get();
                isort_future.get();
                qsort_future.get();
        }
        catch (const std::exception& e) {
                std::cout << "Exception: " << e.what() << std::endl;
        }
        return 0;
}
