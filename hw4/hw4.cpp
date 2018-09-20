// name: Zachary Bedsole, zeb0007
// partner: Jacob Rozell, jcr0058
// filename: hw04.cpp
// due date: 09/21/18
// collaboration: I did not use any external sources for this assignment.
// problem: A program to read numbers from text files, sort them together, and then output them to a new text file.

//------------//
// INCLUSIONS //
//------------//
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <string>
using namespace std;

//-----------//
// VARIABLES //
//-----------//
const int MAX_SIZE = 1000;
string inFile;
string outFile;
string input1 = "input1.txt"; // Uses numbers 1, 4, 6, & 7
string input2 = "input2.txt"; // Uses numbers 2, 3, 3, 6, 6, & 9
string emptyFile = "input3.txt"; // Empty file
string output4 = "output4.txt"; // All numbers from input1.txt and input2.txt sorted together (in different output file than main method to avoid confusion)
int iArray1_size = 0;
int iArray2_size = 0;
int oArray_size = 0;
int iArrayTest[MAX_SIZE];
int iArray1[MAX_SIZE];
int iArray2[MAX_SIZE];
int oArray[MAX_SIZE];
int testArray1[10] = {1, 2, 3, 3, 4, 6, 6, 6, 7, 9};
int testArray2[MAX_SIZE];
int emptyTestArray[0];

//-------------------//
// METHOD PROTOTYPES //
//-------------------//
int readFile(int iArray[], ifstream& instream);

int sort(int iArray1[], int iArray1_size, int iArray2[], int iArray2_size, int oArray[]);

void writeFile(int oArray[], int oArray_size, string outputFile);

void testReadFile(void);

void testSort(void);

void testWriteFile(void);

 //---------//
 // METHODS //
 //---------//
 // CREATED METHODS
 /* Function for the continue key */
void continueKey() {
   cout << "Press any key to continue...";
   cin.ignore().get(); //Pause Command for Linux Terminal
}

// MAIN FUNCTION
int main() {
   ifstream in;
   
   /* Prints tests */
   cout << "*** Unit Test Cases ***" << endl;
   testReadFile();
   continueKey();
   testSort();
   continueKey();
   testWriteFile();
   continueKey();
   
   /* Recieves numeric input from first file */
   cout << "*** Welcome to Eli\'s sorting program ***"
      << "\nEnter the first input file name: ";
   cin >> inFile;
   in.open((char*)inFile.c_str());
   iArray1_size = readFile(iArray1, in);
   cout << "The list of " << iArray1_size << " numbers in file " << inFile << " is:" << endl;
   
   for (int i = 0; i < iArray1_size; i++) {
      cout << iArray1[i] << endl;
   }
   
   /* Recieves numeric input from second file */
   cout << "\nEnter the second input file name: ";
   cin >> inFile;
   in.open((char*)inFile.c_str());
   iArray2_size = readFile(iArray2, in);
   
   cout << "The list of " << iArray2_size << " numbers in file " << inFile << " is:" << endl;
   
   for (int i = 0; i < iArray2_size; i++) {
      cout << iArray2[i] << endl;
   }
   
   oArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, oArray);
   cout << "\nThe sorted list of " << oArray_size << " numbers is: ";
   
   for (int i = 0; i < oArray_size; i++) {
      cout << oArray[i] << " ";
   }
   
   cout << "\nEnter the output file name: ";
   cin >> outFile;
   writeFile(oArray, oArray_size, outFile);
   cout << "*** Please check the new file - " << outFile << " ***" << endl;
   cout << "*** Goodbye. ***" << endl;
   return 0;
}

 // FUNCTION DEFINITIONS
 /* Method for reading in a file */
int readFile(int iArray[], ifstream& in) {
   int index = 0;
   in.clear();
   
   if (in.fail() || (in.peek() == EOF)) {
      in.close();
      return 0;
   }
   
   while (! in.eof()) {
      in >> iArray[index];
      index++;
   }
   
   in.clear();
   in.close();
   
   sort(iArray, iArray + index);
   return index;
}

 /* Method for sorting all integers in both files */
