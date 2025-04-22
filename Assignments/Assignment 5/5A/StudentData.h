#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include "PersonData.h"

class StudentData : public PersonData 
{
public:
    // Constructor
    StudentData(string ln, string fn, string addr, string c, string s, string z, string p,
                int id, bool freshman);

    // Accessors
    int getStudentID() const;
    bool isIncomingFreshman() const;

    // Mutators
    void setStudentID(int id);
    void setIncomingFreshman(bool freshman);

private:
    int studentID;
    bool incomingFreshman;
};

#endif // STUDENTDATA_H
