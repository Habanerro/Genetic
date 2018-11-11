#include "header_bot.hh"

void relationship(Place* a, Bot* c)
{
	a -> log << "\tCome in relationship" << endl;
	int g = 0;
	for (int i = 1; i < a -> height - 1; i++) {
		for (int j = 1; j < a -> lenght - 1; j++) {
			if (a -> ptr[i][j] == 'O') {
				a -> log << "\t\tFound bot: "
						 << "x = " << i
						 << "; y = " << j
						 << "; g = " << g << endl;
				c[g].x = i;
				c[g].y = j;
				g++;
			}
		}
	}
	a -> log << "\tEnd of relationship" << endl;
}
