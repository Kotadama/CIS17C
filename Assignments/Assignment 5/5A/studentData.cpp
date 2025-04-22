#include "StudentData.h"

// Constructor
StudentData::StudentData(string ln, string fn, string addr, string c, string s, string z, string p,
                         int id, bool freshman)

: PersonData(ln, fn, addr, c, s, z, p) // Call base class constructor
{
    studentID = id;
    incomingFreshman = freshman;
}

// Accessors
int StudentData::getStudentID() const {
    return studentID;
}

bool StudentData::isIncomingFreshman() const {
    return incomingFreshman;
}

// Mutators
void StudentData::setStudentID(int id) {
    studentID = id;
}

void StudentData::setIncomingFreshman(bool freshman) {
    incomingFreshman = freshman;
}
