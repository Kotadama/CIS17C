#include "Lawyer.h"

Lawyer::Lawyer(string name) : Worker(name, 144230.0) {}

double Lawyer::salaryPerWeek() const {
    return salary / 52.0;
}
