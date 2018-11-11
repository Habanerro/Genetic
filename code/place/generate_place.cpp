#include "header_place.hh"

void Place::generate_place()
{
	log << "\tCome in func generate_place" << endl;

	int i = 0, j = 0;

	// to create basis
	log << "\t\tTo start allocation memory for place" << endl;
	for (i = 0; i < height; i++) {
		for (j = 0; j < lenght; j++) {
			ptr[i][j] = '_';	// free geks
		}
	}
	// information for log_place.txt
		log << "\t\t\tlenght = " << lenght << "\n";
		log << "\t\t\theight = " << height << "\n";
		log << "\t\t\tall = " << all << "\n";
		log << "\t\t\tbot = " << bot << "\n";
		log << "\t\t\tfood = " << food << "\n";
		log << "\t\t\tpoison = " << poison << "\n";
		log << "\t\t\twall = " << wall << endl;
	log << "\t\tThe end of memory allocation" << endl;

	// to create fencing
	log << "\t\tStart: fencing" << endl;
		log << "\t\t\tbegin border up" << "\n";
			for (i = 0, j = 0; j < lenght; j++) {
				ptr[i][j] = 'X';	// wall
			}
		log << "\t\t\t\tend border up" << endl;

		log << "\t\t\tbegin border right" << "\n";
			for (i = 0, j = lenght - 1; i < height; i++) {
				ptr[i][j] = 'X';	// wall
			}
		log << "\t\t\t\tend border right" << endl;

		log << "\t\t\tbegin border left" << "\n";
			for (i = 0, j = 0; i < height; i++) {
				ptr[i][j] = 'X';	// wall
			}
		log << "\t\t\t\tend border left" << endl;

		log << "\t\t\tbegin border down" << "\n";
			for (i = height - 1, j = 0; j < lenght; j++) {
				ptr[i][j] = 'X';	// wall
			}
		log << "\t\t\t\tend border down" << endl;
	log << "\t\tEnd: fencing" << endl;

	log << "\tEnd function generate_place" << endl;
}
