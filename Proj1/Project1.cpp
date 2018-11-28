// filename: Project1.cpp
// due date: 11/09/18
// collaboration: I did not use any external sources for this assignment.
// problem: A simulated text adventure in which the user tries to get the highest score possible.

//------------//
// INCLUSIONS //
//------------//
#include <iostream>
#include <string>
#include <assert.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;


//-----------//
// VARIABLES //
//-----------//
typedef unsigned short ushort_t;
typedef string* stringPtr_t;
string input;
int noEventProbIn = 24;
int portalProbIn = 44;
int puzzleProbIn = 74;
int profProbIn = 86;
int tutorProbIn = 98;
int winProbIn = 99;


//---------//
// CLASSES //
//---------//
// HIGHSCORES CLASS
class HighScores {
   
   // Variables for HighScores:
   private:
   int iArray[10];
   int iArrayCopy[10];
   string sArray[10];
   string sArrayCopy[10];
   ushort_t score;
   string name;
   ifstream in;
   ofstream out;
   
   public:
   HighScores(string, ushort_t);
   
   /* Reads score files in from a file (HighScores.txt) */
   int readScoreFile() {
      int i = 0;
      in.open((char*)"HighScores.txt");
      if (in.fail() || (in.peek() == EOF)) {
         in.close();
         return 0;
      }
      while (!in.eof() && i < 10) {
         sArrayCopy[i] = sArray[i];
         iArrayCopy[i] = iArray[i];
         i++;
      }
      in.clear();
      in.close();
      return i; // length of arrays
   }
   
   /* Adds scores to list */
   void addScores(string nameIn, ushort_t scoreIn) {
      int i = readScoreFile();
      sArrayCopy[i] = nameIn;
      iArrayCopy[i] = scoreIn;
      sortScores();
   }
   
   /* Sorts given scores */
   void sortScores() {
      int tempI;
      string tempS;
      int i = readScoreFile();
      for (int j = 0; j < i; j++) {
         while (j > 0 && iArrayCopy[j] >= iArrayCopy[j - 1]) {
            tempI = iArrayCopy[j];
            tempS = sArrayCopy[j];
            iArrayCopy[j] = iArrayCopy[j - 1];
            sArrayCopy[j] = sArrayCopy[j - 1];
            iArrayCopy[j - 1] = tempI;
            sArrayCopy[j - 1] = tempS;
            j--;
         }
      }
   }
   
   /* Displays top 10 scores from file (HighScores.txt) when called from the main menu */
   void displayScores() {
      try {
         out.open((char*)"HighScores.txt");
      }
      catch (fstream::failure) {
         cout << "Failed to write to output file." << endl; // Just in case of failure
         out.close();
         return;
      }
      cout << "The top 10 High Scores are:\n" << endl;
      for (int i = 0; i < readScoreFile(); i++) {
         out << sArrayCopy[i] << " " << iArrayCopy[i] << endl;
      }
      if (readScoreFile() != 10) {
         cout << "-no more scores to show-\n" << endl;
      }
      out.close();
   }
 };
 
 // CHARACTER CLASS
class Character {
 
   // Variables for Character:
   private:
   ushort_t steps;
   ushort_t intelligence;
   ushort_t time;
   double money;
   
   public:
   Character(ushort_t, ushort_t, ushort_t, double);
   
   // Return steps:
   ushort_t getSteps() {
      return steps; 
   }
   
   // Set steps:
   void setSteps(ushort_t stepsIn) {
      steps = stepsIn;
   }
   
   // Return intelligence:
   ushort_t getIntelligence() {
      return intelligence; 
   }
   
   // Set intelligence:
   void setIntelligence(ushort_t intelligenceIn) {
      intelligence = intelligenceIn;
   } 
   
   // Return time:
   ushort_t getTime() {
      return time; 
   }
   
   // Set time:
   void setTime(ushort_t timeIn) {
      time = timeIn;
   }
   
   // Return Money:
   double getMoney() {
      return money; 
   }
   
