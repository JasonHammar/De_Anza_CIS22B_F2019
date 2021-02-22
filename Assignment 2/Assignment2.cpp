#include<iostream>
#include<string>
// This function will ask for the user to input student data,
// which is the student names,
// number of tests each student took, and their scores on each test.
// Due Date: October 11th, 2019
using namespace std;
// function protoypes.
int inputData(string*&, double**&);
void displayData(string*, double**, int);
void cleanHeap(string*, double**, int);
// Main function calls all of the functions.
int main() {
	string* strPtr;
	double** dblPtr;
	int val = 0;
	// Asks the user to input student data.
	int stuNum = inputData(strPtr, dblPtr);
	// Displays the student data.
	displayData(strPtr, dblPtr, stuNum);
	// Cleans the heap.
	cleanHeap(strPtr, dblPtr, stuNum);
	system("pause");
}


// InputData function will ask the user to input the student data,
// which is the number of students,
// the names of each student,
// how many tests each student took, and their grade for each test.
// This function recieves a string pointer and a double pointer
// pointing to an array of doubles.
// At the end it will return the number of students.
// In addition, this function will also validate the user's input.
int inputData(string*& strPtr, double**& dblPtr) {
	int stuNum = 0;
	int numTests;
	string stuName;
	double scores;
	cout << "How many students are in the system?" << endl;
	cin >> stuNum;
	if (stuNum < 0) {
		while (stuNum < 0) {
			cout << "Please give a positive number ";
			cout << "for the number of students." << endl;
			cin >> stuNum;
		}
	}
	
	strPtr = new string[stuNum];

	dblPtr = new double* [stuNum];
	for (int i = 0; i < stuNum; i++) {
		cout << "What is the full name of student " << i + 1 << endl;
		cin.ignore();
		getline(cin, stuName);
		*(strPtr + i) = stuName;

		cout << "How many tests did " << stuName << " take?" << endl;
		cin >> numTests;
		if (numTests < 0) {
			while (numTests < 0) {
				cout << "Please give a positive number ";
				cout << "for the number of tests" << endl;
				cin >> numTests;
			}
		}

		*(dblPtr + i) = new double[numTests + 1];
		*(*(dblPtr + i) + 0) = numTests;


		for (int j = 1; j < numTests + 1; j++) {

			cout << "Please enter the score for test " << j << endl;
			cin >> scores;
			if (scores < 0 || scores > 100) {
				while (scores < 0 || scores > 100) {
					cout << "Please give a score greater than 0";
					cout << " but less than 100." << endl;
					cin >> scores;
				}
			}
			*(*(dblPtr + i) + j) = scores;
			
		}
	}

	return stuNum;
}


// This function will display the data for each student that the
// user has entered, that data being the students name,
// number of tests taken, grades for each student, and the number of students.
// This function recieves a string pointer and a double pointer
// pointing to an array of doubles. It also recieves the number of students.
// This function will not return anything.
void displayData(string* strPtr, double** dblPtr, int stuNum) {
	cout << "You have " << stuNum << " students in the system." << endl;
	for (int i = 0; i < stuNum; i++) {
		cout << "Name of Student: " << *(strPtr + i) << endl;

		for (int j = 1; j < *(*(dblPtr + i) + 0) + 1; j++) {
			cout << "Score for test " << j << ": " << *(*(dblPtr + i) + j);
			cout << endl;
		}
	}
}
// This function will clean the heap of
// anything that was dynamically allocated.
// This function recieves a string pointer and a double pointer
// pointing to an array of doubles. It also recieves the numer of students.
// This function will not return anything.
void cleanHeap(string* strPtr, double** dblPtr, int stuNum) {
	double scores;
	
		for (int i = stuNum; i > 0; i--) {
			for (int j = *(*(dblPtr + i) + 0); j > 0; j--) {
				delete[] * (dblPtr + j);
			}
			delete[](strPtr + i);
		}
		delete[] dblPtr;
		delete[] strPtr;
}

/*Sample Run:

How many students are in the system?
-19
Please give a positive number for the number of students.
3
What is the full name of student 1
John Smith
How many tests did John Smith take?
4
Please enter the score for test 1
123
Please give a score greater than 0 but less than 100.
100
Please enter the score for test 2
45.7
Please enter the score for test 3
100.5
Please give a score greater than 0 but less than 100.
87.54
Please enter the score for test 4
96.2
What is the full name of student 2
Tyler Tony
How many tests did Tyler Tony take?
-9
Please give a positive number for the number of tests
3
Please enter the score for test 1
45.76
Please enter the score for test 2
0
Please enter the score for test 3
98.67
What is the full name of student 3
Peter Parker
How many tests did Peter Parker take?
4
Please enter the score for test 1
-6
Please give a score greater than 0 but less than 100.
67.67
Please enter the score for test 2
-98.7
Please give a score greater than 0 but less than 100.
54
Please enter the score for test 3
98.7
Please enter the score for test 4
78.34
You have 3 students in the system.
Name of Student: John Smith
Score for test 1: 100
Score for test 2: 45.7
Score for test 3: 87.54
Score for test 4: 96.2
Name of Student: Tyler Tony
Score for test 1: 45.76
Score for test 2: 0
Score for test 3: 98.67
Name of Student: Peter Parker
Score for test 1: 67.67
Score for test 2: 54
Score for test 3: 98.7
Score for test 4: 78.34

C:\Users\jason\source\repos\Assignment2\
Debug\Assignment2.exe (process 16024) exited with code -1073741819.
Press any key to close this window . . .
*/
