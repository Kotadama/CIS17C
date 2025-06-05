#include <iostream>
#include "Doctor.h"
#include "Lawyer.h"
#include "SoftwareEngineer.h"
#include "Salesperson.h"
using namespace std;

// Polymorphic function
void printSalary(const Worker& worker) 
{
    cout << worker.getName() << " earns $" << worker.salaryPerWeek() << " per week." << endl;
}

int main() 
{
    cout << "===== Testing Doctor Class =====" << endl;
    Doctor doc("Dr. Smith");  // Testing constructor
    cout << "Constructor: Name = " << doc.getName() << ", Salary = $" << doc.getSalary() << endl;
    printSalary(doc);

    doc.setName("Dr. Adams");  // Testing mutator for name
    doc.setSalary(350000.0);   // Testing mutator for salary
    cout << "After mutators: Name = " << doc.getName() << ", Salary = $" << doc.getSalary() << endl;
    printSalary(doc);
    cout << endl;

    cout << "===== Testing Lawyer Class =====" << endl;
    Lawyer law("Attorney Johnson");
    cout << "Constructor: Name = " << law.getName() << ", Salary = $" << law.getSalary() << endl;
    printSalary(law);

    law.setName("Attorney Clark");
    law.setSalary(180000.0);
    cout << "After mutators: Name = " << law.getName() << ", Salary = $" << law.getSalary() << endl;
    printSalary(law);
    cout << endl;

    cout << "===== Testing SoftwareEngineer Class =====" << endl;
    SoftwareEngineer eng("Engineer Brown");
    cout << "Constructor: Name = " << eng.getName() << ", Salary = $" << eng.getSalary() << endl;
    printSalary(eng);

    eng.setName("Engineer Taylor");
    eng.setSalary(120000.0);
    cout << "After mutators: Name = " << eng.getName() << ", Salary = $" << eng.getSalary() << endl;
    printSalary(eng);
    cout << endl;

    cout << "===== Testing Salesperson Class =====" << endl;
    Salesperson sales("Salesperson Davis");
    cout << "Constructor: Name = " << sales.getName() << ", Salary = $" << sales.getSalary() << endl;
    printSalary(sales);

    sales.setName("Salesperson Morgan");
    sales.setSalary(70000.0);
    cout << "After mutators: Name = " << sales.getName() << ", Salary = $" << sales.getSalary() << endl;
    printSalary(sales);
    cout << endl;


    return 0;
}