   // Set money:
   void setMoney(double moneyIn) {
      money = moneyIn;
   }
   
   // Return attributes of the character:
   void viewCharacter() {
      cout << "\n\nYou have:\n" << endl;
      cout << "intelligence: " << getIntelligence() << "\ntime: " << getTime() << "\nmoney: $" << getMoney() << "\n" << endl;
   }
 };

// PUZZLE CLASS
class Puzzle {

   // Variables for Puzzle:
   private:
   int prob1;
   int prob2;
   int prob3;
   int prob4;
   int lastPuzzle;
   int testInput;
   
   public:
   Puzzle(int prob1In, int prob2In, int prob3In, int prob4In, int lastPuzzleIn, int testInputIn);
   
   // Runs when the first question method is chosen at random 
   void firstQuestion(Character& user) {
      int first;
      cout << "\nHow many species of bats (out of the 1200 known species) are actually blind? \n(Enter a whole number between 0 and 9): ";
      cin >> first;
      if (first == 0) {
         cout << "\nCorrect! Reward: +1 time & +1 intelligence" << endl;
         user.setTime(user.getTime() + 1);
         user.setIntelligence(user.getIntelligence() + 1);
      }
      else {
         cout << "\nIncorrect. Penalty: -1 time & -3 intelligence" << endl;
         user.setTime(user.getTime() - 1);
         user.setIntelligence(user.getIntelligence() - 3);
      }
   }
   
   // Runs when the second question method is chosen at random
   void secondQuestion(Character& user) {
      int second;
      cout << "\nHow many deadly sins are there? \n(Enter a whole number between 0 and 9): ";
      cin >> second;
      if (second == 7) {
         cout << "\nCorrect! Reward: +1 time" << endl;
         user.setTime(user.getTime() + 1);
      }
      else {
         cout << "\nIncorrect. Penalty: -1 time & -10 intelligence" << endl;
         user.setTime(user.getTime() - 1);
         user.setIntelligence(user.getIntelligence() - 10);
      }
   }
   
   // Runs when the third question method is chosen at random
   void thirdQuestion(Character& user) {
      int third;
      cout << "\nWhat percentage of people in the world have an outtie belly button? \n(Enter a whole number between 0 and 9): ";
      cin >> third;
      if (third == 4) {
         cout << "\nCorrect! Reward: +1 time & +2 intelligence" << endl;
         user.setTime(user.getTime() + 1);
         user.setIntelligence(user.getIntelligence() + 2);
      }
      else {
         cout << "\nIncorrect. Penalty: -1 time & -3 intelligence" << endl;
         user.setTime(user.getTime() - 1);
         user.setIntelligence(user.getIntelligence() - 3);
      }
   }
   
   // Runs when the fourth question method is chosen at random
   void fourthQuestion(Character& user) {
      int fourth;
      cout << "\nHow many bowel movements on average does a sloth have per week? \n(Enter a whole number between 0 and 9): ";
      cin >> fourth;
      if (fourth == 1) {
         cout << "\nCorrect! Reward: +1 time & +5 intelligence" << endl;
         user.setTime(user.getTime() + 1);
         user.setIntelligence(user.getIntelligence() + 5);
      }
      else {
         cout << "\nIncorrect. Penalty: -1 time & -5 intelligence" << endl;
         user.setTime(user.getTime() - 1);
         user.setIntelligence(user.getIntelligence() -5);
      }
   }
   
   // Runs when the fifth question method is chosen at random
   void fifthQuestion(Character& user) {
      int fifth;
      cout << "\nHow many people have been to the bottom of the ocean (the Marianna Trench)? \n(Enter a whole number between 0 and 9): ";
      cin >> fifth;
      if (fifth == 3) {
         cout << "\nCorrect! Reward: +1 time & +2 intelligence" << endl;
         user.setTime(user.getTime() + 1);
         user.setIntelligence(user.getIntelligence() + 2);
      }
      else {
         cout << "\nIncorrect. Penalty: -1 time & -3 intelligence" << endl;
         user.setTime(user.getTime() - 1);
         user.setIntelligence(user.getIntelligence() - 3);
      }
   }
   
