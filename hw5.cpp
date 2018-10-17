// filename: hw05.cpp
// due date: 10/05/18
// collaboration: I did not use any external sources for this assignment.
// problem: A program that simulates a trivia game with user input.

#include <iostream>
#include <string>
using namespace std;

#define UNIT_TESTING

// Constants:
const string devoloper = "CENSORED";
int nodeCount = 0;

// Create structure for TriviaNode:
struct TriviaNode {
   string question;
   string answer;
   unsigned int points;
   TriviaNode* nextNode;
};

// Make new type that is a pointer type to a TriviaNode structure:
typedef TriviaNode* triviaNodePtr;
triviaNodePtr head;

// Init methods:
triviaNodePtr initTriviaNode(triviaNodePtr &head);
triviaNodePtr addNode(string questionIn, string ansIn, int pointsIn, triviaNodePtr &lastNode);
void game();
void test();

// Implement the main method:
int main() {
   // ----------------------- Testing -------------------------------------------------
   #ifdef UNIT_TESTING
      test();
      
   #else
   // ----------------------- Start Main Game -------------------------------------------------
   // Variables needed for main():
   bool cont = true;
   int whileCount = 0;

   triviaNodePtr currentNode = new TriviaNode;
   // Init triviaNode with 3 questions and put the last one into lastNode:
   triviaNodePtr lastNode = initTriviaNode(head);
   
   // Cout welcome message:
   cout << "*** Welcome to " << devoloper << "'s trivia quiz game ***" << endl;
   
   // Populate the TriviaNode linkedList:
   while (cont) {
      string stringCon = "";
      string question;
      string answer;
      int points;
      
      // Prompt user to enter question and save it into the node:
      cout << "Enter a question: ";
      getline(cin, question);

      // Prompt user to enter answer to question and save it into node:
      cout << "Enter an answer: ";
      getline(cin, answer);
 
      // Prompt user to enter award points and save it into node:
      cout << "Enter award points: ";
      cin >> points;  
      cin.clear();
      cin.ignore(100000,'\n'); 
      
      // Add the node to the chain of LinkedList:
      currentNode = addNode(question, answer, points, lastNode);
      
      // Check to see if the user wants to keep going:
      cout << "Continue (Yes/No): ";
      cin >> stringCon;
      cin.clear();
      cin.ignore(10000,'\n');
      
      // User enters "no", we point last node to NULL:
      if(stringCon == "no" || stringCon == "No") {
        cont = false;
      }
      
      // User enters "yes", we set current node equal the previous and continue:
      else if(stringCon == "yes" || stringCon == "Yes") {
         cont = true;
      }
      
      // The last node is going to now equal the currentNode:
      lastNode = currentNode;
      
      // Reached end of while loop so increment count:
      whileCount++;       
   }
   
   // Play some trivia!
   game();   
   
   #endif
   return 0;
}

// Implement the game:
void game() {
// Init variables that will be used in the game:
   string answer;
   int totalPoints = 0;
   
   // Start game:
   while (true) {
      // Print question to cout:
      cout << "Question: " << head->question << endl;
      
      // Prompt user to enter answer:
      cout << "Answer: ";
      getline(cin, answer);
      cin.clear();

      // Check answer and assign points:
      if (answer.compare(head->answer) == 0) {
         cout << "Your answer is correct. You recieve " << head->points << " points." << endl;
         totalPoints += head->points;
      }
      else {
         cout << "Your answer is wrong. The correct answer is: " << head->answer << endl;
      }  
      
      // Print total points to cout:
      cout << "Your total points: " << totalPoints << endl;

      // Check to see if there is another node:
      if (head->nextNode == NULL) {
         cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
         break;
      }
      else {
         // Step into the next Node:
         head = head->nextNode;
      }
   }
}

// Init the linked list with the first three questions:
triviaNodePtr initTriviaNode(triviaNodePtr &head) {
   triviaNodePtr node1 = new TriviaNode();
   triviaNodePtr node2 = new TriviaNode();
   head = new TriviaNode();
   
   // head node:
   head->question = "How long was the shortest war on record? (Hint: how many minutes)";
   head->answer = "38";
   head->points = 100;
   head->nextNode = node1;
   nodeCount++;
   
   // first node:
   node1->question = "What was Bank of America's orignal name? (Hint: Bank of Italy or Bank of Germany)";
   node1->answer = "Bank of Italy";
   node1->points = 50;
   node1->nextNode = node2;
   nodeCount++;
   
   // second node:
   node2->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
   node2->answer = "Wii Sports";
   node2->points = 20;
   node2->nextNode = NULL;
   nodeCount++;
   
   // return last node
   return node2;
   
}

// add node:
triviaNodePtr addNode(string questionIn, string ansIn, int pointsIn, triviaNodePtr &lastNode) {
   // Create new node:
   triviaNodePtr newNode = new TriviaNode;
   newNode->question = questionIn;
   newNode->answer = ansIn;
   newNode->points = pointsIn;
   nodeCount++;
   
   // Point the last node to the new node:
   lastNode->nextNode = newNode;
   
   // Return the newNode/last node in the linked list:
   return newNode;
   
}

void test() {
   
   cout << "*** This is a debugging version *** " << endl;
   
   // Case 1:
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
   cout << "Warning - The number of trivia to be asked must equal to or larger than 1.\n" << endl;
   
   // Case 2:
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester \nenters an incorrect answer." << endl;
   triviaNodePtr currentNode = new TriviaNode;
   triviaNodePtr lastNode = initTriviaNode(head);
   
   




}
