#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Heap
{
public:
    enum Type {
        MAX_HEAP, MIN_HEAP
    };

private:
    T *elements;
    int capacity;
    int n;
    Type type;

public:
    Heap(T *elements, int n, Type type=MAX_HEAP) : elements(elements), n(n), type(type){
        for (int i=n/2-1; i>=0; i--)
            heapify_down(i);
    }

    Heap(int capacity, Type type=MAX_HEAP) : capacity(capacity), type(type){
        elements = new T[capacity];
        n=0;
    }

    ~Heap(){
        delete[] elements;
    }

    void buildFromArray(T *elements, int n){
        this->n = n;
        for (int i = 0; i < n; i++)
            this->elements[i] = elements[i];
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify_down(i);
    }

    int size(){
        return n;
    }

    bool is_empty(){
        return n == 0;
    }

    void push(T value){
        if (n == capacity)
            resize(2 * capacity);

        elements[n] = value;
        n++;
        heapify_up(n - 1);
    }

    T pop(){
        if (is_empty())
            throw std::runtime_error("Heap is empty");

        T root = elements[0];
        elements[0] = elements[n - 1];
        n--;
        heapify_down(0);

        return root;
    }

    T top(){
        if (is_empty())
            throw std::runtime_error("Heap is empty");
        return elements[0];
    }

    vector<T> extractTheTopK(int k){
        if (k <= 0 or k > n)
            throw std::runtime_error("Invalid value of k");

        vector<T> result;
        for (int i = 0; i < k; i++)
            result.push_back(pop());

        return result;
    }

    static void sortAsc(T* arr, int n){
        for (int i = 0; i < n - 1; i++){
            int minIndex = i;
            for (int j = i + 1; j < n; j++){
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            if (minIndex != i)
                swap(arr[i], arr[minIndex]);
        }
    }

    static void sortDesc(T* arr, int n){
        for (int i = 0; i < n - 1; i++){
            int maxIndex = i;
            for (int j = i + 1; j < n; j++){
                if (arr[j] > arr[maxIndex])
                    maxIndex = j;
            }
            if (maxIndex != i)
                swap(arr[i], arr[maxIndex]);
        }
    }


private:
    int Parent(int i){
        return (i - 1) / 2;
    }

    int Left(int i){
        return (2 * i + 1);
    }

    int Right(int i){
        return (2 * i + 2);
    }

    void heapify_down(int i){
        int left = Left(i);
        int right = Right(i);
        int largest = i;

        if (type == MAX_HEAP && left < n and elements[left] > elements[largest])
            largest = left;

        if (type == MAX_HEAP and right < n and elements[right] > elements[largest])
            largest = right;

        if (type == MIN_HEAP and left < n and elements[left] < elements[largest])
            largest = left;

        if (type == MIN_HEAP and right < n and elements[right] < elements[largest])
            largest = right;

        if (largest != i){
            swap(elements[i], elements[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i){
        int parent = Parent(i);

        if (type == MAX_HEAP and i > 0 and elements[i] > elements[parent]){
            swap(elements[i], elements[parent]);
            heapify_up(parent);
        }

        if (type == MIN_HEAP and i > 0 and elements[i] < elements[parent]){
            swap(elements[i], elements[parent]);
            heapify_up(parent);
        }
    }

    void resize(int new_capacity){
        T* new_elements = new T[new_capacity];
        for (int i = 0; i < n; i++)
            new_elements[i] = elements[i];
        delete[] elements;
        elements = new_elements;
        capacity = new_capacity;
    }
};

#endif // HEAP_H
