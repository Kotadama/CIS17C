#include "Worker.h"

Worker::Worker(string name, double salary) {
    this->name = name;
    this->salary = salary;
}

void Worker::setName(string name) {
    this->name = name;
}

string Worker::getName() const {
    return name;
}

void Worker::setSalary(double salary) {
    this->salary = salary;
}

double Worker::getSalary() const {
    return salary;
}
