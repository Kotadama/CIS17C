#include <fstream>
#include <iostream>
using namespace std;

const int SIZE = 15;

// Function prototypes
void readPrices(ifstream &inFile, int prices[]);
void displayPrices(const int prices[], int size);

int main() 
{
  int prices[SIZE];
  ifstream inFile("prices.txt");

  if (!inFile) 
  {
    cout << "Error opening file prices.txt." << endl;
    return 1;
  }

  readPrices(inFile, prices);
  inFile.close();

  displayPrices(prices, SIZE);

  return 0;
}

void readPrices(ifstream &inFile, int prices[]) 
{
  for (int i = 0; i < SIZE; i++) {
    inFile >> prices[i];
  }
}

void displayPrices(const int prices[], int size) 
{
  cout << "The prices for the " << size << " rows are:" << endl;
  for (int i = 0; i < size; i++) {
    cout << "$" << prices[i] << endl;
  }
}
