#include "header_bot.h"

Bot::Bot()
{
	gquant = 50;
	range = 40;
	grn = 0;
	hp = 50;
	lp = 50;
	ya = 0;
	next = 0;

	gen = new uchar[gquant];
	for (i = 0; i < gquant; i++) {
		gen[i] = rand() % range;
	}

	log.open("../log_bot.txt", ios::app);
	log << "\t*--constructor--*" << endl;
}

Bot::~Bot()
{
	gquant = 0;
	range = 0;
	grn = 0;
	hp = 0;
	lp = 0;
	ya = 0;
	next = 0;

	delete gen;
	log << "\t*--destructor--*" << endl;
	log.close();
}