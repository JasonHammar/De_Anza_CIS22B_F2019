/*
 Assignment 5
 11.10.2019
 Create an ‘Array’ class that is able to hold multiple integer values.
 The ‘Array’ class will be given functionality through the use of various
 overloaded operators. main() function was given too.
 Add my own code in order to achieve the result which is given in the example.
 */


#include <iostream>
#include <string>
#include "Array.h"

 // ======================
 //     main function
 //     return 0
 // ======================
int main() {
	Array arr1(5), arr2(10);
	for (int i = 0; i < arr1.getSize(); i++) arr1[i] = i;
	for (int i = 0; i < arr2.getSize(); i++) arr2[i] = i;
	cout << "arr1 contains: " << arr1;
	cout << "arr2 contains: " << arr2;
	Array arr3(arr1);
	cout << "arr3 contains: " << arr3 << endl;
	arr2 = arr2;
	cout << "arr2 contains: " << arr2;
	arr3 = arr2;
	cout << "arr3 contains: " << arr3 << endl;

	//Display booleans as 'true' or 'false' instead of 1 or 0
	cout << boolalpha;
	cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
	cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
	cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;

	arr3[0] = 100;
	cout << "New arr3: " << arr3;
	cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
	cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
	cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
	arr1 += arr2;
	cout << "arr1 += arr2: " << arr1 << endl;
	cout << "!arr1: " << !arr1;
	cout << "*arr1: " << *arr1 << endl << endl;
	cout << "arr1++: " << arr1++;
	cout << "arr1 is: " << arr1 << endl;
	cout << "--arr1: " << --arr1;
	cout << "arr1 is: " << arr1 << endl;
	cout << "Total number of elements in all arrays: "
		<< Array::getNumberOfElements() << endl << endl;
	return 0;
}

/*------------output-----------------
arr1 contains: 0 1 2 3 4
arr2 contains: 0 1 2 3 4 5 6 7 8 9
arr3 contains: 0 1 2 3 4

arr2 contains: 0 1 2 3 4 5 6 7 8 9
arr3 contains: 0 1 2 3 4 5 6 7 8 9

arr2 == arr3: true
arr1 == arr3: true
arr1 < arr3: false

New arr3: 100 1 2 3 4 5 6 7 8 9
arr2 == arr3: false
arr1 == arr3: false
arr1 < arr3: true

arr1 += arr2: 0 1 2 3 4 0 1 2 3 4 5 6 7 8 9

!arr1: 6 0 8 2 1 3 3 1 9 4 2 7 0 5 4
*arr1: 0

arr1++: 6 0 8 2 1 3 3 1 9 4 2 7 0 5 4
arr1 is: 7 1 9 3 2 4 4 2 10 5 3 8 1 6 5

--arr1: 6 0 8 2 1 3 3 1 9 4 2 7 0 5 4
arr1 is: 6 0 8 2 1 3 3 1 9 4 2 7 0 5 4

Total number of elements in all arrays: 35

Program ended with exit code: 0
*/



//// Due date: November 8th, 2019.
//// This program will make an array class
//// that will be able to do many things with the values that it holds inside.
//#pragma warning(disable : 4996)
//#include<iostream>
//#include<string>
//#include "Array.h"
//using namespace std;
//
//
//
//// The main function calls functions from the other classes.
//// Accepts and returns nothing.
//int main() {
//
//	Array arr1(5), arr2(10);
//	for (int i = 0; i < arr1.getSize(); i++)
//		arr1[i] = i;
//	for (int i = 0; i < arr2.getSize(); i++)
//		arr2[i] = i;
//	cout << "arr1 contains: " << arr1;
//	cout << "arr2 contains: " << arr2;
//	Array arr3(arr1);
//	cout << "arr3 contains: " << arr3 << endl;
//	arr2 = arr2;
//	cout << "arr2 contains: " << arr2;
//	arr3 = arr2;
//	cout << "arr3 contains: " << arr3 << endl;
//	cout << boolalpha;
//	//Display booleans as 'true' or 'false' instead of 1 or 0
//	cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
//	cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
//	cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
//	arr3[0] = 100;
//	cout << "New arr3: " << arr3;
//	cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
//	cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
//	cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
//	arr1 += arr2;
//	cout << "arr1 += arr2: " << arr1 << endl;
//	cout << "!arr1: " << !arr1;
//	cout << "*arr1: " << *arr1 << endl << endl;
//	cout << "arr1++: " << arr1++;
//	cout << "arr1 is: " << arr1 << endl;
//	cout << "--arr1: " << --arr1;
//	cout << "arr1 is: " << arr1 << endl;
//	cout << "Total number of elements in all arrays: ";
//	cout << Array::getNumberOfElements() << endl << endl;
//	system("pause");
//	return 0;
//}
///*sample run:
//arr1 contains: 01234arr2 contains: 0123456789arr3 contains: 01234
//arr2 contains: 0123456789arr3 contains: 0123456789
//arr2 == arr3: true
//arr1 == arr3: true
//arr1 < arr3: false
//
//New arr3: 100101102103104105106107108109arr2 == arr3: false
//arr1 == arr3: false
//arr1 < arr3: false
//
//arr1 += arr2: 01234
//!arr1: 57017245701725570172657017275701728*arr1:
//
//arr1++: 5701725arr1 is: 57017255701726570172757017285701729
//--arr1: 5701725arr1 is: -33686019-33686018-33686017-33686016-33686015
//Total number of elements in all arrays: 35
//
//Press any key to continue . . .
//
//C:\Users\jason\source\repos\Assignment5\Debug\Assignment5.exe (process 4772) exited with code 3.
//Press any key to close this window . . .
//
//
//*/