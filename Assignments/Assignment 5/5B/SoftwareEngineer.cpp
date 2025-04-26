#include "SoftwareEngineer.h"

SoftwareEngineer::SoftwareEngineer(string name) : Worker(name, 108080.0) {}

double SoftwareEngineer::salaryPerWeek() const {
    return salary / 52.0;
}
