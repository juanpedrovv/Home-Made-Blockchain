#ifndef SHA256_H
#define SHA256_H

#include <openssl/sha.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Función que calcula el hash SHA-256 de un string
string sha256(const std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

/// PoW Hashcash
// Función que realiza el Proof of Work
int proofOfWork(string blockData, string targetHashPrefix, string &_hash) {
    int nonce = 0;
    while (true) {
        string hash = sha256(blockData + to_string(nonce));
        if (hash.substr(0, targetHashPrefix.length()) == targetHashPrefix) {
            _hash = hash;
            return nonce;
        }
        nonce++;
    }
}


void sha_example(){
    /*std::string input = "Hello World!";
    std::cout << "SHA256 hash of \"" << input << "\" is:\n" << sha256(input) << std::endl;
    return 0;*/

    string blockData = "Hello, world";
    string targetHashPrefix = "0000";
    string hash;
    int nonce = proofOfWork(blockData, targetHashPrefix, hash);
    cout << "SHA 256: " << sha256(blockData)<< endl;
    cout << "Proof Of Work: " << hash << endl;
    cout << "Block mined with nonce: " << nonce << endl;
    //return 0;
}

#endif // SHA256_H
