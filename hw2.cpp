// filename: hw02.cpp
// due date: 09/07/18
// collaboration: I did not use any external sources for this assignment.
// problem: determine how many months it will take to pay off a loan.

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

// variables
int num_of_months = 1;
double interestRate = -1;
double monthlyPayments;
double loanAmount;
double monthlyInterest;
double payment;
double principal;
double totalInterest;
double rate;

int main () {
   
   cout << "Loan Amount: ";
   cin >> loanAmount;
   
   while (interestRate < 0) {
      cout << "Interest Rate (% per year) : ";
      cin >> interestRate;
      if (interestRate < 0) {
         cout << "Interest Rate can't be less than 0." << endl;
      }
   }
   
   cout << "Monthly Payments: ";
   cin >> monthlyPayments;
   
   if (monthlyPayments < interestRate) {
      cout << "Error: monthly payment is less than interest." << endl;
      return 0;
   }
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "\n*******************************************************************" << endl;
   cout << "          Amortization Table" << endl;
   cout << "*******************************************************************" << endl;
   cout << left << setw(10) << "Month" << setw(10) << "Balance" << setw(10) << " Payment" << setw(10) << " Rate"
        << setw(10) << " Interest" << setw(10) << "  Principal" << endl;
   cout << left << setw(10) << "0" << "$" << setw(10) << loanAmount
        << setw(10) << "N/A" << setw(10) << "N/A" << setw(10) << "N/A" << setw(10) << " N/A" << endl;
   
   
   while (loanAmount > 0.0) {
      // assignment
      rate = (interestRate / 12);
      monthlyInterest = loanAmount * (rate * 0.01);
      principal = monthlyPayments - monthlyInterest;
      loanAmount = loanAmount - principal;
      monthlyInterest = roundf(monthlyInterest * 100) / 100;
      principal = roundf(principal * 100) / 100;
      
      // alignment
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);
      
      // statement
      cout << left << setw(10) << num_of_months << "$" << setw(10) << loanAmount << "$" << setw(9) << monthlyPayments << setw(10) << rate << "$" << setw(10) << monthlyInterest << "$" <<  setw(10) << principal << endl;
      
      // ensures balance doesn't become negative
      if (loanAmount < monthlyPayments) {
         monthlyInterest = loanAmount * (rate * 0.01);
         monthlyPayments = loanAmount + monthlyInterest;
         totalInterest += monthlyInterest; // increments in here as well to avoid error
      }
      totalInterest += monthlyInterest; // incrementing total interest             
      num_of_months++; // incrementing months
   }
   
   cout << "*******************************************************************\n";
   cout << "\nIt takes " << num_of_months - 1 << " months to pay off the loan." << endl;
   cout << "Total interest paid is: $" << totalInterest;
   
   return 0;
}
