#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<locale>
// Due Date: 10/18/2019
// This program will save the user's favorite movies
// into a database/playlist for them to reference.
using namespace std;
// Movie struct.
struct Movie {
	string title;
	double totalGross;
	string director;
	string releaseDate;
	int runTime;
};

// function Prototypes.
int numberOfLines(ifstream&);
void populateMovieFromFile(ifstream&, Movie&);
void displayMovie(const Movie&);
Movie* createDatabase(int&);
bool caseInsensitiveCmp(string, string);
void findMovie(Movie*, int);
void saveToFile(const Movie&);
bool promptToContinue();
void displayFavorites();

int main() {
	ofstream outfile;
	ifstream infile;
	outfile.open("favorites.txt");
	Movie* favs, * favs2;
	int size;
	bool done = false;
	favs = createDatabase(size);
	infile.open("movies.txt");
	size = numberOfLines(infile);
	while (!done) {
		findMovie(favs, size);
		done = promptToContinue();
	}
	outfile.close();
	displayFavorites();

	infile.close();

	delete[] favs;
	favs = nullptr;


	system("pause");
}
// The number of lines function will accept an ifstream file
// so it can calculate the number of lines in the file.
// It will return an int, which will be the number of lines.
int numberOfLines(ifstream& infile) {

	string line;
	int i = 0;
	while (getline(infile, line)) {
		i++;
	}
	infile.close();
	return i;
}
// The populate movie from file function takes the data from all of the movies
// in the file and stores it in the Movie struct that is recieved.
// This function will accept an ifstream and a movie struct
// and doesn't return anything.
void populateMovieFromFile(ifstream& infile, Movie& favs) {
	string mov;


	getline(infile, mov);
	int firstComma = mov.find(',', 0);
	int secondComma = mov.find(',', firstComma + 2);
	int thirdComma = mov.find(',', secondComma + 2);
	int fourthComma = mov.find(',', thirdComma + 2);

	favs.title = mov.substr(0, firstComma);
	favs.totalGross = stod(mov.substr(firstComma + 2, secondComma - firstComma - 2));
	favs.director = mov.substr(secondComma + 2, thirdComma - secondComma - 2);
	favs.releaseDate = mov.substr(thirdComma + 2, fourthComma - thirdComma - 2);
	favs.runTime = stoi(mov.substr(fourthComma + 2));// sets string to int.

}
// The display movie function will display the data
// of the movie that is accepted to the function.
// This function will display the title, director,
// release date, total gross, and run time of the movie.
// The function will not return anything.
void displayMovie(const Movie& favs) {
	cout << endl;
	cout << "Title: " << favs.title << endl;
	cout << "Total Gross: " << favs.totalGross << endl;
	cout << "Director: " << favs.director << endl;
	cout << "Date of Release: " << favs.releaseDate << endl;
	cout << "Runtime: " << favs.runTime << endl;
}
// The create database function will create the array or database of movies
// for the user to look into when they need to search up the movies.
// The user will be prompted to enter a filename for the movies,
// which is going to bre movies.txt or whatever the filename is
// with the movie data stored inside.
// The function accepts an int, which is the size,
// and returns a movie pointer.
Movie* createDatabase(int& size) {
	Movie* favs;
	ofstream outfile;
	ifstream infile;
	string filename;
	cout << "Please enter a file name." << endl;
	cin >> filename;

	infile.open(filename);
	if (!infile) {
		while (!infile)
			cout << "Error. Please enter the correct file name." << endl;
		cin >> filename;
	}
	size = numberOfLines(infile);
	infile.open(filename);
	favs = new Movie[size];
	for (int i = 0; i < size; i++) {
		populateMovieFromFile(infile, *(favs + i));
	}

	infile.close();

	return favs;
}
// The case insensitive function will make the cases of the titles of the
// movies all uppercase, so that way, it the user can find the title
// of the movie by typing in the title any way they want.
// The function accepts two strings and returns a bool value.
bool caseInsensitiveCmp(string norm, string lower) {
	locale loc;
	if (lower.length() == norm.length()) {
		for (int i = 0; i < lower.length(); i++) {
			norm[i] = toupper(norm[i], loc);
			lower[i] = toupper(lower[i], loc);
		}

		if (norm == lower)
			return true;
		else
			return false;
	}
	return false;
}
// The find movie function will prompt the user to enter a title and then
// call the case sensitive function to check if the user input matches.
// If a movie is found, the user will be asked if they
// want to save the movie to a file.
// If they enter y, it will be saved to favorites.txt,
// if they enter n, it will not be saved.
// The function accepts a movie pointer and an int which is the size.
// The function returns nothing.
void findMovie(Movie* ptr, int size) {
	string title = "";
	bool found = false;
	char save;
	cout << "Please enter the title of the movie you are searching for.";
	cout << endl;
	cin.ignore();
	getline(cin, title);


	int i = 0;
	while (i < size) {
		if (caseInsensitiveCmp((ptr + i)->title, title)) {
			cout << "Movie Found!" << endl;
			found = true;
			displayMovie(*(ptr + i));
			cout << "Would you like to save the above movie, y/n?" << endl;
			cin >> save;
			if (save == 'y')
				saveToFile(*(ptr + i));
			break;
		}
		i++;
	}
	if (!found)
		cout << "Error, movie not found." << endl;

}
// The save to file function will save any movies to favorites.txt
// that the user wishes to save.
// The function accepts a constant movie and returns nothing.
void saveToFile(const Movie& favs) {
	ofstream outfile("favorites.txt", ios::app);

	outfile << favs.title << ", ";
	outfile << favs.totalGross << ", ";
	outfile << favs.director << ", ";
	outfile << favs.releaseDate << ", ";
	outfile << favs.runTime;
	outfile << endl;
	outfile.close();
}
// The prompt to continue function prompts the user asking them if they
// want to continue looking through the database.
// If they type in y, they will keep the program running,
// if they type n, the program will list their saved movies.
// The function accepts nothing but returns a bool value.
bool promptToContinue() {
	cout << "Would you like to continue? Y/N" << endl;
	char quit;
	cin >> quit;
	if (quit == 'n')
		return true;
	return false;
}
// The display favorites function will print out the data
// of all of the movies that the user has saved to the text file.
// The function neither returns nor accepts any values.
void displayFavorites() {
	ifstream infile;
	Movie* favs;
	infile.open("favorites.txt");
	if (!infile)
		cout << "Error!";
	int size = numberOfLines(infile);
	infile.open("favorites.txt");

	favs = new Movie[size];
	for (int i = 0; i < size; i++) {
		populateMovieFromFile(infile, *(favs + i));
	}

	cout << "Your saved movies are: " << endl;
	for (int i = 0; i < size; i++) {
		displayMovie(*(favs + i));
	}
	infile.close();
	delete[] favs;
	favs = nullptr;
}

