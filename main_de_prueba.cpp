#include "BankTransfer.h"
#include "Blockchain.h"

using namespace std;

int main() {

    auto transfer1 = new BankTransfer("Alice", "Emma", 50);
    auto transfer2 = new BankTransfer("Bob", "Olivia", 100);
    auto transfer3 = new BankTransfer("Charlie", "Sophia", 200);
    auto transfer4 = new BankTransfer("Diego", "Ava", 500);
    auto transfer5 = new BankTransfer("Daniel", "Liam", 1000);
    auto transfer6 = new BankTransfer("Ethan", "Isabella", 150);
    auto transfer7 = new BankTransfer("Frederick", "Mia", 300);
    auto transfer8 = new BankTransfer("George", "Charlotte", 250);
    auto transfer9 = new BankTransfer("Henry", "Amelia", 400);
    auto transfer10 = new BankTransfer("Isaac", "Harper", 600);
    auto transfer11 = new BankTransfer("John", "Damian", 600);

    Blockchain<BankTransfer> chain(4, 10);

    chain.insert_transaction(transfer1);
    chain.insert_transaction(transfer2);
    chain.insert_transaction(transfer3);
    chain.insert_transaction(transfer4);
    chain.insert_transaction(transfer5);
    chain.insert_transaction(transfer6);
    chain.insert_transaction(transfer7);
    chain.insert_transaction(transfer8);
    chain.insert_transaction(transfer9);
    chain.insert_transaction(transfer10);
    chain.insert_transaction(transfer11);

    chain.load_transactions_from_csv("dataset.csv");

    cout << "Monto máximo: " << chain.max_amount() << endl;
    cout << "Monto mínimo: " << chain.min_amount() << endl;
    cout << "Montos entre 100 y 200: ";
    for(auto elem : chain.range_search(100,200))
        cout << elem << " ";
    cout << endl;
    cout << "Usuarios que inician con 'Dan': ";
    for(auto elem : chain.start_with("Ma"))
        cout << elem << " ";
    cout << endl;
    for(auto elem : chain.contains("ie"))
        cout << elem << " ";
    cout << endl;


    chain.modify_block(5,4,new BankTransfer("Alice", "Emma", 50));
}