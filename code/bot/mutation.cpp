#include "header_bot.h"

void Bot::mutation()
{
	srand( time(NULL) );
	unint i = rand() % gquant;
	unint j = rand() % 2;

	if (j) {
		gen[i]++;
	} else {
		gen[i]--;
	}
}