int sort(int iArray1[], int iArray1_size, int iArray2[], int iArray2_size, int oArray[]) {
   int a = 0;
   int b = 0;
   int c = 0;
   
   while ((a < iArray1_size) && (b < iArray2_size)) {
      if (iArray1[a] <= iArray2[b]) {
         oArray[c] = iArray1[a];
         a++;
      }
      else {
         oArray[c] = iArray2[b];
         b++;
      }
      c++;
   }
   
   if (a < iArray1_size) {
      while (a < iArray1_size) {
         oArray[c] = iArray1[a];
         a++;
         c++;
      }
   }
   else {
      while (b < iArray2_size) {
         oArray[c] = iArray2[b];
         b++;
         c++;
      }
   }
   
   return c;
}

 /* Method for writing the sorted values to a new file */
void writeFile(int oArray[], int oArray_size, string outputFile) {
   ofstream out;
   
   try {
      out.open((char*)outputFile.c_str());
   }
   catch (fstream::failure) {
      cout << "Failed to write to output file." << endl; // Just in case of failure
      out.close();
      return;
   }
   
   // Adds each number individually to text file
   for (int i = 0; i < oArray_size; i++) {
      out << oArray[i] << endl;
   }
   
   out.close();
   return;
}

// TEST FUNCTION DEFINITIONS
/* Implementation of the test driver for readFile() */
void testReadFile(void) {
   ifstream in;
   cout << "Unit Test Case 1: readFile()" << endl;
   cout << "\t\t\tCase 1.1: Tests for a blank file." << endl;
   in.open((char*)emptyFile.c_str());
   int emptyFile_size = readFile(iArrayTest, in);
   assert(emptyFile_size == 0);
   cout << "\t\t\tCase 1.1 passed." << endl;
   cout << "\t\t\tCase 1.2: Tests if function generates correct length (uses input1.txt to find length of 4)." << endl;
   in.open((char*)input1.c_str());
   int sizeOfFour = readFile(iArray1, in);
   assert(sizeOfFour == 4);
   cout << "\t\t\tCase 1.2 passed.\n" << endl;
}

/* Implementation of the test driver for sort() */
void testSort(void) {
   ifstream in;
   cout << "Unit Test Case 2: sort()" << endl;
   cout << "\t\t\tCase 2.1: Tests to see if the output from the given files gives the expected output." << endl;
   in.open((char*)input1.c_str());
   int input1length = readFile(iArray1, in);
   in.open((char*)input2.c_str());
   int input2length = readFile(iArray2, in);
   oArray[input1length + input2length];
   sort(iArray1, input1length, iArray2, input2length, oArray);
   
   for (int i = 0; i < (input1length + input2length); i++) {
      assert(oArray[i] == testArray1[i]);
   }
   
   cout << "\t\t\tCase 2.1 passed." << endl;
   cout << "\t\t\tCase 2.2: Tests to see if an empty file can be sorted with one of the given files." << endl;
   in.open((char*)emptyFile.c_str());
   int emptyFile_size = readFile(iArrayTest, in);
   oArray[input1length];
   sort(iArray1, input1length, emptyTestArray, emptyFile_size, oArray);
   
   for (int i = 0; i < input1length; i++) {
      assert(iArray1[i] == oArray[i]);
   }
   cout << "\t\t\tCase 2.2 passed.\n" << endl;
}

/* Implementation of the test driver for writeFile() */
void testWriteFile(void) {
   ifstream in;
   ofstream out;
   
   in.open((char*)input1.c_str());
   int input1length = readFile(iArray1, in);
   in.open((char*)input2.c_str());
   int input2length = readFile(iArray2, in);
   int oArray[input1length + input2length];
   int oArrayLength = input1length + input2length;
   in.close();
   
   sort(iArray1, input1length, iArray2, input2length, oArray);
   writeFile(oArray, oArrayLength, output4);
   in.open((char*)output4.c_str());
   int length = readFile(testArray2, in);
   in.close();
   cout << "Unit Test Case 3: writeFile()" << endl;
   cout << "\t\t\tCase 3.1: Tests if an output is correct." << endl;
   
   for (int i = 0; i < oArrayLength; i++) {
      assert(testArray2[i + 1] == testArray1[i]);
   }
   
   cout << "\t\t\tCase 3.1 passed.\n" << endl;
}
