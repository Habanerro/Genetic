#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#include "../place/header_place.hh"
typedef unsigned char uchar;
using namespace std;

class Bot {
	friend int main();
	friend class Place;
	friend class Predator;
	friend void population(Bot*, unint);
	friend void relationship(Place*, Bot*, Predator*);
	friend void save(Place*, Bot*, int);
	friend int read(Place*, Bot*, int*);
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
	friend void population(Bot*, unint);
	friend void relationship(Place*, Bot*);
	friend void save(Place*, Bot*, int);
	friend int read(Place*, Bot*, int*);
public:
	Predator();
	~Predator();
	int turn(Place*, Bot*);
};

typedef class Bot cBot;
