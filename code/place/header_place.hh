#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;
typedef unsigned int unint;
typedef unsigned char uchar;

// start settings of place
struct SettingsPlace {
	unint lenght;	// quantity of cols - длина
	unint height;	// quantity of rows - высота
	unint bot;		// quantity of bots		'O'()
	unint predator;	// quantity of predators'#'()
	unint food;		// quantity of food 	'f'()
	unint poison;	// quantity of poison 	'p'()
	unint wall; 	// quantity of wall's 	'X'()
	string file;	// name of file of the settings
};
typedef struct SettingsPlace sPlace;

// information about place in real time
class Place {
	friend int main();
	friend class Bot;
	friend class Predator;
	friend void relationship(Place*, Bot*, Predator*);
	friend void save(Place*, Bot*, int, Predator*);
	friend int read(Place*, Bot*, int*, Predator*);
public:
	void generate_place();	// to create basis of place
	void print_place();		// to show genetic location
	void spawn_wall();		// to add walls on the location
	void spawn_food();		// to add foot on the location
	void spawn_poison();	// to add poison on the location
	void spawn_bot();		// to add bots on the location
	void spawn_predator();	// to add predators on the location
	void spawn_one();		// spawn one geks of food/poison	

	Place(sPlace);	// normal constructor
	Place();		// default constrtuctor
	~Place();		// destructor
private:
	unint lenght;	// quantity of cols
	unint height;	// quantity of rows
	unint all;		// quantity of all cell points
	unint bot;		// quantity of bots
	unint predator;	// quantity of predator
	unint food;		// quantity of food points
	unint poison;	// quantity of poison points
	unint wall;		// quantity of wall points

	char** ptr;		// pointer to place
	string file;	// name of file of the settings

	ofstream log;	// inforamtion about working
};
typedef class Place cPlace;


class Bot {
	friend int main();
	friend class Place;
	friend class Predator;
	friend void population(Bot*, unint, Predator*, unint);
	friend void relationship(Place*, Bot*, Predator*);
	friend void save(Place*, Bot*, int, Predator*);
	friend int read(Place*, Bot*, int*, Predator*);
public:
	Bot();	// constructor
	~Bot();	// destructor
	void turn(Place*);	// one turn of one bot
	void mutation();	// mutation 1 gen

protected:
	unint gquant;	// quantity of gens in genetic matrix
	unint range;	// range of command
	unint grn;		// gen right now - pointer to gen in genetic matrix
	unint hp;		// healths points
	unint lp;		// live points - all hp in the bot's live
	unint x;		// 
	unint y;		// coordinates of bot on the location
	unint flag;		// information of live - 0 = dead

	int* gen;		// genetic matrix
	ofstream log;	// information about working
};

class Predator: public Bot {
	friend int main();
	friend class Place;
	friend void population(Bot*, unint, Predator, unint);
	friend void relationship(Place*, Bot*, Predator*);
	friend void save(Place*, Bot*, int, Predator*);
	friend int read(Place*, Bot*, int*, Predator*);
public:
	Predator();
	~Predator();
	int turn(Place*, Bot*);
};

typedef class Bot cBot;
