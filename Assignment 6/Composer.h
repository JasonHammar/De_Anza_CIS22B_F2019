// Due Date: 11/26/2019
// This program will make a list of composers from a text file
// and then it will ask the user if they want to search for a composer,
// remove a composer, display the list of composers,
// or exit the program entirely.
#pragma once
#ifndef COMPOSER_H
#define COMPOSER_H
#include <string>
#include<fstream>
using namespace std;
// This class houses the prototypes that are defined in composer.cpp.
class Composer {
private:
	int size;
	string name;
	int death;
	string* ptr;
	int* pptr;
public:
	Composer();

	friend ostream& operator << (ostream& out, const Composer& comp);

	bool operator == (const Composer& comp) const;
	bool operator < (const Composer& comp) const;

	string getName()const;
	void setName(string nm);
	int getDeath()const;
	void setDeath(int det);
	int getSize()const;
	void createCompList(Composer& comp);

	~Composer();
};


#endif


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
