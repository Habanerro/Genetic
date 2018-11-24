#include "header_place.hh"

void Place::spawn_predator()
{
	srand( time(NULL) );
	log << "\tCome in spawn_predator(!!)" << endl;
	log << "\t\tWe waiting " << predator << " predators" << endl;
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

		for (i = 0; i < predator; i++) {
			v = rand() % g;
			while (uu[v]) {
				v = rand() % g;
			}
			
			ptr[xc[v]][yc[v]] = '&';
			uu[v] = 1;
		}
		delete xc;
		delete yc;
		delete uu;

	log << "\tEnd spawn_predator" << endl;
}
