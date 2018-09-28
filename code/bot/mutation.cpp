#include "header_bot.h"

void Bot::mutation()
{
	log << "\tCome in mutation function" << endl;
	srand( time(NULL) );
	unint i = rand() % gquant;
	unint j = rand() % 2;

	if (j) {
		gen[i]++;
	} else {
		gen[i]--;
	}
	log << "\t\tMutation: gen = " << i << "; value = " << gen[i] << endl;
	log << "\tEnd mutation" << endl;
}