/*Sample run:
Please enter a file name.
movies.txt
Please enter the title of the movie you are searching for.
SKYfall
Movie Found!

Title: Skyfall
Total Gross: 1.109
Director: Sam Mendes
Date of Release: 11/9/12
Runtime: 143
Would you like to save the above movie, y/n?
y
Would you like to continue? Y/N
y
Please enter the title of the movie you are searching for.
TITanic
Movie Found!

Title: Titanic
Total Gross: 2.187
Director: James Cameron
Date of Release: 12/19/97
Runtime: 195
Would you like to save the above movie, y/n?
y
Would you like to continue? Y/N
y
Please enter the title of the movie you are searching for.
finding DORIE
Error, movie not found.
Would you like to continue? Y/N
y
Please enter the title of the movie you are searching for.
finding dorY
Movie Found!

Title: Finding Dory
Total Gross: 1.029
Director: Andrew Stanton
Date of Release: 6/17/16
Runtime: 97
Would you like to save the above movie, y/n?
y
Would you like to continue? Y/N
n
Your saved movies are:

Title: Skyfall
Total Gross: 1.109
Director: Sam Mendes
Date of Release: 11/9/12
Runtime: 143

Title: Titanic
Total Gross: 2.187
Director: James Cameron
Date of Release: 12/19/97
Runtime: 195

Title: Finding Dory
Total Gross: 1.029
Director: Andrew Stanton
Date of Release: 6/17/16
Runtime: 97
Press any key to continue . . .
*/


