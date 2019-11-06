#include "Company.h"

Company::Company(string name, Location location, double capital, int nif, string email, string phone,
                 vector<Worker> workers, vector<Base> bases) {
    this->name=name;
    this->location=location;
    this->capital=capital;
    this->nif=nif;
    this->email=email;
    this->phone=phone;
    this->workers=workers;
    this->bases=bases;
}

//Metodos Set
void Company::setCompanyName(string name) {
    this->name = name;
}

void Company::setCompanyLocation(Location location) {
    this->location = location;
}

void Company::setCompanyCapital(double capital) {
    this->capital = capital;
}

void Company::setCompanyNif(int nif) {
    this->nif = nif;
}

void Company::setCompanyEmail(string email) {
    this->email = email;
}

void Company::setCompanyPhone(string phone) {
    this->phone = phone;
}

void Company::setCompanyWorkers(vector<Worker> workers) {
    this->workers = workers;
}

void Company::setCompanyBases(vector<Base> bases) {
    this->bases = bases;
}

//Metodos Get
string Company::getCompanyName() const {
    return name;
}

Location Company::getCompanyLocation() const {
    return location;
}

double Company::getCompanyCapital() const {
    return capital;
}

int Company::getCompanyNif() const {
    return nif;
}

string Company::getCompanyEmail() const {
    return email;
}

string Company::getCompanyPhone() const {
    return phone;
}

vector<Worker> Company::getCompanyWorkers() const {
    return workers;
}

vector<Base> Company::getCompanyBases() const {
    return bases;
}

//Other Methods


