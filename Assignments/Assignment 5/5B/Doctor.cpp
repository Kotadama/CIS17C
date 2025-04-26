#include "Doctor.h"

Doctor::Doctor(string name) : Worker(name, 294000.0) {}

double Doctor::salaryPerWeek() const {
    return salary / 52.0;
}
