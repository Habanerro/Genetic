#include "../place/header_place.hh"

void relationship(Place* a, Bot* c, Predator* dat)
{
	a -> log << "\tCome in relationship" << endl;
	a-> log << "\t\t1) Bots:" << endl;
	int g = 0;
	for (int i = 1; i < a -> height - 1; i++) {
		for (int j = 1; j < a -> lenght - 1; j++) {
			if (a -> ptr[i][j] == 'O') {
				a -> log << "\t\t\tFound bot: "
						 << "x = " << i
						 << "; y = " << j
						 << "; g = " << g << endl;
				c[g].x = i;
				c[g].y = j;
				g++;
			}
		}
	}
	a-> log << "\t\t2) Predators:" << endl;
	g = 0;
	for (int i = 1; i < a -> height - 1; i++) {
		for (int j = 1; j < a -> lenght - 1; j++) {
			if (a -> ptr[i][j] == '#') {
				a -> log << "\t\t\tFound predator: "
						 << "x = " << i
						 << "; y = " << j
						 << "; g = " << g << endl;
				dat[g].x = i;
				dat[g].y = j;
				g++;
			}
		}
	}
	a -> log << "\tEnd of relationship" << endl;
}