   // Main selector method for deciding which puzzle to pick
   void selector(Character& user) {
   
      bool cont = true;
      while (cont) {
         int randNumb = rand()%100; // 0 to 100
         if (testInput > 0) {
            randNumb = testInput;
         }
         
         // (1) Q1
         // Random Number: 1-19
         if (randNumb <= prob1) {
         
            if (lastPuzzle == 1) {
               cont = true;
            }
            else {
               firstQuestion(user);
               cont = false;
               lastPuzzle = 1;
            }
         }
        
         // (2) Q2
         // Random Number: 20-39
         else if ((randNumb > prob1) && (randNumb <= prob2)) {
            
            if (lastPuzzle == 2) {
               cont = true;
            }
            else {
               secondQuestion(user);
               cont = false;
               lastPuzzle = 2;
            }
         }
         
         // (3) Q3
         // Random Number: 40-59
         else if ((randNumb > prob2) && (randNumb <= prob3))  {
         
            if (lastPuzzle == 3) {
               cont = true;
            }
            else {
               thirdQuestion(user);
               cont = false;
               lastPuzzle = 3;
            }
         }
         
         // (4) Q4
         // Random Number: 60-79
         else if ((randNumb > prob3) && (randNumb <= prob4))  {
         
            if (lastPuzzle == 4) {
               cont = true;
            }
            else {
               fourthQuestion(user);
               cont = false;
               lastPuzzle = 4;
            }
         }
         
         // (5) Q5
         // Random Number: 80-100
         else {
            if (lastPuzzle == 5) {
               cont = true;
            }
            else {
               fifthQuestion(user);
               cont = false;
               lastPuzzle = 5;
            }
         }
      }
   }
};

// MENU CLASS
class Menu {
   
   // Variables for Menu:
   private:
   ushort_t decision;
   string name;
   
   public:
   Menu(string nameIn);
   
   // Method to retrieve decision
   ushort_t getDecision() {
      return decision;
   }
   
   // Method to retrieve name 
   string getName() {
      return name;
   }
   
   // Method that runs the main menu with the 3 deliverable options; transfers control to different classes after input
   ushort_t mainMenu() {
      
      decision = 0;
      
      while (decision == 0 || decision > 3) {
         cout << "\n1) Start a New Game of Shelby Center and Dragons!\n2) View top 10 High Scores\n3) Quit" << endl;
         cout << "\n\tPlease choose an option: ";
         cin >> decision;
         
         // Error Check:
         if (decision == 0 || decision > 3) {
            cout << "\n\tPlease choose a valid option! The only valid inputs are 1, 2, & 3." << endl;
         }
         
         // Show high scores:
         if (decision == 2) {
            HighScores hS(input, 0);
            if (hS.readScoreFile() == 0) {
               cout << "There are no high scores yet! Press 1 to start the game and try to set a record for yourself." << endl;
               decision = 0;
            }
            else {
               hS.sortScores();
               hS.displayScores();
            }
         }
      }
      
      return decision;
   }
   };
   
 // QUIT CLASS
class Quit {
   
   // Variables for Quit Class:
   private:
   ushort_t decision;
   string name;
   string attributeName;
   ushort_t points;
   
   public:
   Quit(ushort_t decisionIn, string nameIn);
   Quit(ushort_t decisionIn, string nameIn, ushort_t points);
   Quit(ushort_t decisionIn, string nameIn, string attributeNameIn, ushort_t pointsIn);
   
   // Method for quitSystem logic:
   void quitSystem() {
      
      // Player quits:
      if (decision == 0) {
         cout << "\nCome back when you aren't afraid to discard 3 hours of your day!" << endl;
         exit(0);
      }
      
      // Player dies:
      if (decision == 1) {
         cout << "\n\t\t\t############" << endl;
         cout << "\t\t\t# YOU LOSE #" << endl;
         cout << "\t\t\t############" << endl;
         exit(0);
      }
      
      // Player gets an attribute to zero and loses:
      if (decision == 2) {
         cout << "\nYou hit zero points on your " << attributeName << " attribute! Try again if you think you're good enough." << endl;
         exit(0);
      }
      
      // Player wins:
      if (decision == 3) {
         cout << "\nYou achieved a score of " << points << " points, congratulations! Check the Top 10 High Scores list to see if you made it!" << endl;
         HighScores hS(name, points);
         hS.addScores(name, points);
         exit(0);
      }
   }
};

