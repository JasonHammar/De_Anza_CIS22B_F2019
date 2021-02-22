// Due Date: 11/26/2019
// This program will make a list of composers from a text file
// and then it will ask the user if they want to search for a composer,
// remove a composer, display the list of composers,
// or exit the program entirely.
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "Node.h"
#include "Composer.h"
using namespace std;

// The default constructor sets name to " " and death to 0.
// It accepts and returns nothing.
Composer::Composer() : name(" "), death(0) { }

// This method basically creates the composer object
// and gives the composer a name and date of death.
// It accepts a Composer and returns nothing.
void Composer::createCompList(Composer& comp) {
	ifstream infile;
	int count = 0;

	string obj;
	infile.open("composers.txt");
	if (!infile) {
		cout << "error!" << endl;
	}
	else {
		getline(infile, obj);



		int firstcomma = obj.find(',', 0);
		comp.setName(obj.substr(0, firstcomma));
		comp.setDeath(stoi(obj.substr(firstcomma + 2)));



	}
}



// This operator allows the name and date of death
// for the composer to be printed out.
// Accepts an ostream object and composer object
// and returns the ostream object.
ostream& operator<< (ostream& out, const Composer& comp) {
	out << comp.getName() << ", " << comp.getDeath() << endl;
	return out;
}

// This operator checks if the name of the composer objects are the same.
// Accepts a composer objects and returns true or false.
bool Composer::operator == (const Composer& comp) const {
	if (getName() == comp.getName())
		return true;
	return false;
}

// This operator checks if the death of a composer is earlier than another.
// It accepts a composer object and returns either true or false.
bool Composer::operator < (const Composer& comp) const {
	if (getDeath() < comp.getDeath())
		return true;
	return false;
}

// This method will get the name of the composer.
// Accepts nothing but returns the name.
string Composer::getName()const {
	return name;
}

// This method will set the name of the composer to what the user enters.
// It accepts a string but returns nothing.
void Composer::setName(string nm) {
	name = nm;
}
// This method will get the date of death of the composer.
// Accepts nothing but returns the date of death.
int Composer::getDeath()const {
	return death;
}

// This method will set the year of death to what the user enters.
// It accepts an int but returns nothing.
void Composer::setDeath(int det) {
	death = det;
}

// This method will get the size of the text file.
// Accepts nothing but returns the size.
int Composer::getSize()const {
	return size;
}
// The destructor cleans the heap, it accepts and returns nothing.
Composer::~Composer() {
	delete[] ptr;
	ptr = nullptr;
	delete[] pptr;
	pptr = nullptr;
}


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
