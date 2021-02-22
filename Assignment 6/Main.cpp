// Due Date: 11/26/2019
// This program will make a list of composers from a text file
// and then it will ask the user if they want to search for a composer,
// remove a composer, display the list of composers,
// or exit the program entirely.
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "Composer.h"
#include "Node.h"
using namespace std;

// The main function will prompt the user to enter whether they want to
// search for a name, remove a name, display the list or exit.
// It will also insert the composer objects into the linked list.
// It accepts nothing and returns 0.
int main() {
	ifstream infile;


	int count = 0;

	string obj;
	infile.open("composers.txt");
	if (!infile) {
		cout << "error!" << endl;
	}
	else {
		while (getline(infile, obj)) {


			count++;
		}
	}

	int size = count;
	string* ptr = new string[size];
	int* pptr = new int[size];
	infile.close();
	infile.open("composers.txt");
	int i = 0;
	string obj2;
	while (getline(infile, obj2)) {
		int firstcomma = obj2.find(',', 0);
		*(ptr + i) = obj2.substr(0, firstcomma);
		*(pptr + i) = stoi(obj2.substr(firstcomma + 2));
		i++;
	}
	infile.close();


	Composer comp;
	Composer* compPtr = new Composer[size];
	LinkedList<Composer> link;
	infile.open("composers.txt");

	for (int i = 0; i < size; i++) {
		comp.setName(*(ptr + i));
		comp.setDeath(*(pptr + i));
		link.insert(comp);
		*(compPtr + i) = comp;

	}



	int j = 0;
	string name;
	char choice;
	while (true) {
		cout << "Enter 's' to search, 'r' to remove,";
		cout << "'d' to display, or 'e' to exit : " << endl;

		cin >> choice;
		cin.ignore(256, '\n');
		if (choice == 'r') {
			cout << "Enter the composer's name to remove." << endl;

			getline(cin, name);

			while (j < size) {
				if (name == compPtr[j].getName()) {
					if (link.remove(compPtr[j])) {
						cout << compPtr[j].getName();
						cout << " was successfully removed from the list.";
						cout << endl;
						j = 0;
					}

					break;
				}
				j++;
				if (j == size) {
					j = 0;
					cout << name << " was not found in the list";
					cout << " while attempting to remove." << endl;
					break;
				}
			}
		}
		else if (choice == 's') {
			cout << "Enter the composer's name to search for." << endl;

			getline(cin, name);

			while (j < size) {
				if (name == compPtr[j].getName()) {
					if (link.find(compPtr[j])) {
						cout << compPtr[j].getName();
						cout << " was successfully found.";
						cout << endl;
						j = 0;
					}
					else {
						j = 0;
						cout << name << " has already bean removed." << endl;
					}
					break;
				}
				j++;
				if (j == size) {
					j = 0;
					cout << name << " was not found in the list." << endl;
					break;
				}
			}
		}
		else if (choice == 'd')
			link.printList();
		else if (choice == 'e') {
			cout << "Thank you and goodbye!" << endl;
			break;
		}
		else
			cout << "Incorrect entry, try again!" << endl;

	}
	
	return 0;
}
// This is the default constructor for the linked list class,
// it sets header to nullptr.
// doesn't accept or return arguments.
template<class T>
LinkedList<T>::LinkedList() : header(nullptr) {}

// This is the linked list destructor, it will clean the heap,
// doesn't accept or return arguments.
template<class T>
LinkedList<T>::~LinkedList() {

	delete header;
	delete last;
	header = nullptr;
	last = nullptr;
}
template class LinkedList <int>;

// This method will print the contents of the linked list to the users screen.
// It will not accept nor return any arguments.
template<class T>
void LinkedList<T>::printList()const {
	Node <T>* iter = header;

	while (iter != NULL) {
		cout << iter->data;
		iter = iter->link;
	}
}
template class LinkedList <int>;

// This function will add a node to the end of the linked list.
// It will accept a T value but won't return anything.
template<class T>
void LinkedList<T>::append(const T data) {

	Node <T>* temp = new Node<T>;
	temp->data = data;

	temp->link = nullptr;
	if (header == nullptr)
		header = temp;
	else {
		Node<T>* iter = header;
		while (iter->link != nullptr) {

			iter = iter->link;

		}
		iter->link = temp;
	}
}
template class LinkedList<int>;

// This method will add a node to the beginning of the linked list.
// It will accept a T value but won't return anything.
template<class T>
void LinkedList<T>::prepend(const T data) {
	Node<T>* temp = new Node<T>(data);
	temp->link = header;

	header = temp;
}
template class LinkedList<int>;

// This method will remove the node at the very front of the linked list.
// It will not accept any arguments but it will return header as null.
template<class T>
bool LinkedList<T>::removeFront() {
	if (header == nullptr)
		return nullptr;
	Node<T>* temp = header;
	header = header->link;
	delete temp;
	return header;
}
template class LinkedList<int>;

