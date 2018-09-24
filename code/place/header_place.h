#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;

typedef unsigned int unint;

// start settings of place
struct SettingsPlace {
	unint lenght;	// quantity of cols - длина
	unint height;	// quantity of rows - высота
	unint bot;		// quantity of bots		'O'()
	unint food;		// quantity of food 	'h'()
	unint poison;	// quantity of poison 	'p'()
	unint wall; 	// quantity of wall's 	'X'()
	string file;	// name of file of the settings
};
typedef struct SettingsPlace sPlace;

// information about place in real time
class Place {
	friend main();
public:
	void generate_place();	// to create basis of place
	void print_place();		// to show genetic location
	void spawn_wall();		// to add walls on the location
	void spawn_food();		// to add foot on the location
	void spawn_poison();	// to add poison on the location
	

	Place(sPlace);	// normal constructor
	Place();		// default constrtuctor
	~Place();		// destructor
protected:
	unint lenght;	// quantity of cols
	unint height;	// quantity of rows
	unint all;		// quantity of all cell points
	unint bot;		// quantity of bots
	unint food;		// quantity of food points
	unint poison;	// quantity of poison points
	unint wall;		// quantity of wall points

	char** ptr;		// pointer to place
	string file;	// name of file of the settings

	ofstream log;	// inforamtion about working
};
typedef class Place cPlace;