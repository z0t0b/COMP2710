// filename: hw01.cpp
// due date: 08/31/18
// collaboration: I did not use any external sources for this assignment.
// problem: determine how much diet soda it is possible to drink without dying as a result.

#include <iostream>
using namespace std;
using namespace ceil;

// variables
const double RATIO = 0.001;
int mouseWeight, dieterWeight;
double sweetenerAmt, num_of_soda;

int main () {
   cout << "What is the amount of artifical sweetener needed to kill a mouse: ";
   cin >> sweetenerAmt;
   
   cout << "\nWhat is the weight of the mouse: ";
   cin >> mouseWeight;
   
   cout << "\nWhat is the weight that the dieter will be happy with: ";
   cin >> dieterWeight;
   
   num_of_soda = (sweetenerAmt / mouseWeight) * (dieterWeight / RATIO);
   
   cout << "\nYou can drink " << num_of_soda << " diet soda without dying as a result.";
   
   return 0;
}
