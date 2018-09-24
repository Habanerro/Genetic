#include "header_place.h"

void Place::spawn_wall()
{
	log << "\tCome in spawn_wall" << endl;
	srand( time(NULL) );

	char direction = 0;	// four value's
	char delta = 0;		// two value's
	char chance = 0;	// three value's
	char q = 5;			// quantity of wall's section in the wall segment

	unint segments = wall / 5; // quantity of wall's segments
	unint nLenght = lenght - 10;
	unint nHeight = height - 10;

	int i = 0, j = 0, g = 0, k = 0, m = 0, n = 0;
	int a = 0; // buffer for offset

	log << "\t\tStaring generation..." << endl;
		log << "\t\t\tWe waiting " << segments << " wall's segments" << endl;
		log << "\t\t\tnHeight = " << nHeight
			<< "; nLenght = " << nLenght << endl;

		for (k = 0; k < segments; k++) {
			j = 5 + rand() % nLenght;
			i = 5 + rand() % nHeight;
			direction = rand() % 4;
			log << "\t\t\ti = " << i
				<< "; j = " << j
				<< "; direction = " << direction
				<< "; k = " << k << endl;
			switch (direction) {
				case 0: // up
					a = i;
					for (g = 0; g < q; g++) {
						delta = rand() % 2;
						chance = rand() % 3;
						m = 0;
						if (chance == 1) {
							if (delta = 0) {
								// to left
								m = 1;
							} else {
								// to right
								m = -1;
							}
						}
						ptr[a][j + m] = 'X';
						a++;
					}
					break;
				case 1:	// down
					a = i;
					for (g = 0; g < q; g++) {
						delta = rand() % 2;
						chance = rand() % 3;
						m = 0;
						if (chance == 1) {
							if (delta = 0) {
								// to left
								m = 1;
							} else {
								// to right
								m = -1;
							}
						}
						ptr[a][j + m] = 'X';
						a--;
					}
					break;
				case 2:	// right
					a = j;
					for (g = 0; g < q; g++) {
						delta = rand() % 2;
						chance = rand() % 3;
						m = 0;
						if (chance == 1) {
							if (delta = 0) {
								// to left
								m = 1;
							} else {
								// to right
								m = -1;
							}
						}
						ptr[i + m][a] = 'X';
						a++;
					}
					break;
				case 3:	// left
					a = j;
					for (g = 0; g < q; g++) {
						delta = rand() % 2;
						chance = rand() % 3;
						m = 0;
						if (chance == 1) {
							if (delta = 0) {
								// to left
								m = 1;
							} else {
								// to right
								m = -1;
							}
						}
						ptr[i + m][a] = 'X';
						a--;
					}
					break;
			}
		}
	log << "\t\t\tEnd of generation." << endl;

	log << "\tEnd spawn_wall" << endl;
}