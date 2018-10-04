#include "header_bot.h"

void Bot::mutation()
{
	log << "\tCome in mutation function" << endl;
	srand( time(NULL) );
	unint i = rand() % gquant;
	unint j = rand() % 2;

	if (j) {
		gen[i]++;
		if (gen[i] == range) {
			gen[i] -= 2;
		}
	} else {
		gen[i]--;
		if (gen[i] == -1) {
			gen[i] += 2;
		}
	}
	log << "\t\tMutation: gen = " << i << "; value = " << gen[i] << endl;
	printf("Mutation: gen = %d; value = %d;\n", i, gen[i]);
	log << "\tEnd mutation" << endl;
}
