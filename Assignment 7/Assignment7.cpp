// This program will create child classes from the parent class creature.
// The child classes are human, elf, and demon,
// and cyberdemon and balrog are children of demon.
// This program is basically a game and will allow the user to pit
// two different creatures against each other,
// until one or both of them don't have any hit points.
// Due date: 12/3/2019
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
// The creature class is the parent class,
// it has the hitpoints and strength values for the children of this class.
class Creature
{
private:

	int strength; // How much damage we can inflict
	int hitpoints; // How much damage we can sustain
	 // Returns type of species, for Creature class
					  // returns “unKnown”
public:
	Creature();
	// Initialize to human, 10 strength, 10 hit points
	Creature(int newStrength, int newHit);
	// Initialize creature to new type, strength, hit points

	virtual string getSpecies();
	virtual int getDamage();
	void setStrength(int s);
	void setHitpoints(int hp);
	int getStrength()const;
	int getHitpoints()const;
	// Returns amount of damage this creature
	// inflicts in one round of combat
};
// The human class is a child of creature and whatever hitpoints and
// strength are given, it will set those in creature.
// It also has getDamage and getSpecies which is defined for its own class.
class Human : public Creature {
public:
	Human() :Creature() {};
	Human(int s, int hp) :Creature(s, hp) {};
	int getDamage();
	string getSpecies();
};
// The Elf class is a child of creature and whatever hitpoints and
// strength are given, it will set those in creature.
// It also has getDamage and getSpecies which is defined for its own class.
class Elf : public Creature {
public:
	Elf() :Creature() {};
	Elf(int s, int hp) :Creature(s, hp) {};
	int getDamage();
	string getSpecies();
};
// The Demon class is a child of creature and whatever hitpoints and
// strength are given, it will set those in creature.
// It also has getDamage which is defined for its own class.
class Demon : public Creature {
public:
	Demon() :Creature() {};
	Demon(int s, int hp) :Creature(s, hp) {};

	int getDamage();
};
// The Balrog class is a child of Demon and whatever hitpoints and
// strength are given, it will set those in creature, and demon.
// It also has getDamage and getSpecies which is defined for its own class.
class Balrog : public Demon {
public:
	Balrog() :Demon() {};
	Balrog(int s, int hp) :Demon(s, hp) {};

	int getDamage();
	string getSpecies();
};
// The Cyberdemon class is a child of Demon and whatever hitpoints and
// strength are given, it will set those in creature, and demon.
// It also has getDamage and getSpecies which is defined for its own class.
class Cyberdemon : public Demon {
public:
	Cyberdemon() :Demon() {};
	Cyberdemon(int s, int hp) :Demon(s, hp) {};

