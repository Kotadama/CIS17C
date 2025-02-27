#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

const int MONTHS = 12;

// Function prototypes
double totalAmount(const double[], int);
double averageAmount(const double[], int);
double largestMonth(const double[], int);
double smallestMonth(const double[], int);

int main() 
{
    // Array storing month names for display
    string monthNames[MONTHS] = {"January", "February", "March", "April", "May", "June", 
                                 "July", "August", "September", "October", "November", "December"};
    
    // Array to store monthly expenses
    double monthlyExpenses[MONTHS];

    // Input monthly expenses
    for (int i = 0; i < MONTHS; i++) 
    {
        while (true) 
        {
            cout << "Enter the amount spent on " << monthNames[i] << ": ";
            cin >> monthlyExpenses[i];

            // Check if the input failed (i.e., non-numeric input)
            if (cin.fail()) 
            {
                cin.clear(); // Reset the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            } 
            // Check for input under 0 and assume 0
            else if (monthlyExpenses[i] < 0) 
            {
                monthlyExpenses[i] = 0.0;
                break;
            } 
            else 
            {
                break; // Valid input
            }
        }
    }
    
    // Set default formatting for monetary values
    cout << fixed << setprecision(2);

    // Display each month's total expenses
    cout << "\nHere are the credit card totals for each month:" << endl << endl;
    for (int i = 0; i < MONTHS; i++) 
    {
        cout << setw(10) << left << monthNames[i] << " : $" << monthlyExpenses[i] << endl;
    }
    
    // Display summary statistics
    cout << "\nThe total amount of money spent was $" << totalAmount(monthlyExpenses, MONTHS) << endl;
    cout << "The average amount of money spent per month was $" << averageAmount(monthlyExpenses, MONTHS) << endl;
    cout << "The most amount of money spent in a month was $" << largestMonth(monthlyExpenses, MONTHS) << endl;
    cout << "The least amount of money spent in a month was $" << smallestMonth(monthlyExpenses, MONTHS) << endl;

    return 0;
}

// Function to calculate the total amount spent
double totalAmount(const double arr[], int size) 
{
    double total = 0.0;
    for (int i = 0; i < size; i++) 
    {
        total += arr[i]; // Summing all values in the array
    }
    return total;
}

// Function to calculate the average amount spent
double averageAmount(const double arr[], int size) 
{
    return totalAmount(arr, size) / size; // Compute total and divide by number of months
}

// Function to find the largest amount spent in a month
double largestMonth(const double arr[], int size) 
{
    double max = arr[0]; // Assume first month has the highest amount initially

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max) // Update max if a higher value is found
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the smallest amount spent in a month
double smallestMonth(const double arr[], int size) 
{
    double min = arr[0]; // Assume first month has the lowest amount initially

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < min) // Update min if a lower value is found
        {
            min = arr[i];
        }
    }
    return min;
}
