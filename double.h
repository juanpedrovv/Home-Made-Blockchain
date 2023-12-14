#ifndef DOUBLE_H
#define DOUBLE_H

#include <iostream>
#include <node.h>
#include "list.h"

template <typename T>
class IteratorDouble;

template <typename T>
class DoubleList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;
public:
    DoubleList() : List<T>() {
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes = 0;
    }

    DoubleList(const DoubleList<T>& other){
        this->head = other.head;
        this->tail = other.tail;
        this->nodes = other.nodes;
    }

    DoubleList<T>& operator=(const DoubleList<T>& other) {
        if(other.head == nullptr){this->head = nullptr; this->tail = nullptr;}
        this->head = new Node<T>(other.head->data);
        this->tail = this->head;
        Node<T>* temp = other.head;
        while(temp->next != nullptr){
            (*this).push_back(temp->data);
            temp = temp->next;
        }
        this->nodes =  other.nodes;
        return *this;
    }

    ~DoubleList(){
        if (this->head == nullptr) return;
        this->head->killSelf();
        this->nodes = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    IteratorDouble<T> begin() const {
        IteratorDouble<T> it(this->head);
        return it;
    }

    IteratorDouble<T> end() const {
        IteratorDouble<T> it(nullptr);
        return it;
    }

    T front() override{
        // O (1)
        if (this->head == nullptr)
            throw std::runtime_error("Double List has no elements");
        return this->head->data;
    }

    T back() override{
        // O (n)
        if (this->head == nullptr)
            throw std::runtime_error("Double List has no elements");

        return this->tail->data;
    }

    void push_front(T data) override{
        // O (1)
        if (this->head == nullptr){
            Node<T> * new_ = new Node<T>();
            new_->data = data;
            new_->next = nullptr;
            new_->prev = nullptr;
            this->head = new_;
            this->tail = new_;
            this->nodes++;
        }else {
            Node<T> * new_ = new Node<T>();
            new_->data = data;
            new_->next = this->head;
            new_->prev = nullptr;
            this->head->prev = new_;
            this->head = new_;
            this->nodes++;
        }
    }

    void push_back(T data) override{
        // O (1)
        if (this->head == nullptr){
            Node<T> * new_ = new Node<T>();
            new_->data = data;
            new_->next = nullptr;
            new_->prev = nullptr;
            this->head = new_;
            this->tail = new_;
            this->nodes++;
        }else{
            Node<T> * new_ = new Node<T>();
            new_->data = data;
            new_->next = nullptr;
            new_->prev = this->tail;
            this->tail->next = new_;
            this->tail = new_;
            this->nodes++;
        }
    }

    T pop_front() override{
        // O (1)
        if (this->head == nullptr){
            throw std::runtime_error("Double List has no elements");
        }else if (this->head->next == nullptr){
            T aux = this->head->data;
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->nodes = 0;
            return aux;
        }else{
            Node<T> * temp = this->head;
            T aux = this->head->data;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp;
            this->nodes--;
            return aux;
        }
    }

    T pop_back() override{
        // O (1)
        if (this->head == nullptr){
            throw std::runtime_error("Double List has no elements");
        } else if (this->head->next == nullptr){
            T aux = this->head->data;
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->nodes = 0;
            return aux;
        }else{
            Node<T> * temp = this->tail;
            T aux = this->tail->data;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp;
            this->nodes--;
            return aux;
        }
    }

    T insert(T data, int pos) override{
        // O (n)
        if (pos > this->nodes || pos < 0){
            throw std::out_of_range("Index not found");
        }else{
            if (pos == 0){
                this->push_front(data);
            } else if (pos == this->nodes){
                this->push_back(data);
            }else{
                Node<T> * new_ = new Node<T>();
                new_->data = data;
                Node<T> * temp = this->head;
                for (int i = 0; i<pos-1; i++)
                    temp = temp->next;
                new_->next = temp->next;
                new_->prev = temp;
                temp->next->prev = new_;
                temp->next = new_;
                this->nodes++;
            }
            return data;
        }
    }

    bool remove(int pos) override{
        // O (n)
        if (pos >= this->nodes || pos < 0){
            throw std::out_of_range("Index out of range");
        }else{
            if (pos == 0){
                this->pop_front();
            } else if (pos == this->nodes - 1){
                this->pop_back();
            }else{
                Node<T> * temp = this->head;
                for (int i = 0; i<pos-1; i++)
                    temp = temp->next;
                Node<T> * rm = temp->next;
                temp->next->next->prev = temp;
                temp->next = temp->next->next;
                delete rm;
                this->nodes--;
            }
            return true;
        }
    }

    T& operator[](int pos) override{
        if (pos >= this->nodes || pos < 0){
            throw std::out_of_range("Index out of range");
        }else {
            Node<T> * temp = this->head;
            for (int i = 0; i < pos; i++)
                temp = temp->next;
            // retorno solo el valor
            return temp->data;
        }
    }

    bool is_empty() override{
        // O (1)
        return this->nodes == 0;
    }

    int size() override{
        // O (1)
        return this->nodes;
    }

    void clear() override{
        // O (n)
        if (this->head == nullptr) return;
        this->head->killSelf();
        this->nodes = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    string list_to_string() const {
        std::stringstream ss;
        Node<T>* current = head;
        while (current != nullptr) {
            ss << current->data << " ";
            current = current->next;
        }
        return ss.str();
    }

private:

    /*void sorted_insert(Node<T>*& head_sorted_list, Node<T>* new_){
        // Si la cabeza de la lista ordenada es vacia coloca el primer nodo
        if(head_sorted_list==nullptr){
            head_sorted_list = new_;
            // Si la cabeza de la lista es mayor que el nuevo nodo, el nuevo nodo es la cabeza
        } else if(new_ -> data <= head_sorted_list -> data){
            new_->next = head_sorted_list;
            new_->next->prev = new_;
            head_sorted_list = new_;
            // Inserta el nodo en una posicion antes de un nodo con un dato mayor
        }else{
            Node<T>* temp = head_sorted_list;
            while(temp->next != nullptr && new_->data > temp->next->data){
                temp = temp->next;
            }
            new_->next = temp->next;
            if(temp->next != nullptr){
                temp->next->prev = new_;
            }
            temp->next = new_;
            new_->prev = temp;
        }
    }

    void insertion_sort(){
        Node<T>* sorted_list = nullptr;
        Node<T>* current = this->head;
        // Por cada nodo quita su enlaces e insertalo a la lista ordenada
        while(current != nullptr){
            Node<T>* next = current->next;
            current->prev = nullptr;
            current->next = nullptr;
            this->sorted_insert(sorted_list, current);
            current = next;
        }
        this->head = sorted_list;
    }*/

public:

    /*void sort(){
        if(this->nodes <= 1) return;
        this->insertion_sort();
        Node<T>* temp = this->head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        this->tail = temp;
    }

    bool is_sorted(){
        // O (n)
        Node<T> * temp = head;
        if(nodes < 2) return true;
        while(temp->next->next != nullptr){
            if(temp->data > temp->next->data){
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    void reverse(){
        // O (n)
        Node<T> * prev = nullptr;
        Node<T> * current = this->head;
        Node<T> * new_tail = this->head;
        Node<T> * nxt = nullptr;
        while(current != nullptr){
            nxt = current->next;
            current->next = prev;
            current->prev = nxt;
            prev = current;
            current = nxt;
        }
        this->head = prev;
        this->tail = new_tail;
    }*/

    std::string name() override{
        return "DoubleList";
    }
};

template <typename T>
class IteratorDouble{
private:
    Node<T> * current;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;

    IteratorDouble() : current(nullptr){};
    explicit IteratorDouble(Node<T> * node) : current(node){};

    IteratorDouble<T>& operator=(IteratorDouble<T> other){
        this->current = other.current;
        return *this;
    }

    friend bool operator==(const IteratorDouble<T>& a, const IteratorDouble<T>& b) { return a.current == b.current; }
    friend bool operator!= (const IteratorDouble<T>& a, const IteratorDouble<T>& b) { return a.current != b.current; }

    IteratorDouble<T> operator++(){
        this->current = this->current->next;
        return *this;
    }
    IteratorDouble<T> operator++(int){
        (*this)++;
        return *this;
    }
    IteratorDouble<T> operator--(){
        this->current = this->current->prev;
        return *this;
    }
    reference operator*(){
        return this->current->data;
    }
    pointer operator->(){
        return &this->current->data;
    }
};

#endif // DOUBLE_H
