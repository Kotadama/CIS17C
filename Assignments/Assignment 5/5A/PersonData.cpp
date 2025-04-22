// Constructor and member functions will go here
#include "PersonData.h"


// Constructor
PersonData::PersonData(string ln, string fn, string addr, string c, string s, string z, string p) {
    lastName = ln;
    firstName = fn;
    address = addr;
    city = c;
    state = s;
    zip = z;
    phone = p;
}



// Accessors
string PersonData::getLastName() const {
    return lastName;
}

string PersonData::getFirstName() const {
    return firstName;
}

string PersonData::getAddress() const {
    return address;
}

string PersonData::getCity() const {
    return city;
}

string PersonData::getState() const {
    return state;
}

string PersonData::getZip() const {
    return zip;
}

string PersonData::getPhone() const {
    return phone;
}



// Mutators
void PersonData::setLastName(string ln) {
    lastName = ln;
}

void PersonData::setFirstName(string fn) {
    firstName = fn;
}

void PersonData::setAddress(string addr) {
    address = addr;
}

void PersonData::setCity(string c) {
    city = c;
}

void PersonData::setState(string s) {
    state = s;
}

void PersonData::setZip(string z) {
    zip = z;
}

void PersonData::setPhone(string p) {
    phone = p;
}
