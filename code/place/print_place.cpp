#include "header_place.h"

void Place::print_place()
{
	log << "\tTo print" << endl;
		int i = 0, j = 0;
		for (i = 0; i < height; i++) {
			cout << "\n " << endl;
			for (j = 0; j < lenght; j++) {
				switch (ptr[i][j]) {
					case 'X':
						printf("  %c", ptr[i][j]);
						break;
					case '_':
						printf("  %c", ptr[i][j]);
						break;
					case 'O':
						printf("  %c", ptr[i][j]);
						break;
					case 'f':
						printf("  %c", ptr[i][j]);
						break;
					case 'p':
						printf("  %c", ptr[i][j]);
						break;
				}
			}
		}
		cout << endl;
	log << "\tEnd print" << endl;
}