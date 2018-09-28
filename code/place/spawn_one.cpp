#include "header_place.h"

void Place::spawn_one()
{
	srand( time(NULL) );
	log << "\tCome in spawn_one" << endl;
	
	int v = 0;
	unint nHeight = height - 2;
	unint nLenght = lenght - 2;

		// we divide place on four fourth
	unint lmid = nLenght / 2;
	unint hmid = nHeight / 2;
    unint fourth = 0;

		log << "\t\t\tnHeight = " << nHeight
			<< "; nLenght = " << nLenght << endl;
		log << "\t\t\tHeight_mid = " << hmid
			<< "; Lenght_mid = " << lmid << endl;

	unint what = rand() % 3;
	unint i = 1 + rand() % nHeight;
	unint j = 1 + rand() % nLenght;

	if (i > hmid) {
		if (j > lmid) {fourth = 4;} else {fourth = 3;}
	} else {
		if (j > lmid) {fourth = 1;} else {fourth = 2;}
	}
	
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
	}
	if (what) {
		// food
		ptr[i][j] = 'f';
	} else {
		// poison
		ptr[i][j] = 'p';
	}
	log << "\tEnd spawn_one" << endl;
}
