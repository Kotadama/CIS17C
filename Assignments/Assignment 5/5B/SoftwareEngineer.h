#ifndef SOFTWAREENGINEER_H
#define SOFTWAREENGINEER_H

#include "Worker.h"

class SoftwareEngineer : public Worker {
public:
    SoftwareEngineer(string name);
    double salaryPerWeek() const override;
};

#endif