// This method will insert the nodes in numerical order
// by the composers death date.
// It accepts a T value but it will not return anything.
template <class T>
void LinkedList<T>::insert(const T data) {



	Node<T>* iter = header, * prev = nullptr;
	Node<T>* temp = new Node<T>(data);
	if (isEmpty()) {
		header = last = temp;
		return;
	}

	while (iter != nullptr && iter->data < data) {
		prev = iter;
		iter = iter->link;
	}
	if (prev == nullptr) { // (iter == header)
		prepend(data);
	}
	else if (iter == nullptr) {
		append(data);

	}
	else {
		prev->link = temp;
		temp->link = iter;
	}




}
template class LinkedList <int>;

// This method will remove a node of the users choice
// by entering the name of the composer.
// It will accept a T value and return either true or false;
template<class T>
bool LinkedList<T>::remove(const T data) {

	if (data == header->data) {
		return removeFront();
	}

	Node<T>* iter = header, * prev = nullptr;

	while (iter != nullptr) {
		prev = iter;
		iter = iter->link;
		if (data == iter->data) {

			Node<T>* temp = iter;
			prev->link = iter->link;
			delete temp;
			temp->link = iter;
			return true;
		}


	}
	return false;
}
template class LinkedList <int>;

// This method will find the object the user enters in the linked list.
// It will accept a T value and return either true or false.
template<class T>
bool LinkedList<T>::find(const T data) {
	Node<T>* iter = header;
	while (iter != nullptr) {
		if (data == iter->data)
			return true;
		iter = iter->link;
	}
	return false;
}
template class LinkedList <int>;

// This method will check whether or not the linked list is empty.
// It accepts nothing but returns true or false.
template<class T>
bool LinkedList<T>::isEmpty()const {
	if (header == nullptr)
		return true;
	return false;
}
template class LinkedList <int>;

// This method will get the first node in the list.
// This method accepts nothing but returns the first node in the linked list.
template<class T>
T LinkedList<T>::getFirst()const {
	return header->data;
}
template class LinkedList <int>;

// This method will get the last node in the list.
// This method accepts nothing but returns the last node in the linked list.
template<class T>
T LinkedList<T>::getLast()const {
	Node<T>* iter = header;

	while (iter->link != nullptr) {

		iter = iter->link;
	}

	return iter->data;
}
template class LinkedList <int>;


/*
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
s
Enter the composer's name to search for.
Giuseppe Verdi
Giuseppe Verdi was successfully found.
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
d
Claudio Monteverdi, 1643
Henry Purcell, 1695
Antonio Vivaldi, 1741
Johann Sebastian Bach, 1750
George Frideric Handel, 1759
Wolfgang Amadeus Mozart, 1791
Joseph Haydn, 1809
Ludwig van Beethoven, 1827
Franz Schubert, 1828
Felix Mendelssohn, 1847
Frederic Chopin, 1849
Robert Schumann, 1856
Hector Berlioz, 1869
Richard Wagner, 1883
Franz Liszt, 1886
Pyotr Ilyich Tchaikovsky, 1893
Johannes Brahms, 1897
Giuseppe Verdi, 1901
Antonin Dvorak, 1904
Edvard Grieg, 1907
Gustav Mahler, 1911
Claude Debussy, 1918
Camille Saint-Saens, 1921
Giacomo Puccini, 1924
George Gershwin, 1937
Maurice Ravel, 1937
Sergei Rachmaninoff, 1943
Bela Bartok, 1945
Arnold Schoenberg, 1951
Sergei Prokofiev, 1953
Igor Stravinsky, 1971
Dmitri Shostakovich, 1975
Leonard Bernstein, 1990
Aaron Copland, 1990
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
r
Enter the composer's name to remove.
Aaron Copland
Aaron Copland was successfully removed from the list.
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
r
Enter the composer's name to remove.
Henry Purcell
Henry Purcell was successfully removed from the list.
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
d
Claudio Monteverdi, 1643
Antonio Vivaldi, 1741
Johann Sebastian Bach, 1750
George Frideric Handel, 1759
Wolfgang Amadeus Mozart, 1791
Joseph Haydn, 1809
Ludwig van Beethoven, 1827
Franz Schubert, 1828
Felix Mendelssohn, 1847
Frederic Chopin, 1849
Robert Schumann, 1856
Hector Berlioz, 1869
Richard Wagner, 1883
Franz Liszt, 1886
Pyotr Ilyich Tchaikovsky, 1893
Johannes Brahms, 1897
Giuseppe Verdi, 1901
Antonin Dvorak, 1904
Edvard Grieg, 1907
Gustav Mahler, 1911
Claude Debussy, 1918
Camille Saint-Saens, 1921
Giacomo Puccini, 1924
George Gershwin, 1937
Maurice Ravel, 1937
Sergei Rachmaninoff, 1943
Bela Bartok, 1945
Arnold Schoenberg, 1951
Sergei Prokofiev, 1953
Igor Stravinsky, 1971
Dmitri Shostakovich, 1975
Leonard Bernstein, 1990
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
s
Enter the composer's name to search for.
Gary Franz
Gary Franz was not found in the list.
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
r
Enter the composer's name to remove.
Sergey Profokiev
Sergey Profokiev was not found in the list while attempting to remove.
Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit :
e
Thank you and goodbye!

C:\Users\jason\source\repos\Assignment6\Debug\Assignment6.exe
(process 14668) exited with code 0.
Press any key to close this window . . .
*/


