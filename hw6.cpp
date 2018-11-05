// filename: hw06.cpp
// due date: 10/19/18
// collaboration: I did not use any external sources for this assignment.
// problem: A program to store patient and doctor info.

//------------//
// INCLUSIONS //
//------------//
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


//-----------//
// VARIABLES //
//-----------//
typedef unsigned short ushort_t;
typedef string* stringPtr_t;
int n = 0;


//-------//
// CLASS //
//-------//
class Doctor {
   private:
   ushort_t numPatients;
   ushort_t patientArraySize;
   string doctorName;
   stringPtr_t patientList;
   public:
   Doctor();
   Doctor(string nameInput);
   Doctor(ushort_t patientArrayCapacity);
   Doctor(string nameInput, ushort_t patientArrayCapacity);
   ~Doctor() { delete [] patientList; }
   bool addPatient(string patientName);
   string displayPatientArray();
   void resizePatientArray(ushort_t newArraySize); 
   Doctor& operator =(const Doctor& docSource);
   string getDoctorName() const {
      return doctorName;
   }
      
   ushort_t getNumOfPatient() const {
      return numPatients;
   }
   
   ushort_t getArraySize() const {
      return patientArraySize;
   }
      
   void setDoctorName(string docName) {
      doctorName.assign(docName);
   }
   
   void emptyPatientArray() {
      numPatients = 0;
      patientList = NULL;
      patientArraySize = 0;
   }
};


