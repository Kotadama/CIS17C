#ifndef SALESPERSON_H
#define SALESPERSON_H

#include "Worker.h"

class Salesperson : public Worker {
public:
    Salesperson(string name);
    double salaryPerWeek() const override;
};

#endif
