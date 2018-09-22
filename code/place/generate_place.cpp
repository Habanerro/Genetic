#include "header_place.h"

void Place::generate_place()
{
	log << "\tCome in func generate_place" << endl;

	int i = 0, j = 0;

	// to create basis
	log << "\t\tTo start allocation memory for place" << endl;
		ptr = new char*[height];
		for (i = 0; i < height; i++) {
			ptr[i] = new char[lenght];
			for (j = 0; j < lenght; j++) {
				ptr[i][j] = '_';	// free geks
			}
		}
	log << "\t\tThe end of memory allocation" << endl;

	// to create fencing
	log << "\t\tTo create fencing" << endl;
}