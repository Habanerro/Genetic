#include "header_place.hh"

void Place::spawn_wall()
{
	log << "\tCome in spawn_wall" << endl;
	srand( time(NULL) );

	log << "\t\tStaring generation..." << endl;

	char direction = 0;	// four value's
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
						if (ptr[a][j] == 'X') {
							v++;
						} else {
							ptr[a][j] = 'X';
						}
						a++;
					}
					break;
				case 1:	// down
					a = i;
					for (g = 0; g < q; g++) {
						if (ptr[a][j] == 'X') {
							v++;
						} else {
							ptr[a][j] = 'X';
						}
						a--;
					}
					break;
				case 2:	// right
					a = j;
					for (g = 0; g < q; g++) {
						if (ptr[i][a] == 'X') {
							v++;
						} else {
							ptr[i][a] = 'X';
						}
						a++;
					}
					break;
				case 3:	// left
					a = j;
					for (g = 0; g < q; g++) {						
						if (ptr[i][a] == 'X') {
							v++;
						} else {
							ptr[i][a] = 'X';
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
		m = rand() % g;
		while (uu[m]) {
			m = rand() % g;
		}
			
		ptr[xc[m]][yc[m]] = 'X';
		uu[m] = 1;
	}

	log << "\t\t\tEnd of generation." << endl;

	log << "\tEnd spawn_wall" << endl;
}
