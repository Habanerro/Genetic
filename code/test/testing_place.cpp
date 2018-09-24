#include "../place/header_place.h"

int main()
{
	ofstream test;
	test.open("../test_log.txt", ios::trunc);
	int po = 0, f = 0, b = 0, w = 0, g = 0, j = 0, i = 0;

	test << "Testing program:" << endl;
	test << "\tPlace's function:\n\t{" << endl;

	sPlace a;
	a.lenght = 28;
	a.height = 21;
	a.bot = 30;
	a.food = 90;
	a.poison = 60;
	a.wall = 50;
	a.file = "\0";
	cPlace p(a);
	
	for (g = 1; g < 21; g++) {

		test << "\t\t" << g << ":" << endl;
		p.generate_place();
		p.spawn_wall();
		p.spawn_food();
		p.spawn_poison();
		p.spawn_bot();

		po = 0; f = 0; b = 0; w = 0;

		for (i = 1; i < p.height - 1; i++) {
			for (j = 1; j < p.lenght - 1; j++) {
				switch(p.ptr[i][j]) {
					case 'O': b++;
						break;
					case 'X': w++;
						break;
					case 'p': po++;
						break;
					case 'f': f++;
						break;
				}
			}
		}

		if (b == p.bot) {
			test << "\t\t\tBot:    " << "[correct]" << endl;
		} else {
			test << "\t\t\tBot:    " << "[incorrect]" << endl;
		}
		if (w == p.wall) {
			test << "\t\t\tWall:   " << "[correct]" << endl;
		} else {
			test << "\t\t\tWall:   " << "[incorrect]" << endl;
		}
		if (f == p.food) {
			test << "\t\t\tFood:   " << "[correct]" << endl;
		} else {
			test << "\t\t\tFood:   " << "[incorrect]" << endl;
		}
		if (po == p.poison) {
			test << "\t\t\tPoison: " << "[correct]" << endl;
		} else {
			test << "\t\t\tPoison: " << "[incorrect]" << endl;
		}
	}
	test << "\t}" << endl;

	return 0;
}
