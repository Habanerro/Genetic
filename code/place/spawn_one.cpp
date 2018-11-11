#include "header_place.hh"

void Place::spawn_one()
{
	srand( time(NULL) );
	log << "\tCome in spawn_one" << endl;
	
	int v = 0, what = 0, i = 0, j = 0, g = 0;
	int* xc = new int[all];
	int* yc = new int[all];

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

		v = rand() % g;
		what = rand() % 3;

	if (what) {
		ptr[xc[v]][yc[v]] = 'f';
	} else {
		ptr[xc[v]][yc[v]] = 'p';
	}
	delete xc;
	delete yc;
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
		if (i < 0 || i > height || j < 0 || j > lenght) {
			i = 1 + rand() % nHeight;
			j = 1 + rand() % nLenght;
		}
	}*/
	
	log << "\tEnd spawn_one" << endl;
}
