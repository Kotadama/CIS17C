#ifndef WORKER_H
#define WORKER_H

#include <string>
using namespace std;

class Worker {
protected:
    string name;
    double salary;
public:
    Worker(string name, double salary);
    
    void setName(string name);
    string getName() const;

    void setSalary(double salary);
    double getSalary() const;

    virtual double salaryPerWeek() const = 0; // Pure virtual function

    virtual ~Worker() {} // Virtual destructor
};

#endif
