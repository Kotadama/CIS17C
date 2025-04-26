#ifndef DOCTOR_H
#define DOCTOR_H

#include "Worker.h"

class Doctor : public Worker {
public:
    Doctor(string name);
    double salaryPerWeek() const override;
};

#endif
