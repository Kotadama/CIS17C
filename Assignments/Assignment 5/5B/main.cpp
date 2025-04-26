#include <iostream>
#include "Doctor.h"
#include "Lawyer.h"
#include "SoftwareEngineer.h"
#include "Salesperson.h"
using namespace std;

// Polymorphic function
void printSalary(const Worker& worker) {
    cout << worker.getName() << " earns $" << worker.salaryPerWeek() << " per week." << endl;
}

int main() {
    Doctor doc("Dr. Smith");
    Lawyer law("Attorney Johnson");
    SoftwareEngineer eng("Engineer Brown");
    Salesperson sales("Salesperson Davis");

    printSalary(doc);
    printSalary(law);
    printSalary(eng);
    printSalary(sales);

    return 0;
}
