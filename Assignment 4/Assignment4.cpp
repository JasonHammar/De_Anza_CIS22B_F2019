// Due date is November 1st, 2019.
// This program basically acts like a vending machine,
// and will prompt the user to enter a number of quarters.
// It will calculate how much money you have
// and then give you three choices of delicious treats.
// The user will choose an option, and the program will
// dispense the amount of money left over and the item,
// so long as the user entered enough money and the item isn't sold out.
// The user will be asked if they want to continue, if they say yes,
// They will go through the program again,
// otherwise it will print the closing transaction data.
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<ctime>
#pragma warning(disable: 4996)


using namespace std;

// Snack class which stores all class variables, constructors, and methods.
class Snack {
private:
	// Private part of the class that stores the variables.
	string name;
	double price;
	int quantityInStock, numSold;
	string* strPtr;

	string getCurrentTime() {
		// gets the time at which the transaction occurred.
		time_t t = time(0);
		struct tm ts;
		char buff[10];
		ts = *localtime(&t);
		strftime(buff, sizeof(buff), "%X", &ts);
		return buff;
	};
public:
	int i = 0;
	// Default constructor.
	Snack() {
		name = " ";
		price = 0;
		quantityInStock = 0;
		numSold = 0;

	}
	// Overloaded constructor.
	Snack(string named, double priced, int quantity) {
		name = named;
		price = priced;
		quantityInStock = quantity;
		strPtr = new string[quantityInStock];
	}

	// Getters and setters for the private variables.
	// Getters return the variables they are getting,
	// setters accept the variable that they are setting a variable to.
	void setNumSold(int sold) {
		numSold = sold;
	}
	void setName(string named) {
		name = named;
	}

	void setPrice(double priced) {
		price = priced;
	}
	void setQuantityInStock(int quantity) {
		quantityInStock = quantity;
		if (i == 0)
			strPtr = new string[quantityInStock];
	}
	string getName() const {
		return name;
	}
	double getPrice() const {
		return price;
	}
	int getQuantityInStock() const {
		return quantityInStock;
	}

	int getNumSold() {
		return numSold;
	}
	// return true or false if the item was able to be sold
	// and accepts the amount of money entered.
	// Will check if the snack the user chose to purchase is in stock,
	// and if the user has enough money for that snack.
	bool buyItem(double& moneyEntered) {

		if (quantityInStock == 0) {
			cout << "Error, item is not in stock" << endl;
			cout << moneyEntered << " has been dispensed below." << endl;
			return false;
		}



		if (moneyEntered >= price) {

			quantityInStock -= 1;
			numSold += 1;
			cout << "Item has been dispensed below." << endl;
			if (moneyEntered > price) {
				moneyEntered -= price;
				cout << "$" << moneyEntered << " dispensed below." << endl;
			}
			int i = 0;
			while (true) {

				if (*(strPtr + i) == "") {
					*(strPtr + i) = getCurrentTime();
					break;
				}
				
				i++;
			}
			return true;
		}
		else if (moneyEntered < price) {
			cout << "Error, not enogh money." << endl;
			cout << moneyEntered << " has been dispensed below." << endl;
			return false;
		}
	}
	// Destructor for the class. Accepts and returns nothing.
	~Snack() {
		cout << "Closing info for: " << name << endl;
		cout << quantityInStock << " in stock." << endl;
		cout << numSold << " sold for a profit of $";
		cout << numSold * price << endl;
		if (*(strPtr + 0) != "") {
			cout << "Transactions occurred at: " << endl;
			int i = 0;
			while (true) {
				if (*(strPtr + i) != "") {
					cout << *(strPtr + i) << endl;
					i++;
				}
				else
					break;
			}

		}
		cout << endl;
		cout << endl;
		cout << endl;
		delete[]strPtr;
	}

};
// function Prototypes.

