#include <iostream>
#include <cmath>
#include <random>
#include <memory>

#include "bst.h"

int main(int argc, char* argv[]) {
        unsigned int size = 100u;

        if (argc > 1) {
                size = std::atoi(argv[1]);
                if (!size) {
                        size = 100u;
                }
        }

        std::random_device rd;
        std::default_random_engine dre(rd());
        std::uniform_int_distribution<int> di(0, 1000);

        BinarySearchTree<int> bstree;
        for(unsigned int i = 0; i < size; i++) {
                bstree.insert(di(dre));
        }
        bstree.inorder();
}