// ENCOUNTERS CLASS
class Encounters {

   // Variables for Encounters:
   private:
   int noEventProb;
   int portalProb;
   int puzzleProb;
   int profProb;
   int tutorProb;
   int winProb;
   string name;
   int lastEncounter;
   int testInput;
   
   public:
   Encounters(int tutorProbIn, int portalProbIn, int puzzleProbIn, int noEventProbIn, int profProbIn, int winProbIn, int lastEncounter, string nameIn, int testInputIn);
   
   // Runs when the noEvent method is chosen at random
   void noEvent(Character& user) {
      cout << "\nYou move forward one step, and...\nNOTHING HAPPENS!\n" << endl;
      user.setSteps(user.getSteps() - 1);
      user.setTime(user.getTime() - 1);
   }
   
   // Runs when the portal method is chosen at random
   void portal(Character& user) {
      int randNumb2 = rand()%5 + 1; // (1 to 5) Used for increasing or decreasing time attribute
      int randNumb3 = rand()%2; // (0 to 2) Used for selecting which version of portal user will recieve
      
      if (randNumb3 == 1) {
         cout << "\nYou move forward one step, and...\nYOU ARE SUCKED THROUGH A PORTAL AND YOU HAVE LOST TIME!\n" << endl;
         user.setTime(user.getTime() - randNumb2);
         user.setSteps(user.getSteps() - 2);
      }
      else {
         cout << "\nYou move forward one step, and...\nYOU ARE SUCKED THROUGH A PORTAL AND YOU HAVE GAINED TIME!\n" << endl;
         user.setTime(user.getTime() + randNumb2);
         user.setSteps(user.getSteps() - 2);
      }
      
   }
   
   // Runs when the puzzle method is chosen at random (TRANSFERS CONTROL TO PUZZLE CLASS)
   void puzzle(Character& user) {
      cout << "\nYou move forward one step and...\nYOU RUN INTO A PUZZLE THAT MUST BE SOLVED\n" << endl;
      Puzzle puzzleQuestions(19,39,59,79,0,0);
      puzzleQuestions.selector(user);
      user.setSteps(user.getSteps() - 1);
   }
   
   // Runs when the prof method is chosen at random
   void prof(Character& user) {
      cout << "\nYou move forward one step and...\nYOU RUN INTO A BORING PROFESSOR GIVING A LECTURE!\n" << endl;
      int randNumb2 = rand()%5 + 1;
      user.setSteps(user.getSteps() - 1);
      user.setTime(user.getTime() - 1);
      user.setIntelligence(user.getIntelligence() - randNumb2);
      cout << "\nYou lose " << randNumb2 << " intelligence!\n";
   }
   
   // Runs when the tutor method is chosen at random 
   void tutor(Character& user) {
      cout << "\nYou move forward one step and...\nYOU RUN INTO A NEEDY KID THAT NEEDS CASH FOR TUTORING!\n" << endl;
      double randNumb2 = rand()%5 + 1;
      user.setSteps(user.getSteps() - 1);
      user.setTime(user.getTime() - 1);
      user.setMoney(user.getMoney() - randNumb2);
      cout << "\nYou lose " << randNumb2 << " money!\n";
   }
   
   // Runs when the immediate win method is chosen at random
   void win(Character& user) {
      cout << "\nYou move forward one step and...\nYOU FIND A WINNING LOTTERY \nTICKET ON THE GROUND AND DROP OUT OF COLLEGE TO PURSUE YOUR DREAM OF BECOMING A FAMOUS RAPPER!\n" << endl;
      int randNumb2 = rand()%5 + 1;
      user.setSteps(0);
      ushort_t score = user.getIntelligence() * ((ushort_t)user.getMoney()) * user.getTime();
      Quit winGame(3, name, NULL, score);
      winGame.quitSystem();
   }
   