//---------//
// METHODS //
//---------//
// MAIN METHOD
int main() {

   #define UNIT_TESTING
   
   #ifdef UNIT_TESTING
   
   Doctor testDoc("default name", 100);
   cout << "Case 1: Tests if a doctor's name can be changed." << endl;
   cout << "\t\tCase 1.1: Tests if the default doctor name can be received with the getDoctorName() method." << endl;
   assert((testDoc.getDoctorName() == "default name") == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 1.2: Tests if the default doctor name can be set to something else with setDoctorName() method." << endl;
   testDoc.setDoctorName("correct name");
   assert((testDoc.getDoctorName() == "correct name") == true);
   cout << "\t\tCase passed..." << endl;
   cout << "Case 2: Tests if the number of patients can be modified." << endl;
   cout << "\t\tCase 2.1: Tests if number of patients can be received with getNumOfPatient()." << endl;
   assert((testDoc.getNumOfPatient() == 0) == true);
   testDoc.addPatient("Bob Dinkleheimer");
   assert((testDoc.getNumOfPatient() == 1) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 2.2: Tests if number of patients can be cleared to 0 with emptyPatientArray()." << endl;
   testDoc.emptyPatientArray();
   assert((testDoc.getNumOfPatient() == 0) == true);
   assert((testDoc.getArraySize() == 0) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "Case 3: Tests if the array size can be modified." << endl;
   cout << "\t\tCase 3.1: Tests if array size is correct with getArraySize()." << endl;
   Doctor testDoc2(100);
   assert((testDoc2.getArraySize() == 100) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 3.2: Tests if array can be resized with resizePatientArray()." << endl;
   testDoc2.resizePatientArray(44);
   assert((testDoc2.getArraySize() == 44) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 3.3: Tests if names in the patient array can be displayed with displayPatientArray()." << endl;
   testDoc2.addPatient("smitty werbenjegermanjensen");
   assert((testDoc2.displayPatientArray() == "smitty werbenjegermanjensen ") == true);
   cout << "\t\tCase passed..." << endl;
   cout << "Case 4: Tests to see if all 4 constructors work properly." << endl;
   cout << "\t\tCase 4.1: Tests Doctor() (no params)." << endl;
   Doctor testDoc3;
   assert((testDoc3.getDoctorName() == "Need a name.") == true);
   assert((testDoc3.getArraySize() == 0) == true);
   assert((testDoc3.getNumOfPatient() == 0) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 4.2: Tests Doctor(string nameInput) (only accepts doctor name)." << endl;
   Doctor testDoc4("bob jones");
   assert((testDoc4.getDoctorName() == "bob jones") == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 4.3: Tests Doctor(ushort_t patientArrayCapacity) (only accepts array capacity)." << endl;
   Doctor testDoc5(200);
   assert((testDoc5.getArraySize() == 200) == true);
   assert((testDoc5.getNumOfPatient() == 0) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 4.4: Tests Doctor(string nameInput, ushort_t patientArrayCapacity) (accepts doctor name and array capacity)." << endl;
   Doctor testDoc6("dingleberry smith", 999);
   assert((testDoc6.getDoctorName() == "dingleberry smith") == true);
   assert((testDoc6.getArraySize() == 999) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "Case 5: Tests to see if overloaded assignment operator works correctly by assigning testDoc6 to testDoc5." << endl;
   testDoc6.addPatient("random guy");
   testDoc5 = testDoc6;
   cout << "\t\tCase 5.1: Tests if testDoc5 has the correct array size after assignment." << endl;
   assert((testDoc5.getArraySize() == 999) == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 5.2: Tests if testDoc5 has the correct doctor name after assignment." << endl;
   assert((testDoc5.getDoctorName() == "dingleberry smith") == true);
   cout << "\t\tCase passed..." << endl;
   cout << "\t\tCase 5.3: Tests if testDoc5 has the correct number of patients after assignment." << endl;
   assert((testDoc5.getNumOfPatient() == 1) == true);
   cout << "\t\tCase passed..." << endl;
   
   cout << "\nAll tests passed, methods are fully functional." << endl;
    
   return 0;
   
   #else
   string docName;
   string patientName;
   string input;
   ushort_t listSize;
   cout << "*** Welcome to the product version that we have just been informed to make the day before our assignment is due!!! ***" << endl;
   cout << "Please enter the name of the doctor: ";
   getline(cin, docName);
   cout << "Please enter a number for how many patients will be entered into the system: ";
   cin >> listSize;
      
   Doctor newDoc(docName, listSize);
   int i = 0;
   while (i < newDoc.getArraySize()) {
      cout << "\nName of new patient: ";
      cin >> patientName;
      newDoc.addPatient(patientName);
      cout << "Do you need to alter how many patients will be entered into the system? (Enter Y/N): ";
      cin >> input;
      if (input == "Y" || input == "y") {
         ushort_t numb = 0;
         while (numb <= newDoc.getNumOfPatient()) {
            cout << "Enter number for how many patients will be entered (must be greater than the amount of patients already entered): ";
            cin >> numb;
            if (numb <= newDoc.getNumOfPatient()) {
               cout <<"Invalid! Must be greater than the amount of patients already entered." << endl;
            }
         }
         newDoc.resizePatientArray(numb);
      }
      cout << "Display current list of patients? (Enter Y/N): ";
      cin >> input;
      if (input == "Y" || input == "y") {
         cout << newDoc.displayPatientArray() << endl;
      }
      i++;
   }
      
   cout << "\nYou have entered " << newDoc.getNumOfPatient() << " patient(s) into the system under the care of " << newDoc.getDoctorName() << "." << endl;
   cout << "Is this correct? Enter Y for yes or N to clear all patients from the system (WARNING: You will have to run the program again to store more patients!): ";
   cin >> input;
   if (input == "N" || input == "n") {
      newDoc.emptyPatientArray();
      cout << "\n*** Patient list has been cleared. Thank you for using the product version. Goodbye! ***" << endl;
      return 0;
   }
   cout << "\n*** The patient list has been successfully created. Thank you for using the product version. Goodbye! ***" << endl;
   return 0;
   #endif
   
} 

// FUNCTION DEFINITIONS
/* Function for adding a patient to the patient list. */
bool Doctor::addPatient(string patientName) {
   patientList[n] = patientName;
   if (patientList[n] == patientName) {
      numPatients++;
      n++;
      return true;
   }
   return false;
}

/* Function for displaying every patient in the array. */
string Doctor::displayPatientArray() {
   string result;
   for (int i = 0; i < patientArraySize; ++i) {
      result += patientList[i];
      if (patientList[i] != "") {
         result += " ";
      }
   }
   return result;
}

/* Function for resizing the patient array. */
void Doctor::resizePatientArray(ushort_t newArraySize) {
   stringPtr_t newPatientList = new string[newArraySize];
   std::copy(patientList, patientList + std::min(patientArraySize, newArraySize), newPatientList);
   delete[] patientList;
   patientList = newPatientList;
   patientArraySize = newArraySize;
} 

/* Function for overloading the assignment operator. */
Doctor& Doctor::operator =(const Doctor& docSource) {
   if (this != &docSource) {
      delete [] patientList;
      patientList = new string[strlen((const char*)docSource.patientList)+1];
      strcpy((char*)patientList, (const char*)docSource.patientList);
      patientArraySize = docSource.patientArraySize;
      numPatients = docSource.numPatients;
      doctorName = docSource.doctorName;
   }
   return *this;
}


//--------------//
// CONSTRUCTORS //
//--------------//
// CONSTRUCTOR WITH NO PARAMETERS
Doctor::Doctor() : doctorName("Need a name."), patientArraySize(0), patientList(NULL) {
   numPatients = 0;
}
 
// CONSTRUCTOR WITH NAME INPUT PARAMETER
Doctor::Doctor(string nameInput) : doctorName(nameInput) {
   
}

// CONSTRUCTOR WITH ARRAY CAPACITY INPUT PARAMETER
Doctor::Doctor(ushort_t patientArrayCapacity) : patientArraySize(patientArrayCapacity) {
   patientList = new string[patientArraySize];
   numPatients = 0;
}

// CONSTRUCTOR WITH BOTH NAME INPUT AND ARRAY CAPACITY INPUT PARAMETERS
Doctor::Doctor(string nameInput, ushort_t patientArrayCapacity) : doctorName(nameInput), patientArraySize(patientArrayCapacity) { 
   patientList = new string[patientArraySize];
   numPatients = 0;
}
