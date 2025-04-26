#include "Salesperson.h"

Salesperson::Salesperson(string name) : Worker(name, 64310.0) {}

double Salesperson::salaryPerWeek() const {
    return salary / 52.0;
}
