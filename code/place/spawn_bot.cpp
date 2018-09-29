#include "header_place.h"

void Place::spawn_bot()
{
	srand( time(NULL) );
	log << "\tCome in spawn_bot(!!)" << endl;
	log << "\t\tWe waiting " << bot << " bots" << endl;
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

		for (i = 0; i < bot; i++) {
			v = rand() % g;
			while (uu[v]) {
				v = rand() % g;
			}
			
			ptr[xc[v]][yc[v]] = 'O';
			uu[v] = 1;
		}
		delete xc;
		delete yc;
		delete uu;
		/*unint nHeight = height - 2;
		unint nLenght = lenght - 2;

		// we divide place on four fourth
		unint lmid = nLenght / 2;
		unint hmid = nHeight / 2;
		unint fourth = 0;

		log << "\t\t\tnHeight = " << nHeight
			<< "; nLenght = " << nLenght << endl;
		log << "\t\t\tHeight_mid = " << hmid
			<< "; Lenght_mid = " << lmid << endl;

		for (g = 0; g < bot; g++) {
			i = 1 + rand() % nHeight;
			j = 1 + rand() % nLenght;
				if (i > hmid) {
					if (j > lmid) {fourth = 4;} else {fourth = 3;}
				} else {
					if (j > lmid) {fourth = 1;} else {fourth = 2;}
				}
			//log << "\t\t\ti = " << i
			//	<< "; j = " << j << endl;
			while (ptr[i][j] != '_') {
				v = rand() % 2;
				switch (fourth) {
					case 1:
						if (v) {i++;} else {j--;}
						break;
					case 2:
						if (v) {i++;} else {j++;}
						break;
					case 3:
						if (v) {i--;} else {j++;}
						break;
					case 4:
						if (v) {i--;} else {j--;}
						break;
				}
				if (i < 0 || i > height || j < 0 || j > lenght) {
					i = 1 + rand() % nHeight;
					j = 1 + rand() % nLenght;
				}
			}
			ptr[i][j] = 'O';
		}*/
	log << "\tEnd spawn_bot" << endl;
}
