#ifndef TRIES_H
#define TRIES_H

#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

const unsigned ALPHA_SIZEs = 26; // tamaño del alfabeto: letras minúsculas

bool BoyesMoore(string Texto, string Patron);

class Trie{
public:
    virtual void insert(string key) = 0;
    virtual bool search(string key) = 0;
    virtual void remove(string key) = 0;

    //imprime ordenado
    virtual string toString(string sep=",") = 0;
};


class TriePatricia : public Trie {
private:
    struct TrieNode {
        TrieNode **children;
        string prefix;
        bool endWord; // indica si es el final de una palabra

        TrieNode() : children(new TrieNode*[ALPHA_SIZEs]()), prefix(""), endWord(false) {}

        ~TrieNode() {
            for (int i = 0; i < ALPHA_SIZEs; i++) {
                delete children[i];
            }
            delete[] children;
        }
    };
    TrieNode* root;

public:
    TriePatricia() : root(nullptr) {}

    void insert(string key) {
        if (root == nullptr) {
            root = new TrieNode();
        }
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
                curr->children[index]->prefix = curr->prefix + c;
            }
            curr = curr->children[index];
        }
        curr->endWord = true;
    }

    bool search(string key) {
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr != nullptr && curr->endWord;
    }

    void remove(string key) {
        if (!search(key)) {
            return;
        }
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - 'a';
            curr = curr->children[index];
        }
        curr->endWord = false;
    }

    string toString(string sep) {
        string result;
        if (root != nullptr) {
            toStringHelper(root, result, sep);
        }
        return result;
    }

    vector<string> getWordsWithPrefix(string prefix) {
        vector<string> words;
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return words; // Retorna una lista vacía si no hay palabras con el prefijo dado
            }
            curr = curr->children[index];
        }
        getWordsHelper(curr, words);
        return words;
    }

    vector<string> contains(string pattern){
        vector<string> words;
        TrieNode* curr = root;
        patternHelper(curr, words, pattern);
        return words;
    }

private:
    void toStringHelper(TrieNode* node, string& result, string& sep) {
        if (node == nullptr) {
            return;
        }
        if (node->endWord) {
            result += node->prefix + sep;
        }
        for (int i = 0; i < ALPHA_SIZEs; i++) {
            toStringHelper(node->children[i], result, sep);
        }
    }

    void getWordsHelper(TrieNode* node, vector<string>& words) {
        if (node == nullptr) {
            return;
        }
        if (node->endWord) {
            string temp = node->prefix;
            temp[0] = std::toupper(temp[0]);
            words.push_back(temp);
        }
        for (int i = 0; i < ALPHA_SIZEs; i++) {
            getWordsHelper(node->children[i], words);
        }
    }

    void patternHelper(TrieNode* node, vector<string>& words, string pattern) {
        if (node == nullptr) {
            return;
        }
        if (node->endWord) {
            string temp = node->prefix;
            if(BoyesMoore(temp, pattern)){
                temp[0] = std::toupper(temp[0]);
                words.push_back(temp);
            }
        }
        for (int i = 0; i < ALPHA_SIZEs; i++) {
            patternHelper(node->children[i], words,pattern);
        }
    }
};

bool BoyesMoore(string Texto, string Patron){
    int n = Texto.size();
    int m = Patron.size();
    vector<int> positions(256, -1);
    for (int i = 0; i < m; i++) {
        positions[Patron[i]] = i;
    }
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 and Patron[j] == Texto[i + j]) {
            j--;
        }
        if (j < 0) {
            return true;
        } else {
            i = i + max(1, j - positions[Texto[i + j]]);
        }
    }
    return false;
}

#endif // TRIES_H
