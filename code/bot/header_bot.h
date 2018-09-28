#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#include "../place/header_place.h"
typedef unsigned char uchar;
using namespace std;

class Bot {
	friend int main();
	friend class Place;
	friend void relationship(Place*, Bot*);
public:
	Bot();	// constructor
	~Bot();	// destructor
	void turn(Place*);	// one turn of one bot
	void mutation();	// mutation 1 gen

private:
	unint gquant;	// quantity of gens in genetic matrix
	unint range;	// range of command
	unint grn;		// gen right now - pointer to gen in genetic matrix
	unint hp;		// healths points
	unint lp;		// live points - all hp in the bot's live
	unint x;		// 
	unint y;		// coordinates of bot on the location
	unint flag;		// information of live - 0 = dead

	uchar* gen;		// genetic matrix
	ofstream log;	// information about working
};
typedef class Bot cBot;
