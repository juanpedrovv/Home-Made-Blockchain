#ifndef BANKTRANSFER_H
#define BANKTRANSFER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <ostream>
#include <sstream>

using namespace std;

typedef chrono::system_clock::time_point date_t;
typedef float mount_t;

class BankTransfer{
    string emisor;
    string receptor;
    mount_t monto;
    date_t fecha;

public:
    BankTransfer(){
        emisor = "";
        receptor = "";
        monto = 0.0;
        fecha = chrono::system_clock::now();
    }

    BankTransfer(string _emisor, string _receptor, mount_t _monto){
        emisor = _emisor;
        receptor = _receptor;
        monto = _monto;
        fecha = chrono::system_clock::now();
    }

    ~BankTransfer(){}

    string get_all_information() const {
        std::ostringstream oss;
        oss << this->monto;
        std::string strNumber = oss.str();
        return this->emisor + " send to " + this->receptor + " " + strNumber + " at " + getFechaAsString();

    }

    string get_emisor(){
        return emisor;
    }

    string get_receptor(){
        return receptor;
    }

    mount_t get_monto(){
        return monto;
    }

    date_t get_fecha(){
        return fecha;
    }

    void modify_emisor(const string& newEmisor) {
        emisor = newEmisor;
    }

    void modify_receptor(const string& newReceptor){
        receptor = newReceptor;
    }

    void modify_monto(const mount_t & newMonto){
        monto = newMonto;
    }

    void modify_fecha(const date_t& newDate){
        fecha = newDate;
    }

    friend std::ostream& operator<<(std::ostream& os, const BankTransfer& transfer);

private:
    std::string getFechaAsString() const {
        std::time_t time = std::chrono::system_clock::to_time_t(fecha);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
        return buffer;
    }
};

//Sobrecarga del operador para imprimir los datos de la transferencia
ostream& operator<<(std::ostream& os, const BankTransfer& transfer) {
    os << transfer.get_all_information();
    return os;
}


#endif // BANKTRANSFER_H
