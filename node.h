#ifndef NODE_H
#define NODE_H

template <typename T>
struct NodeBT {
    T data;
    int height;
    NodeBT* left;
    NodeBT* right;
    NodeBT() : left(nullptr), right(nullptr), height(0) {}
    NodeBT(T value) : data(value), left(nullptr), right(nullptr), height(0) {}

    void killSelf(){
        if(left != nullptr) left->killSelf();
        if(right != nullptr) right->killSelf();
        delete this;
    }
};

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(T value){
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node<T>(const Node<T>& other){
        this->data = other.data;
        this->next = other.next;
        this->prev =  other.prev;
    }

    Node<T>& operator=(const Node<T>& other) {
        this->data = other.data;
        this->next = other.next;
        this->prev =  other.prev;
        return *this;
    }

    void killSelf(){
        if(this->next != nullptr){
            this->next->killSelf();
        }
        delete this;
    }
};

#endif // NODE_H