   // Runs when the immediate win method is chosen at random and in the test version
   void winTest(Character& user) {
      cout << "\nYou move forward one step and...\nYOU FIND A WINNING LOTTERY \nTICKET ON THE GROUND AND DROP OUT OF COLLEGE TO PURSUE YOUR DREAM OF BECOMING A FAMOUS RAPPER!\n" << endl;
      int randNumb2 = rand()%5 + 1;
      user.setSteps(0);
      ushort_t score = user.getIntelligence() * ((ushort_t)user.getMoney()) * user.getTime();
   }
   
   // Main selector method for deciding which encounter to pick
   void selector(Character& user) {
      
      // tutor, portal, puzzle, noEvent, prof, win
      
      /* Tutor: (0-9)
         Portal: (10-19)
         Puzzle: (20-35)
         No event (36-40)
         Prof: (41-49)
         Win: (50) */
     
      bool cont = true;
      
      while (cont) {
         int randNumb = rand()%100; // 0 to 50
         if (testInput > 0) {
            randNumb = testInput;
         }
         
         // Tutor (1):
         // Range: 0-9
         // Prob: 20%
         if ((randNumb <= tutorProb) && cont != false) {
         
            if (lastEncounter == 1) {
               cont = true;
            }
            else {
               tutor(user);
               cont = false;
               lastEncounter = 1;
            }
         }
         
         // Portal (2):
         // Range: 10-19
         // Prob: 20%
         if ( ((randNumb > tutorProb) && (randNumb <= portalProb)) && cont != false) {
            
            if (lastEncounter == 2) {
               cont = true;
            }
            else {
               portal(user);
               cont = false;
               lastEncounter = 2;
            }
         }
         
         // Puzzle (3):
         // Range 20-35:
         // Prob: 30%
         else if ( ((randNumb > portalProb) && (randNumb <= puzzleProb)) && cont != false) {
         
            if (lastEncounter == 3) {
               cont = true;
            }
            else {
               puzzle(user);
               cont = false;
               lastEncounter = 3;
            }
         }
         
         // No Event (4):
         // Range 36-40:
         // Prob: 10%
         else if ( ((randNumb > puzzleProb) && (randNumb <= noEventProb)) && cont != false) {
         
            if (lastEncounter == 4) {
               cont = true;
            }
            else {
               noEvent(user);
               cont = false;
               lastEncounter = 4;
            }
         }
         
         // Professor (5):
         // Range: 41-49
         // Prob: 18%
         else if ( ((randNumb > noEventProb) && (randNumb <= profProb)) && cont != false) {
         
            if (lastEncounter == 5) {
               cont = true;
            }
            else {
               prof(user);
               cont = false;
               lastEncounter = 5;
            }
         }
         
         // Win Lottery (6):
         // Range 50
         // Prob: 1%
         else if (randNumb == winProb) {
            win(user);
            cont = false;
            lastEncounter = 6;
         }
       }
   }
};

// SYSTEM CLASS (driver for most of program)
class System {

   // Variables for System:
   private:
   double chance;
   string name;
   ushort_t steps;
   ushort_t score;
   ushort_t intelligence;
   ushort_t money;
   ushort_t time;
   
   public:
   System(string nameIn);
   
