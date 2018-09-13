// filename: hw03.cpp
// due date: 09/14/18
// collaboration: I did not use any external sources for this assignment.
// problem: A program to simulate the Puzzlevania duel between Aaron, Bob, and Charlie.

//------------//
// INCLUSIONS //
//------------//
# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
# include <cstdlib>
using namespace std;

//-----------//
// VARIABLES //
//-----------//
const int aaronProb = 33;
const int bobProb = 50;
const int TOTAL_RUNS = 10000;
const string PRINTDIVIDE = "/10000";
int aWinCount1;
int aWinCount2;
int bWinCount1;
int bWinCount2;
int cWinCount1;
int cWinCount2;
int num2;
int num1;
bool A_Alive;
bool B_Alive;
bool C_Alive;
bool True = true;
bool False = false;
string target;

//---------------------//
// FUNCTION PROTOTYPES //
//---------------------//
// METHOD PROTOTYPES
/* at_least_two_alive() function prototype */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
      /* Input: A_alive indicates whether Aaron is alive */
      /* B_alive indicates whether Bob is alive */
      /* C_alive indicates whether Charlie is alive */
      /* Return: true if at least two are alive */
      /* otherwise return false */

/* Aaron_shoots1() function prototype */
void Aaron_shoots1(bool& B_alive, bool& C_alive);
      /* Strategy 1: Use call by reference
      * Input: B_alive indicates whether Bob alive or dead
      * C_alive indicates whether Charlie is alive or dead
      * Return: Change B_alive into false if Bob is killed.
      * Change C_alive into false if Charlie is killed.
      */
      
/* Bob_shoots() function prototype */
void Bob_shoots(bool& A_alive, bool& C_alive);
      /* Call by reference
      * Input: A_alive indicates if Aaron is alive or dead
      * C_alive indicates whether Charlie is alive or dead
      * Return: Change A_alive into false if Aaron is killed.
      * Change C_alive into false if Charlie is killed.
      */

/* Charlie_shoots() function prototype */     
void Charlie_shoots(bool& A_alive, bool& B_alive);
      /* Call by reference
      * Input: A_alive indicates if Aaron is alive or dead
      * B_alive indicates whether Bob is alive or dead
      * Return: Change A_alive into false if Aaron is killed.
      * Change B_alive into false if Bob is killed.
      */
/* Aaron_shoots2() function prototype */      
void Aaron_shoots2(bool& B_alive, bool& C_alive);
      /* Strategy 2: Use call by reference
      * Input: B_alive indicates whether Bob alive or dead
      * C_alive indicates whether Charlie is alive or dead
      * Return: Change B_alive into false if Bob is killed.
      *         Change C_alive into false if Charlie is killed.
      */

// TEST METHOD PROTOTYPES
void test_at_least_two_alive(void);
 /* This is a test driver for at_least_two_alive() */

void test_Aaron_shoots1(void);
 /* This is a test driver for Aaron_shoots() */

void test_Bob_shoots(void);
 /* This is a test driver for Bob_shoots() */
 
void test_Charlie_shoots(void);
 /* This is a test driver for Charlie_shoots() */
 
void test_Aaron_shoots2(void);
 /* This is a test driver for Aaron_shoots2() */
 
 //---------//
 // METHODS //
 //---------//
 // CREATED METHODS
 /* Function for the continue key */
void continueKey() {
   cout << "Press any key to continue...";
   cin.ignore().get(); //Pause Command for Linux Terminal
}

/* Strategy 1 Driver */
void strategy1Driver() {
   cout << "Ready to test strategy 1 (run " << TOTAL_RUNS << " times):" << endl;
   continueKey();
   
   for (int i = 0; i < TOTAL_RUNS; i++) {
      A_Alive = B_Alive = C_Alive = true;
      do {
         if (A_Alive) {
            Aaron_shoots1(B_Alive, C_Alive);
         }
         if (B_Alive) {
            Bob_shoots(A_Alive, C_Alive);
         }
         if (C_Alive) {
            Charlie_shoots(A_Alive, B_Alive);
         }
      } while (at_least_two_alive(A_Alive, B_Alive, C_Alive));
      if (A_Alive) {
         aWinCount1 += 1;
      }
      if (B_Alive) {
         bWinCount1 += 1;
      }
      if (C_Alive) {
         cWinCount1 += 1;
      }
      cout << "\n";
   }
   double percentageA = aWinCount1 * 0.01;
   double percentageB = bWinCount1 * 0.01;
   double percentageC = cWinCount1 * 0.01;
   cout << "Aaron won " << aWinCount1 << PRINTDIVIDE << " duels or " << percentageA << "%";
   cout << "\nBob won " << bWinCount1 << PRINTDIVIDE << " duels or " << percentageB << "%";
   cout << "\nCharlie won " << cWinCount1 << PRINTDIVIDE << " duels or " << percentageC << "%";
}

