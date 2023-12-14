#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <utility>
#include <fstream>
#include <sstream>
#include "vector"
#include "Block.h"
#include "BankTransfer.h"
#include "heap.h"
#include "B+Tree.h"
#include "tries.h"
#include "hashtable.h"

typedef float amount_t;

template <class Data>
class Blockchain{
    int size;
    int difficulty;
    int max_blockTransactions;
    Block<Data>* genesis;
    DoubleList<Block<Data>*> chain;

    //Indices
    Heap<amount_t> amounts_maxheap;
    Heap<amount_t> amounts_minheap;
    BPlusTree<amount_t> amounts;
    TriePatricia users;
    ChainHash<string, float> users_cash;

public:
    Blockchain():amounts_maxheap(10), amounts_minheap(10, Heap<amount_t>::MIN_HEAP), amounts(3), users(), users_cash(){
        max_blockTransactions = 10;
        size = 1;
        difficulty = 4;
        genesis = new Block<Data>(10, "0000000000000000000000000000000000000000000000000000000000000000");
        chain.push_back(genesis);
    }

    Blockchain(int _difficulty, int _maxTransactions): amounts_maxheap(_maxTransactions), amounts_minheap(_maxTransactions, Heap<amount_t>::MIN_HEAP),
        amounts(3),users(), users_cash(){
        max_blockTransactions = _maxTransactions;
        size = 1;
        difficulty = _difficulty;
        genesis = new Block<Data>(_maxTransactions, "0000000000000000000000000000000000000000000000000000000000000000");
        chain.push_back(genesis);
    }

    ~Blockchain(){
        for (auto blockPtr : chain) {
            delete blockPtr;
        }
    }

    void insert_transaction(Data* transaction){
        if(transaction->get_emisor() == "" or transaction->get_receptor() == "" or transaction->get_monto() == 0.0){
            throw "Empty parameter";
        }
        if(chain.back()->get_transactions_count() < max_blockTransactions){
            chain.back()->add_transaction(transaction);
            if(chain.back()->get_transactions_count() == max_blockTransactions)
                chain.back()->mineBlock(difficulty);
        }
        else{
            auto newBlock = new Block<Data>(max_blockTransactions, chain.back()->get_hash());
            newBlock->set_index(size+1);
            newBlock->add_transaction(transaction);
            chain.push_back(newBlock);
            size += 1;
        }
        amounts_maxheap.push(transaction->get_monto());
        amounts_minheap.push(transaction->get_monto());
        amounts.insert(transaction->get_monto());
        string temp1 = std::move(transaction->get_emisor());
        temp1[0] = std::tolower(temp1[0]);
        users.insert(temp1);
        string temp2 = std::move(transaction->get_receptor());
        temp2[0] = std::tolower(temp2[0]);
        users.insert(temp2);

        if(!users_cash.find(transaction->get_receptor()))
            users_cash.set(transaction->get_receptor(), transaction->get_monto());
        else{
            float cash = users_cash.search(transaction->get_receptor());
            users_cash.remove(transaction->get_receptor(), cash);
            users_cash.set(transaction->get_receptor(), (transaction->get_monto() + cash));
        }
    }

    int chain_size(){
        return size;
    }

    template<class TK=int, class TV=float>
    TV max_amount(){
        TV max = amounts_maxheap.top();
        return max;
    }

    template<class TK=int, class TV=float>
    TV min_amount(){
        TV min = amounts_minheap.top();
        return min;
    }

    template<class TK=int, class TV=float>
    vector<TV> range_search(TK begin, TK end){
        if(begin != 0 and end == 0)
            throw "Missed end parameter";
        if(end < begin)
            throw "Invalid search";
        return amounts.range_search(begin,end);
    }

    template<class TV=string>
    vector<TV> contains(string pattern){
        return users.contains(pattern);
    }

    template<class TV=string>
    vector<TV> start_with(string prefix){
        for (char& c : prefix) {
            c = tolower(c);
        }
        return users.getWordsWithPrefix(std::move(prefix));
    }

    template<class TK=string, class TV=float>
    TV search(TK key){
        return users_cash.search(key);
    }

    void print_block(int n_block){
        if(n_block > size)
            throw "Blockchain size exceeded";
        else{
            cout << "Index: " << chain[n_block-1]->get_index() << endl;
            cout << "Nonce: " << chain[n_block-1]->get_nonce() << endl;
            chain[n_block-1]->show_transactions();
            cout << "PrevHahs: " << chain[n_block-1]->get_prevHash() << endl;
            cout << "Hash: " << chain[n_block-1]->get_hash() << endl;
        }
    }

    void modify_block(int n_block, int n_register, Data* modify_transaction){
        if(n_block > size)
            throw "Blockchain size exceeded";

        if(n_register > max_blockTransactions)
            throw "Max registers size exceeded";

        if(n_register > chain[n_block - 1]->block_size())
            throw "Not found register";

        chain[n_block - 1]->modify_block(n_register, modify_transaction);
        chain[n_block - 1]->update_hash();
        for(int i=n_block; i < size; i++){
            chain[i]->update_prevhash(chain[i - 1]->get_hash());
            chain[i]->update_hash();
        }
    }

    Block<Data>* get_block(int n){
        return chain[n-1];
    }

    void load_transactions_from_csv(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error al abrir el archivo: " << filename << std::endl;
            return;
        }

        std::string line;
        bool firstLine = true; // Variable para omitir la primera línea (encabezados)
        while (std::getline(file, line)) {
            if (firstLine) {
                firstLine = false;
                continue;
            }

            std::stringstream ss(line);
            std::string emisor, receptor, monto;
            if (std::getline(ss, emisor, ',') && std::getline(ss, receptor, ',') && std::getline(ss, monto, ',')) {
                try {
                    float _monto = std::stof(monto);
                    auto* transaction = new BankTransfer(emisor, receptor, _monto);
                    insert_transaction(transaction);
                } catch (const std::exception& e) {
                    cout << "Error al procesar la transacción: " << e.what() << std::endl;
                }
            }
        }
        file.close();
        cout << "Transacciones ingresadas correctamente" << endl;
    }

};


#endif // BLOCKCHAIN_H