   // Method that runs entire system
   ushort_t runSystem() {
      
      // Default action to 1:
      ushort_t action = 1;
      
      // Init other variables:
      int randNumb = rand()%5 + 1;
      Quit quitProgram2(1, name);
      steps = intelligence = money = 20;
      time = 50;
      
      // Create the character:
      Character onlyChar(20, 20, 50, 20);
      Encounters encounterGenerator(9, 19, 35, 40, 49, 50, 0, name, 0);
      
      // Display entry:
      cout << "\nEntering the Game...\n" << endl;
      cout.precision(2);
      
      // Enter main game loop:
      while (onlyChar.getSteps() != 0) {
         cout << "You are " << onlyChar.getSteps() << " steps from the goal. Time left: " << onlyChar.getTime() << ".\n" << endl;
         cout << "\t\t\t1) Move forward (takes time, could be risky...)" << endl;
         cout << "\t\t\t2) Read technical papers (boost intelligence, takes time)" << endl;
         cout << "\t\t\t3) Search for loose change (boost money, takes time)" << endl;
         cout << "\t\t\t4) View character" << endl;
         cout << "\t\t\t5) Quit the game" << endl;
         cout << "\n\t\tPlease choose an action: ";
         cin >> action; 
         
         char switchAction = 'Z';
         if (action == 1) {
            switchAction = 'A'; // Random encounter:
         }
         if (action == 2) {
            switchAction = 'B'; // Technical Papers: (textbook)?
         }
         if (action == 3) {
            switchAction = 'C'; // Search for loose change:
         }
         if (action == 4) {
            switchAction = 'D'; // View Character:
         }
         if (action == 5) {
            switchAction = 'E'; // Quit:
         }
         
         switch(switchAction) {
         
            // Run random encounter:
            case 'A' :
               encounterGenerator.selector(onlyChar);
               break;
               
            // Read techincal papers (time -1) (intelligence +)
            case 'B' :
               onlyChar.setTime(onlyChar.getTime() - 1);
               onlyChar.setIntelligence(onlyChar.getIntelligence() + randNumb);
               cout << "\nYou read through some technical papers. You gain " << randNumb << " intelligence, but \nlose 1 unit of time.\n" << endl;
               break;
               
            // Search for loose change (time -1) (money +)
            case 'C' :
               onlyChar.setTime(onlyChar.getTime() - 1);
               onlyChar.setMoney(onlyChar.getMoney() + randNumb);
               cout << "\nYou search in your pockets for loose change. You gain $" << randNumb << ", but \nlose 1 unit of time.\n" << endl;
               break;
              
            // View Character:
            case 'D' :
               onlyChar.viewCharacter();
               break;
               
            // Quit:
            case 'E' :
               quitProgram2.quitSystem();
               break;
               
            // invalid Input / Loop back through:
            default :
               cout << "\n\tPlease choose a number between 1 and 5!" << endl;
         }
         
         // If any stats are 0 or less, quit game, show "You lose" text:
         if (onlyChar.getIntelligence() <= 0) {
            Quit quitProgram3(2, input, "Intelligence", 0);
            quitProgram3.quitSystem();
         }
         else if (onlyChar.getMoney() <= 0) {
            Quit quitProgram3(2, input, "Money", 0);
            quitProgram3.quitSystem();
         }
         else if (onlyChar.getTime() <= 0) {
            Quit quitProgram3(2, input, "Time", 0);
            quitProgram3.quitSystem();
         }
      }
      return score = onlyChar.getIntelligence() * ((ushort_t)onlyChar.getMoney()) * onlyChar.getTime();
      
   }
   
};


