#ifndef AEDA_UGHEATS_CLIENT_H
#define AEDA_UGHEATS_CLIENT_H

#include <string>
#include "Base.h"
#include "Address.h"
#include "utils.h"

using namespace std;

class Client {
private:
    string name;
    Base base;
    Address address;
    int nif;
    bool black_listed;

public:
    Client() = default;
    Client(string name, Base base, Address address, int nif, bool black_listed);
    //Metodos Set
    void setClientName(string name);
    void setBase(Base base);
    void setClientAddress(Address address);
    void setClientNif(int nif);
    void setBlack_listed(bool black_listed);
    //Metodos Get
    string getClientName() const;
    Base getBase() const;
    Address getClientAddress() const;
    int getClientNif() const;
    bool getBlack_listed();
    //Other Methods

};


#endif //AEDA_UGHEATS_CLIENT_H