#ifndef _BST_H_
#define _BST_H_
#include <iostream>
#include <functional>

template <typename T>
struct Node {
        T key;
        Node<T>* left;
        Node<T>* right;
        Node(T data) : key(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
       public:
        BinarySearchTree() {}
        ~BinarySearchTree();
        void insert(T data);
        void inorder();

       private:
        void insert_internal(T data, Node<T>** parent);
        void inorder_internal(Node<T>* parent);
        Node<T>* root = nullptr;
};

template <typename T>
void BinarySearchTree<T>::insert(T data) {
        insert_internal(data, &root);
}

template <typename T>
void BinarySearchTree<T>::insert_internal(T data, Node<T>** parent) {
        if (!*parent) {
                *parent = new Node<T>(data);
                return;
        }

        if (data <= ((*parent)->key)) {
                insert_internal(data, &((*parent)->left));
        } else {
                insert_internal(data, &((*parent)->right));
        }
}

template <typename T>
void BinarySearchTree<T>::inorder_internal(Node<T>* parent) {
        if (parent) {
                inorder_internal(parent->left);
                std::cout << parent->key << " ";
                inorder_internal(parent->right);
        }
}

template <typename T>
void BinarySearchTree<T>::inorder() {
        inorder_internal(root);
        std::cout << std::endl;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
        std::function<void(Node<T>*)> free_nodes = [&](Node<T>* ptr) {
                if (!ptr) return;

                if (ptr->left) {
                        free_nodes(ptr->left);
                }
                if (ptr->right) {
                        free_nodes(ptr->right);
                }
                delete ptr;
                return;
        };

        free_nodes(root);
}

#endif
