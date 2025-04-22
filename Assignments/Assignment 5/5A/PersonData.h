#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>
using namespace std;

class PersonData 
{

public:
    // Constructor
    PersonData(string ln, string fn, string addr, string c, string s, string z, string p);

    // Accessors
    string getLastName() const;
    string getFirstName() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    string getZip() const;
    string getPhone() const;

    // Mutators
    void setLastName(string ln);
    void setFirstName(string fn);
    void setAddress(string addr);
    void setCity(string c);
    void setState(string s);
    void setZip(string z);
    void setPhone(string p);

private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

};

#endif // PERSONDATA_H
