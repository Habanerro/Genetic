#include "header_place.h"

void Place::spawn_wall()
{
	log << "\tCome in spawn_wall" << endl;
	srand( time(NULL) );

	log << "\t\tStaring generation..." << endl;
	int i = 0, j = 0, g = 0, v = 0;
		
	// lenght >= height
	int* xc = new int[all];
	int* yc = new int[all];
	int* uu = new int[all]; // used coordinates

	for (i = 0; i < all; i++) {
		uu[i] = 0;
	}

	for (i = 1; i < height - 1; i++) {
		for (j = 1; j < lenght - 1; j++) {
			if (ptr[i][j] == '_') {
				xc[g] = i;
				yc[g] = j;
				g++;
			}
		}
	}
	log << "\t\tQuantity of free gekses: " << g << endl;

	for (i = 0; i < wall; i++) {
		v = rand() % g;
		while (uu[v]) {
			v = rand() % g;
		}
		
		ptr[xc[v]][yc[v]] = 'X';
		uu[v] = 1;
	}
	delete xc;
	delete yc;
	delete uu;
/*
	char direction = 0;	// four value's
	char delta = 0;		// two value's
	char chance = 0;	// three value's
	char q = 5;			// quantity of wall's section in the wall segment

	unint segments = wall / 5; // quantity of wall's segments
	unint nLenght = lenght - 10;
	unint nHeight = height - 10;

	int i = 0, j = 0, g = 0, k = 0, m = 0, n = 0, v = 0;
	int a = 0; // buffer for offset

		log << "\t\t\tWe waiting " << segments << " wall's segments" << endl;
		log << "\t\t\tnHeight = " << nHeight
			<< "; nLenght = " << nLenght << endl;

		int* xc = new int[all];
		int* yc = new int[all];
		int* uu = new int[all]; // used coordinates

		for (i = 0; i < all; i++) {
			uu[i] = 0;
		}

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

						if (ptr[a][j + m] == 'X') {
							v++;
						} else {
							ptr[a][j + m] = 'X';
						}
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

						if (ptr[a][j + m] == 'X') {
							v++;
						} else {
							ptr[a][j + m] = 'X';
						}
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

						if (ptr[i + m][a] == 'X') {
							v++;
						} else {
							ptr[i + m][a] = 'X';
						}
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
						if (ptr[i + m][a] == 'X') {
							v++;
						} else {
							ptr[i + m][a] = 'X';
						}
						a--;
					}
					break;
			}
		}

	g = 0;
	for (i = 1; i < height - 1; i++) {
		for (j = 1; j < lenght - 1; j++) {
			if (ptr[i][j] == '_') {
				xc[g] = i;
				yc[g] = j;
				g++;
			}
		}
	}
	log << "\t\tNeed save " << v << " walls" << endl;
	for (i = 0; i < v; i++) {
		v = rand() % g;
		while (uu[v]) {
			v = rand() % g;
		}
			
		ptr[xc[v]][yc[v]] = 'X';
		uu[v] = 1;
	}*/
	log << "\t\t\tEnd of generation." << endl;

	log << "\tEnd spawn_wall" << endl;
}
