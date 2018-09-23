#include "header_place.h"

void Place::print_place()
{
	log << "\nTo print" << endl;
		int i = 0, j = 0;
		for (i = 0; i < height; i++) {
			cout << "\n " << endl;
			for (j = 0; j < lenght; j++) {
				/*switch (ptr[i][j]) {
					case '_':	// free geks
						printf("\033[37m %c\033[0m", ptr[i][j]);
						break;

					case 'X':	// wall
						printf("\033[1m %c\033[0m", ptr[i][j]);
						break;

					case 'O':	// bot
						printf("\033[36m %c\033[0m", ptr[i][j]);
						break;

					case 'f':	// food
						printf("\033[32m %c\033[0m", ptr[i][j]);
						break;

					case 'p':	// poison
						printf("\033[31m %c\033[0m", ptr[i][j]);
						break;
				} NOT WORKED*/
				printf(" %c", ptr[i][j]); 
			}
		}
	log << "End print" << endl;
}