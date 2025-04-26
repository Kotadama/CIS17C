#ifndef LAWYER_H
#define LAWYER_H

#include "Worker.h"

class Lawyer : public Worker {
public:
    Lawyer(string name);
    double salaryPerWeek() const override;
};

#endif
