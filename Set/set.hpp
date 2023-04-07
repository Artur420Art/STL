#include "set.h"
template<typename T>
void m_set<T>::insert(T value) {
    
    
}
template<typename T>
m_set<T>::Node::Node(T value) {
    root->data = value;
}
template<typename T>
void m_set<T>::print(Node* ptr = nullptr) { 
    print(root->left);
    print(root->data);
    std::cout << root->data << " ";
}
template<typename T>
m_set<T>::Node m_set<T>::insert_helper(Node* ptr, T value) {
    if (ptr == nullptr) {
        ptr = new Node(value);
        ptr->left = nullptr;
        ptr->right = nullptr;
        return;
    }
    if (ptr->data == value) {
        return;
    }
    if(ptr->data > value) {
        insert_helper(ptr->left, value);
    }
    if(ptr->data < value) {
        insert_helper(ptr->right, value);
    }
}