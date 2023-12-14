cmake_minimum_required(VERSION 3.17)
project(Blockchain)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(Blockchain main.cpp sha256.h list.h node.h double.h Block.h BankTransfer.h Blockchain.h B+Tree.h heap.h hashtable.h tries.h)
target_link_libraries(Blockchain ${OPENSSL_CRYPTO_LIBRARY})
