#include "header_place.h"

void Place::spawn_poison()
{
	srand( time(NULL) );
	log << "\tCome in spawn_poison" << endl;
		log << "\t\tWe waiting " << poison << " poison gekses" << endl;

		int i = 0, j = 0, g = 0, v = 0;
		unint nHeight = height - 2;
		unint nLenght = lenght - 2;
		log << "\t\t\tnHeight = " << nHeight
			<< "; nLenght = " << nLenght << endl;

		for (g = 0; g < poison; g++) {
			i = 1 + rand() % nHeight;
			j = 1 + rand() % nLenght;
			//log << "\t\t\ti = " << i
			//	<< "; j = " << j << endl;
			while (ptr[i][j] != '_') {
				v = rand() % 4;
				switch (v) {
					case 0: i++; break;
					case 1: i--; break;
					case 2: j++; break;
					case 3: j--; break;
				}
			}
			ptr[i][j] = 'p';
		}

	log << "\tEnd spawn_poison" << endl;
}