void userBuyItem(Snack[], int);
void displayVendingMachine(const Snack[], int num);
int getQuarters();
bool promptToContinue();
// Main function.
// Calls other functions and sets the values of the snack array.
int main() {
	Snack snacks[3] = { {},{ "Candy", 1.25, 5 },{ "Soda", 1.00, 3 } };


	snacks[0].setName("Chips");
	snacks[0].setPrice(1.75);
	snacks[0].setQuantityInStock(3);
	snacks[1].setNumSold(0);
	snacks[2].setNumSold(0);

	userBuyItem(snacks, 3);

	/*snacks[0].~Snack();
	snacks[1].~Snack();
	snacks[2].~Snack();
	system("pause");*/
	return 0;

}
// This function accepts a constant snack array and
// the number of items in the array, but doesn't return anything.
// This function will display the current contents of the vending machine.
void displayVendingMachine(const Snack snacks[], int num) {

	cout << "Item #	Item Name  	Price 	# in-stock" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < num; i++) {
		cout << fixed;
		if (i == 2) {
			cout << i + 1 << "     	" << snacks[i].getName();
			cout << "       	$";
			cout << setprecision(2) << snacks[i].getPrice();
			cout << fixed << "  	";
			cout << snacks[i].getQuantityInStock() << endl;
		}
		else {
			cout << i + 1 << "     	" << snacks[i].getName();
			cout << "      	$";
			cout << setprecision(2) << snacks[i].getPrice();
			cout << fixed << "  	";
			cout << snacks[i].getQuantityInStock();
			cout << endl;
		}
	}
}
/*
Item #	Item Name  	Price 	# in
-
stock
-
--------------------------------------------
1     	Chips      	1.75  	3
2     	Candy      	1.25  	5
3     	Soda       	1.00  	2

*/
// This function doesn't accept anything,
// but will return the number of quarters.
// This function will prompt the user to enter a number of quarters.
int getQuarters() {
	int quarters;
	cout << "Please enter the number of quarters." << endl;
	cin >> quarters;
	return quarters;
}
// This function accepts a snack array and the number of elements in the array.
// It doesn't return anything.
// It will call the getQuarters function
// and then calculate the total amount of money entered.
// It will then prompt the user to enter a number
// between 1 and 3 for a selection to the vending machine.
// It will check to make sure that enough money was entered
// and that the item is in stock.
// It will then call the promptToContinue function
// to ask the user if they want to continue.
void userBuyItem(Snack snacks[], int num) {
	bool cont = true;
	while (cont) {
		displayVendingMachine(snacks, num);
		int userNum;
		int quarters = getQuarters();
		double moneyEntered = quarters * 0.25;

		cout << "Amount entered: $" << moneyEntered << endl;
		cout << "Enter a number between 1 and 3 to make your selection.";
		cout << endl;
		cin >> userNum;
		if (userNum > 3 || userNum < 1) {
			while (userNum > 3 || userNum < 1) {
				cout << "Error, invalid entry, please enter a number ";
				cout << "between 1 and 3 to make your selection." << endl;
				cin >> userNum;
			}
		}
		snacks[userNum - 1].buyItem(moneyEntered);

		cont = promptToContinue();
	}

}
// This function doesn't accept anything
// but it will return either true or false.
// It will ask the user if they want to continue, if they type in y,
// it will return true, if they typr in n, it will return false.
bool promptToContinue() {
	cout << "Would you like to continue, y/n?" << endl;
	char cont;
	cin >> cont;
	if (cont == 'y' || cont == 'Y') {
		return true;

	}
	else if (cont == 'n' || cont == 'N')
		return false;
	return false;
}


/*Sample Run:
Item #  Item Name       Price   # in-stock
---------------------------------------------
1       Chips           $1.75   3
2       Candy           $1.25   5
3       Soda            $1.00   3
Please enter the number of quarters.
7
Amount entered: $1.75
Enter a number between 1 and 3 to make your selection.
4
Error, invalid entry, please enter a number between 1 and 3 to make your selection.
2
Item has been dispensed below.
$0.50 dispensed below.
Would you like to continue, y/n?
y
Item #  Item Name       Price   # in-stock
---------------------------------------------
1       Chips           $1.75   3
2       Candy           $1.25   4
3       Soda            $1.00   3
Please enter the number of quarters.
8
Amount entered: $2.00
Enter a number between 1 and 3 to make your selection.
3
Item has been dispensed below.
$1.00 dispensed below.
Would you like to continue, y/n?
y
Item #  Item Name       Price   # in-stock
---------------------------------------------
1       Chips           $1.75   3
2       Candy           $1.25   4
3       Soda            $1.00   2
Please enter the number of quarters.
4
Amount entered: $1.00
Enter a number between 1 and 3 to make your selection.
1
Error, not enogh money.
1.00 has been dispensed below.
Would you like to continue, y/n?
y
Item #  Item Name       Price   # in-stock
---------------------------------------------
1       Chips           $1.75   3
2       Candy           $1.25   4
3       Soda            $1.00   2
Please enter the number of quarters.
7
Amount entered: $1.75
Enter a number between 1 and 3 to make your selection.
1
Item has been dispensed below.
Would you like to continue, y/n?
y
Item #  Item Name       Price   # in-stock
---------------------------------------------
1       Chips           $1.75   2
2       Candy           $1.25   4
3       Soda            $1.00   2
Please enter the number of quarters.
12
Amount entered: $3.00
Enter a number between 1 and 3 to make your selection.
2
Item has been dispensed below.
$1.75 dispensed below.
Would you like to continue, y/n?
n
Closing info for: Soda
2 in stock.
1 sold for a profit of $1.00
Transactions occurred at:
13:49:06



Closing info for: Candy
3 in stock.
2 sold for a profit of $2.50
Transactions occurred at:
13:49:02
13:49:32



Closing info for: Chips
2 in stock.
1 sold for a profit of $1.75
Transactions occurred at:
13:49:20




C:\Users\jason\source\repos\Assignment4\Debug\
Assignment4.exe (process 8424) exited with code 0.
Press any key to close this window . . .
*/


