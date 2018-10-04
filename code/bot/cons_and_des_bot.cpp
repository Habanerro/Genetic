#include "header_bot.h"

Bot::Bot()
{
	gquant = 50;
	range = 40;
	grn = 0;
	hp = 50;
	lp = 50;
	x = 0;
	y = 0;
	flag = 1;

	gen = new int[gquant];
	for (int i = 0; i < gquant; i++) {
		gen[i] = rand() % range;
	}

	//log.open("log.txt", ios::app);
	log << "\t*--constructor-bot-*" << endl;
}

Bot::~Bot()
{
	gquant = 0;
	range = 0;
	grn = 0;
	hp = 0;
	lp = 0;
	x = 0;
	y = 0;
	flag = 0;

	delete gen;
	log << "\t*--destructor-bot-*" << endl;
	log.close();
}
