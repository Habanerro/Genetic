#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#include "../place/header_place.h"
using namespace std;

class Bot {
	friend main();
public:

	Bot();	// constructor
	~Bot();	// destructor
protected:
	unint gquant;	// quantity of gens in genetic matrix
	unint grn;		// gen right now - pointer to gen in genetic matrix
	unint hp;		// healths points
	unint lp;		// live points - all hp in the bot's live
	unint ya;		// index of this bot
	unint next;		// index of the next undead bot in the

	char* gen;		// genetic matrix
	ofstream log;	// information about working
};