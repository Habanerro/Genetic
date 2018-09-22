#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;

typedef unsigned char uchar;

// start settings of place
struct SettingsPlace {
	uchar lenght;	// quantity of cols - длина
	uchar height;	// quantity of rows - высота
	uchar bot;		// quantity of bots		'O'()
	uchar food;		// quantity of food 	'h'()
	uchar poison;	// quantity of poison 	'p'()
	uchar wall; 	// quantity of wall's 	'X'()
	string file;	// name of file of the settings
};
typedef struct SettingsPlace sPlace;

// information about place in real time
class Place {
	friend main();
public:
	void generate_place(); // to create basis of place

	Place(sPlace);	// normal constructor
	~Place();		// destructor
protected:
	uchar lenght;	// quantity of cols
	uchar height;	// quantity of rows
	uchar all;		// quantity of all cell points
	uchar bot;		// quantity of bots
	uchar food;		// quantity of food points
	uchar poison;	// quantity of poison points
	uchar wall;		// quantity of wall points

	char** ptr;		// pointer to place
	string file;	// name of file of the settings
};
typedef class Place cPlace;