	int getDamage();
	string getSpecies();
};
// battleArena function prototype.
void battleArena(Creature& c1, Creature& c2);
// The main function will go through how much damage is dealt by each creature
// and then it will call battleArena to pit two creatures in a fight.
// It doesn't accept or return anything.
int main()
{
	srand(static_cast<int>(time(NULL)));
	Human human1(30, 10);
	human1.getDamage();
	cout << endl;
	Elf elf1;
	elf1.getDamage();
	cout << endl;
	Balrog balrog1(50, 50);;
	balrog1.getDamage();
	cout << endl;
	Cyberdemon cdemon(30, 40);
	cdemon.getDamage();
	cout << endl;
	Elf elf2(50, 50);
	Balrog balrog2(50, 50);
	cout << endl;
	battleArena(elf2, balrog2);

}
// The battleArena function will accept two creature objects
// which can be any of the children, and have them fight each other.
// It is put in a while loop and basically, both creatures get a turn,
// and whatever damage they deal, is the amount of health that is subtracted.
// The while loop is broken and the battle is over once either one creature
// or both creatures' health is at or below zero.
// It will then state which creature won or if there was a tie.
// It will not return anything.
void battleArena(Creature& c1, Creature& c2) {
	while (true) {
		c2.setHitpoints(c2.getHitpoints() - c1.getDamage());
		cout << c2.getSpecies() << " has " <<
			c2.getHitpoints() << " hit points" << endl;

		c1.setHitpoints(c1.getHitpoints() - c2.getDamage());
		cout << c1.getSpecies() << " has " <<
			c1.getHitpoints() << " hit points" << endl;
		if (c2.getHitpoints() <= 0 && c1.getHitpoints() <= 0) {
			cout << "It's a tie!" << endl;
			break;
		}
		if (c2.getHitpoints() <= 0) {
			cout << c1.getSpecies() << " wins!" << endl;
			break;
		}
		else if (c1.getHitpoints() <= 0) {
			cout << c2.getSpecies() << " wins!" << endl;
			break;
		}
	}
}
// This is the default constructor for creature.
// It sets strength and hitpoints to ten,
//and doesn't accept or return anything.
Creature::Creature() {
	strength = 10;
	hitpoints = 10;
}
// This is the overloaded constructor for creature, it will set the hitpoints
// and strength to the values passed through it.
// It accepts two int values for hitpoints and strength but returns nothing.
Creature::Creature(int newStrength, int newHit) {
	strength = newStrength;
	hitpoints = newHit;
}
// This finction accepts an int value.
// This function will set strength to the value passed through.
// The function returns nothing.
void Creature::setStrength(int s) {
	strength = s;
}
// This finction accepts an int value.
// This function will set hitpoints to the value passed through.
// The function returns nothing.
void Creature::setHitpoints(int hp) {
	hitpoints = hp;
}
// This function returns the strength value of the creture object,
// it doesn't accept arguments.
int Creature::getStrength()const {
	return strength;
}
// This function returns the hitpoints value of the creture object,
// it doesn't accept arguments.
int Creature::getHitpoints()const {
	return hitpoints;
}
// This function doesn't accept any arguments,
// but it will return unkown because the creature is unkown.
string Creature::getSpecies()
{

	return "Unknown";
}
// This function doesn't accept any arguments,
// but it will return human.
string Human::getSpecies()
{

	return "Human";
}
// This function doesn't accept any arguments,
// but it will return Elf.
string Elf::getSpecies()
{

	return "Elf";
}
// This function doesn't accept any arguments,
// but it will return Balrog.
string Balrog::getSpecies() {
	return "Balrog";
}
// This function doesn't accept any arguments,
// but it will return Cyberdemon.
string Cyberdemon::getSpecies() {
	return "Cyberdemon";
}
// This function calculates the damage that a demon will deal,
// including a demonic attack that deals 50 extra damage.
// it will return the damage.
int Demon::getDamage() {
	int damage = Creature::getDamage();
	if ((rand() % 100) < 5) {
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 " << " additional damage points!" << endl;
	}
	return damage;
}
// This function calculates the damage that a Balrog will deal,
// including a demonic attack that deals 50 extra damage.
// It will also calculate another damage because the balrog attacks twice.
// it will return the damage.
int Balrog::getDamage() {
	int damage;
	damage = (rand() % getStrength()) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;
	if ((rand() % 100) < 5) {
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "
			<< " additional damage points!" << endl;
	}
	int damage2 = (rand() % getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2;
	cout << " additional damage points!" << endl;
	damage = damage + damage2;
	return damage;
}
// This function calculates the damage that a Cyberdemon will deal,
// including a demonic attack that deals 50 extra damage.
// it will return the damage.
int Cyberdemon::getDamage() {
	int damage = Creature::getDamage();
	if ((rand() % 100) < 5) {
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 " << " additional damage points!" << endl;
	}
	return damage;
}

// This function calculates the damage that a Human will deal,
// which is only the standard damage.
// it will return the damage.
int Human::getDamage() {
	int damage;
	damage = (rand() % getStrength()) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;
	return damage;
}
// This function calculates the damage that an Elf will deal,
// including a magical attack that can inflict additional damage.
// it will return the damage.
int Elf::getDamage() {
	int damage;
	damage = (rand() % getStrength()) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;
	if ((rand() % 10) == 0) {
		cout << "Magical attack inflicts " << damage <<
			" additional damage points!" << endl;
		damage = damage * 2;
	}
	return damage;
}
// This function calculates the damage that a creature will deal,
// which is the standard attack.
// it will return the damage.
int Creature::getDamage()
{
	int damage;
	// All creatures inflict damage which is a
	// random number up to their strength
	damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;

	return damage;
}

/*sample run:
Human attacks for 11 points!

Elf attacks for 10 points!

Balrog attacks for 40 points!
Balrog speed attack inflicts 48 additional damage points!

Cyberdemon attacks for 2 points!


Elf attacks for 14 points!
Balrog has 36 hit points
Balrog attacks for 1 points!
Balrog speed attack inflicts 3 additional damage points!
Elf has 46 hit points
Elf attacks for 38 points!
Balrog has -2 hit points
Balrog attacks for 35 points!
Demonic attack inflicts 50  additional damage points!
Balrog speed attack inflicts 43 additional damage points!
Elf has -82 hit points
It's a tie!

C:\Users\jason\source\repos\Assignment7\Debug\Assignment7.exe
(process 10668) exited with code 0.
Press any key to close this window . . .
C:\Users\jason\source\repos\Assignment7\Debug\
Assignment7.exe (process 10360) exited with code 0.
Press any key to close this window . . .
*/