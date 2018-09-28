#include "header_bot.h"

void Bot::turn(Place* p)
{
	log << "\tTurn (x = " << x << "; y = " << y << ")" << endl;

	unint command = gen[grn];	// summaty command
	log << "\t\tgen[grn] = " << command << endl;
	log << "\t\tgrn = " << grn << endl;
		// 7 < command < 16 || 31 < command < 40

	unint x2 = x;	// coordinates for lookup geks
	unint y2 = y;	// on the place

	while((command > -1 && command < 8) || (command > 15 && command < 32)) {
		if (command >= 0 && command <= 7) {
			x2 = x;
			y2 = y;
			// to make coordintes for lookup
			switch(command) {
				case 0: x2++; y2--;
					break;
				case 1: x2++;
					break;
				case 2: x2++; y2++;
					break;
				case 3: y2++;
					break;
				case 4: x2--; y2++;
					break;
				case 5: x2--;
					break;
				case 6: x2--; y2--;
					break;
				case 7: y2--;
					break;
			}
			log << "\t\t\tLookup: x2 = " << x2
				<< "; y2 = " << y2 << endl;
			// lookup on the place
			switch (p -> ptr[x2][y2]) {
				case 'O':
					grn += 5;
					break;
				case 'X':
					grn += 4;
					break;
				case 'f':
					grn += 2;
					break;
				case 'p':
					grn += 3;
					break;
				case '_':
					grn += 1;
					break;
			}
			if (grn >= gquant) {
				grn = grn - gquant - 1;
			}
			log << "\t\t\tgrn = " << grn << endl;
			command = gen[grn];
			log << "\t\t\tgen[grn] = " << command << endl;

		} else if (command >= 16 && command <= 31) {
			grn += command;
			log << "\t\t\tgrn = " << grn << endl;
			if (grn >= gquant) {
				grn = grn - gquant - 1;
				log << "\t\t\tgrn = " << grn << endl;
			}
			log << "\t\t\tgen[grn] = " << command << endl;
			command = gen[grn];
		}
	}

	x2 = x;
	y2 = y;

	// ready to go
	if (command >= 8 && command <= 15) {
		log << "\t\tSimple to go" << endl;
		switch (command) {
			case 8: x2++; y2--;
				break;
			case 9:	x2++;
				break;
			case 10: x2++; y2++;
				break;
			case 11: y2++;
				break;
			case 12: x2--; y2++;
				break;
			case 13: x2--;
				break;
			case 14: x2--; y2--;
				break;
			case 15: y2--;
				break;
		}
		log << "\t\t\tTo go: x2 = " << x2
			<< "; y2 = " << y2 << endl;
	}

	log << "\tEnd turn (command: " << command << ")" << endl;
}