//--------//
// METHOD //
//--------//
// MAIN METHOD
int main() {

   #define UNIT_TESTING
   
   #ifdef UNIT_TESTING
   
   cout << "----------START OF TESTING----------" << endl;
   
   //---------- TEST FOR PLAYER CLASS ----------
   
   cout << "\n------PLAYER CLASS TESTING-----" << endl;
   
   Character testChar(20, 20, 50, 20);
   
   cout << "\nPlayer Test 1: Check getSteps() and setSteps()" << endl;
   testChar.setSteps(10);
   cout << "Should return 10 -> " << testChar.getSteps() << endl;;
   
   cout << "\nPlayer Test 2: Check getIntelligence() and setIntelligence()" << endl;
   testChar.setIntelligence(10);
   cout << "Should return 10 -> " << testChar.getIntelligence() << endl;
   
   cout << "\nPlayer Test 3: Check getTime() and setTime()" << endl;
   testChar.setTime(10);
   cout << "Should return 10 -> " << testChar.getTime() << endl;
   
   cout << "\nPlayer Test 4: Check getMoney() and setMoney()" << endl;
   testChar.setMoney(10);
   cout << "Should return 10 -> " << testChar.getMoney() << endl;
   
   cout << "\nPlayer Test 5: Check viewCharacter()" << endl;
   cout << "Should cout information about the character (10/10/10) -> " << endl;
   testChar.viewCharacter();
   
   
    //---------- TEST FOR PUZZLE CLASS ----------
   cout << "\n------PUZZLE CLASS TESTING-----" << endl;
   Puzzle puzzleTest(19,39,59,79,0,0);
   
   // First Question Test
   cout << "\nPuzzle Test 1: Check firstQuestion() with wrong answer (enter 6)" << endl;
   puzzleTest.firstQuestion(testChar);
   
   cout << "\nPuzzle Test 2: Check firstQuestion() with right answer (enter 0)" << endl;
   puzzleTest.firstQuestion(testChar);
   
   // Second Question Test
   cout << "\nPuzzle Test 3: Check secondQuestion() with wrong answer (enter 6)" << endl;
   puzzleTest.secondQuestion(testChar);
   
   cout << "\nPuzzle Test 4: Check secondQuestion() with right answer (enter 7)" << endl;
   puzzleTest.secondQuestion(testChar);
   
   // Third Question Test
   cout << "\nPuzzle Test 5: Check thirdQuestion() with wrong answer (enter 6)" << endl;
   puzzleTest.thirdQuestion(testChar);
   
   cout << "\nPuzzle Test 6: Check thirdQuestion() with right answer (enter 4)" << endl;
   puzzleTest.thirdQuestion(testChar);
   
   // Fourth Question Test
   cout << "\nPuzzle Test 7: Check fourthQuestion() with wrong answer (enter 6)" << endl;
   puzzleTest.fourthQuestion(testChar);
   
   cout << "\nPuzzle Test 8: Check fourthQuestion() with right answer (enter 1)" << endl;
   puzzleTest.fourthQuestion(testChar);
   
   // Fifth Question Test
   cout << "\nPuzzle Test 9: Check fifthQuestion() with wrong answer (enter 6)" << endl;
   puzzleTest.fifthQuestion(testChar);
   
   cout << "\nPuzzle Test 10: Check fifthQuestion() with right answer (enter 3)" << endl;
   puzzleTest.fifthQuestion(testChar);
   
   // Test Selector
   cout << "\nPuzzle Test 11: Selector method picks a random method" << endl;
   puzzleTest.selector(testChar);

   cout << "\nPuzzle Test 12: Selector method picks a random method" << endl;
   puzzleTest.selector(testChar);
   
   
   //---------- TEST FOR ENCOUNTER CLASS ----------
   cout << "\n------ENCOUNTER CLASS TESTING-----" << endl;
   
   Encounters eTest(9, 19, 35, 40, 49, 50, 0, "NAME", 0);
   
   cout << "\nEncounter Test 1: noEvent() -> nothing happens" << endl;
   eTest.noEvent(testChar);
   
   cout << "\nEncounter Test 2: portal() -> portal opens" << endl;
   eTest.portal(testChar);
   
   cout << "\nEncounter Test 3: puzzle() -> asks a random puzzle" << endl;
   eTest.puzzle(testChar);
   
   cout << "\nEncounter Test 4: prof() -> boring professor" << endl;
   eTest.prof(testChar);
   
   cout << "\nEncounter Test 5: tutor() -> needy kid needs money" << endl;
   eTest.tutor(testChar);
   
   cout << "\nEncounter Test 6: win() -> win lottery and drop out" << endl;
   eTest.winTest(testChar);
   
   cout << "\nEncounter Test 7: selector() -> picks a random encounter" << endl;
   eTest.selector(testChar);
   

    //---------- TEST FOR HIGHSCORES CLASS ----------
   cout << "\n------HIGHSCORES CLASS TESTING-----" << endl;
   
   HighScores hsTest("TESTER1", 100);
   
   cout << "\nHighscores Test 1: add scores to a file using addScores() -> TESTER1 100" << endl;
   hsTest.addScores("TESTER1", 100);

   cout << "\nHighscores Test 2: read the file and get the scores" << endl;
   int fucku = hsTest.readScoreFile();
   cout << fucku << endl;
   assert(hsTest.readScoreFile() == 2);
   
   cout << "\nHighscores Test 3: display the scores added using displayScores" << endl;
   hsTest.displayScores();
   return 0;
   
   #else

   // Feed a random seed to the rand() function:
      srand( time(NULL) );

   // Get name of player:
   cout << "\tWhat's your name? ";
   getline(cin, input);
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   
   // Dispay welcome message:
   cout << setw(10) << "\n\n\t=================================================" << endl;
   cout << "\t|" << setw(25) << "Welcome, " << input << "!" << setw(22 - input.length()) << "|" << endl;
   cout << setw(10) << "\t=================================================" << endl;
   
   // Create the menu:
   Menu onlyMenu(input);
   ushort_t choice = onlyMenu.mainMenu();
   
   // Quit:
   if (choice == 3) {
      Quit quitProgram(0, input, NULL, 0);
      quitProgram.quitSystem();
   }
   
   // Run game (from system):
   if (choice == 1) {
      System onlySystem(input);
      ushort_t finalScore = onlySystem.runSystem();
      Quit quitProgram(3, input, finalScore);
      if (finalScore > 0) {
         quitProgram.quitSystem();
      }
   }
   return 0;
   #endif
}

