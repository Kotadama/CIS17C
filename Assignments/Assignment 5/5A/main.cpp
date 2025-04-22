#include <iostream>
#include "StudentData.h"
using namespace std;

int main() {
    // Create a StudentData object with initial data
    StudentData student(
        "Doe", "John", "123 Main St", "Anytown", "CA", "90210", "555-1234",
        12345, true
    );

    // Test accessors (getters)
    cout << "Testing getters:\n";
    cout << "Last Name: " << student.getLastName() << endl;
    cout << "First Name: " << student.getFirstName() << endl;
    cout << "Address: " << student.getAddress() << endl;
    cout << "City: " << student.getCity() << endl;
    cout << "State: " << student.getState() << endl;
    cout << "ZIP: " << student.getZip() << endl;
    cout << "Phone: " << student.getPhone() << endl;
    cout << "Student ID: " << student.getStudentID() << endl;
    cout << "Incoming Freshman: " << (student.isIncomingFreshman() ? "Yes" : "No") << endl;
    cout << endl;

    // Test mutators (setters)
    cout << "Testing setters:\n";
    student.setLastName("Smith");
    student.setFirstName("Jane");
    student.setAddress("456 Elm St");
    student.setCity("Othertown");
    student.setState("NY");
    student.setZip("10001");
    student.setPhone("555-5678");
    student.setStudentID(67890);
    student.setIncomingFreshman(false);

    // Display updated values
    cout << "Updated Last Name: " << student.getLastName() << endl;
    cout << "Updated First Name: " << student.getFirstName() << endl;
    cout << "Updated Address: " << student.getAddress() << endl;
    cout << "Updated City: " << student.getCity() << endl;
    cout << "Updated State: " << student.getState() << endl;
    cout << "Updated ZIP: " << student.getZip() << endl;
    cout << "Updated Phone: " << student.getPhone() << endl;
    cout << "Updated Student ID: " << student.getStudentID() << endl;
    cout << "Updated Incoming Freshman: " << (student.isIncomingFreshman() ? "Yes" : "No") << endl;

    return 0;
}