/* Strategy 2 Driver */
void strategy2Driver() {
   cout << "\n\nReady to test strategy 2 (run " << TOTAL_RUNS << " times):" << endl;
   continueKey();
   
   for (int i = 0; i < TOTAL_RUNS; i++) {
      A_Alive = B_Alive = C_Alive = true;
      do {
         if (A_Alive) {
            Aaron_shoots2(B_Alive, C_Alive);
         }
         if (B_Alive) {
            Bob_shoots(A_Alive, C_Alive);
         }
         if (C_Alive) {
            Charlie_shoots(A_Alive, B_Alive);
         }
      } while (at_least_two_alive(A_Alive, B_Alive, C_Alive));
      if (A_Alive) {
         aWinCount2 += 1;
      }
      if (B_Alive) {
         bWinCount2 += 1;
      }
      if (C_Alive) {
         cWinCount2 += 1;
      }
      cout << "\n";
   }
   double percentageA = aWinCount2 * 0.01;
   double percentageB = bWinCount2 * 0.01;
   double percentageC = cWinCount2 * 0.01;
   cout << "Aaron won " << aWinCount2 << PRINTDIVIDE << " duels or " << percentageA << "%";
   cout << "\nBob won " << bWinCount2 << PRINTDIVIDE << " duels or " << percentageB << "%";
   cout << "\nCharlie won " << cWinCount2 << PRINTDIVIDE << " duels or " << percentageC << "%";
   
   if (aWinCount2 > aWinCount1) {
      num2 = 2;
      num1 = 1;
   }
   else if (aWinCount2 == aWinCount1) {
      cout << "\n\nStrategy 2 is equal to strategy 1." << endl;
      return;
   }
   else {
      num2 = 1;
      num1 = 2;
   }
   cout << "\n\nStrategy " << num2 << " is better than strategy " << num1 << "." << endl;
}

// MAIN METHOD
int main() {
   srand((unsigned)time(0));
   cout << "*** Welcome to Puzzlevania's Duel Simulator ***" << endl;
   test_at_least_two_alive();
   test_Aaron_shoots1();
   test_Bob_shoots();
   test_Charlie_shoots();
   test_Aaron_shoots2();
   strategy1Driver();
   strategy2Driver();
}

// FUNCTION DEFINITIONS
/* Implementation of at_least_two_alive() */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   int count = 0;
   
   if (A_alive) {
      count++;
   }
   if (B_alive) {
      count++;
   }
   if (C_alive) {
      count++;
   }
   
   if (count > 1) {
      return true;
   } 
   else { 
      return false;
   }
}

 /* Implementation of Aaron_shoots1() */
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   B_Alive = B_alive;
   C_Alive = C_alive;
   int randomNumb = rand()%100;
   
   if (C_Alive) {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Bob";
      target = "Bob";
   }
   
   if (randomNumb <= aaronProb) {
      cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         C_Alive = false;
         return;
      }
      else {
         B_Alive = false;
         return;
      }
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron misses.\n";
      return;
   }
}
 
 /* Implementation of Bob_shoots() */
void Bob_shoots(bool& A_alive, bool& C_alive) {
   A_Alive = A_alive;
   C_Alive = C_alive;
   int randomNumb = rand()%100;
   
   if (C_Alive) {
      cout << "\n\t\t\t\t\t\tBob is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\t\t\t\t\tBob is shooting at Aaron";
      target = "Aaron";
   }
   
   if (randomNumb <= bobProb) {
      cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         C_Alive = false;
      }
      else {
         A_Alive = false;
      }
   }
   else {
      cout << "\n\t\t\t\t\t\tBob misses.\n";
   }
}
 
 /* Implementation of Charlie_shoots() */
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   A_Alive = A_alive;
   B_Alive = B_alive;
   
   if (B_Alive) {
      cout << "\n\t\t\t\t\t\tCharlie is shooting at Bob";
      B_Alive = false;
      target = "Bob";
   }
   else {
      cout << "\n\t\t\t\t\t\tCharlie is shooting at Aaron";
      A_Alive = false;
      target = "Aaron";
   }
   cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
}
 
 /* Implementation of Aaron_shoots2() */
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   B_Alive = B_alive;
   C_Alive = C_alive;
   int randomNumb = rand()%100;
   
   if ((B_Alive == true) && (C_Alive == true)) {
      cout << "\n\t\t\t\t\t\tAaron intentionally misses his first shot" << endl;
      cout << "\t\t\t\t\t\tBoth Bob and Charlie are alive." << endl;
      return;
   }
   
   if (C_Alive) {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Bob";
      target = "Bob";
   }
   
   if (randomNumb <= aaronProb) {
      cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         C_Alive = false;
         return;
      }
      else {
         B_Alive = false;
         return;
      }
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron misses.\n";
      return;
   }
}

// TEST FUNCTION DEFINITIONS
/* Implementation of the test driver for at_least_two_alive() */
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\t\t\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\t\t\tCase passed ...\n";
   continueKey();
}

 /* Implementation of the test driver for Aaron_shoots1() */
void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   cout << "\t\t\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots1(True, True);
   cout << "\t\t\tCase 2: Bob dead, Charlie alive";
   Aaron_shoots1(False, True);
   cout << "\t\t\tCase 3: Bob alive, Charlie dead";
   Aaron_shoots1(True, False);
   continueKey();
}

/* Implementation of the test driver for Bob_shoots() */
void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   cout << "\t\t\tCase 1: Aaron alive, Charlie alive";
   Bob_shoots(True, True);
   cout << "\t\t\tCase 2: Aaron dead, Charlie alive";
   Bob_shoots(False, True);
   cout << "\t\t\tCase 3: Aaron alive, Charlie dead";
   Bob_shoots(True, False);
   continueKey();
}
 
 /* Implementation of the test driver for Charlie_shoots() */
void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   cout << "\t\t\tCase 1: Aaron alive, Bob alive";
   Charlie_shoots(True, True);
   cout << "\t\t\tCase 2: Aaron dead, Bob alive";
   Charlie_shoots(False, True);
   cout << "\t\t\tCase 3: Aaron alive, Bob dead";
   Charlie_shoots(True, False);
   continueKey();
}
 
 /* Implementation of the test driver for Aaron_shoots2() */
void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   cout << "\t\t\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots2(True, True);
   cout << "\t\t\tCase 2: Bob dead, Charlie alive";
   Aaron_shoots2(False, True);
   cout << "\t\t\tCase 3: Bob alive, Charlie dead";
   Aaron_shoots2(True, False);
   continueKey();
}