//--------------//
// CONSTRUCTORS //
//--------------//
// CONSTRUCTOR FOR MENU CLASS
Menu::Menu(string nameIn) : name(nameIn) {}

// CONSTRUCTOR FOR SYSTEM CLASS
System::System(string nameIn) : name(nameIn) {}

// CONSTRUCTOR FOR HIGHSCORES CLASS
HighScores::HighScores(string nameIn, ushort_t scoreIn) : name(nameIn), score(scoreIn) {}

// CONSTRUCTOR FOR ENCOUNTERS CLASS WITH 8 PARAMETERS
Encounters::Encounters(int tutorProbIn, int portalProbIn, int puzzleProbIn, int noEventProbIn, int profProbIn, int winProbIn, int lastEncounter, string nameIn, int testInputIn) : noEventProb(noEventProbIn), portalProb(portalProbIn), puzzleProb(puzzleProbIn), profProb(profProbIn), tutorProb(tutorProbIn), winProb(winProbIn), name(nameIn), testInput(testInputIn) {}

// CONSTRUCTOR FOR CHARACTER CLASS
Character::Character(ushort_t stepsIn, ushort_t intelligenceIn, ushort_t timeIn, double moneyIn) : steps(stepsIn), intelligence(intelligenceIn), time(timeIn), money(moneyIn) {}

// CONSTRUCTOR FOR QUIT CLASS WITH ONE PARAMETER
Quit::Quit(ushort_t decisionIn, string nameIn) : decision(decisionIn), name(nameIn) {}

// CONSTRUCTOR FOR QUIT CLASS WITH TWO PARAMETERS
Quit::Quit(ushort_t decisionIn, string nameIn, ushort_t pointsIn) : decision(decisionIn), name(nameIn), points(pointsIn) {}

// CONSTRUCTOR FOR QUIT CLASS WITH THREE PARAMETERS
Quit::Quit(ushort_t decisionIn, string nameIn, string attributeNameIn, ushort_t pointsIn) : decision(decisionIn), name(nameIn), attributeName(attributeNameIn), points(pointsIn) {}

// CONSTRUCTOR FOR PUZZLE CLASS WITH SIX PARAMETERS
Puzzle::Puzzle(int prob1In, int prob2In, int prob3In, int prob4In, int lastPuzzleIn, int testInputIn) : prob1(prob1In), prob2(prob2In), prob3(prob3In), prob4(prob4In), testInput(testInputIn) {}
