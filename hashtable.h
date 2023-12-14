#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <functional>

using namespace std;

const float maxFillFactor = 0.4;
const int maxColision = 10;

template <typename TK, typename TV>
struct Entry{
    TK key;
    TV value;
    size_t hashcode;
    Entry(TK _key, TV _value){
        key = _key;
        value = _value;
    }
    ~Entry(){}
};

template<typename TK, typename TV>
class ChainHash{
private:

    list<Entry<TK, TV>> *array;
    int capacity; // Tamaño del array
    int size; // Cantidad de elementos totales
    hash<TK> hashFunction;

public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
        array = new list<Entry<TK,TV>>[capacity];
    }

    void set(TK key, TV value){
        int index = hashFunction(key) % capacity;
        if (size * 1.0 / (maxColision * capacity) >= maxFillFactor) {
            rehashing();
        }
        array[index].push_front(Entry<TK,TV>(key, value));
        size++;
    }

    int get_size(){
        return size;
    }

    bool find(TK key){
        int index = hashFunction(key) % capacity;
        for (const auto& entry : array[index]) {
            if (entry.key == key) {
                return true;
            }
        }
        return false;
    }

    TV search(TK key) {
        if (!find(key)) {
            return -1;
        }
        int index = hashFunction(key) % capacity;
        for (const auto& entry : array[index]) {
            if (entry.key == key) {
                return entry.value;
            }
        }
        return -1;
    }

    void display(){
        for(int i = 0; i < bucket_count(); i++){
            cout << "Bucket " << i << ": ";
            for (const auto& entry : array[i]) {
                cout << "(" << entry.key << ", " << entry.value << ") " << "-> ";
            }
            cout << endl;
        }
    }

    void remove(TK key, TV value) {
        int index = hashFunction(key) % capacity;
        auto it = array[index].begin();
        while (it != array[index].end()) {
            if (it->key == key && it->value == value) {
                array[index].erase(it);
                return;
            } else {
                ++it;
            }
        }
    }

    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i){
        return array[i].size();
    }

    ~ChainHash(){
        delete[] array;
    }

private:
    void rehashing(){
        int newCapacity = capacity * 2;
        list<Entry<TK,TV>>* newArray = new list<Entry<TK,TV>>[newCapacity];
        for(int i = 0; i < bucket_count(); i++){
            for(auto it = array[i].begin(); it != array[i].end(); ++it){
                TK key = it->key;
                TV value = it->value;
                int index = hashFunction(key) % newCapacity;
                newArray[index].push_front(Entry<TK,TV>(key, value));
            }
        }

        delete[] array;
        this->capacity *= 2;
        this->array = new list<Entry<TK,TV>>[capacity];

        for(int i = 0; i < bucket_count(); i++){
            array[i] = newArray[i];
        }

        delete[] newArray;
    }
};

#endif // HASHTABLE_H
