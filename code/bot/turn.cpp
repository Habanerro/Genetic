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
			command = gen[grn];
			log << "\t\t\tgen[grn] = " << command << endl;
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

		switch (p -> ptr[x2][y2]) {
				case 'O':
				case 'X':
					log << "\t\t\t\tI meet bot/wall!" << endl;
					hp--;
					if (hp == 0) {
						flag = 0;
						p -> ptr[x][y] = '_';
					}
					break;
				case 'f':
					log << "\t\t\t\tI meet food!" << endl;
					p -> ptr[x2][y2] = 'O';
					p -> ptr[x][y] = '_';
					x = x2;
					y = y2;
					lp += 10;
					hp += 10;
					if (hp > 100) {
						hp = 100;
					}
					hp--;
					p -> spawn_one();
					break;
				case 'p':
					log << "\t\t\t\tI meet poison!" << endl;
					p -> ptr[x][y] = '_';
					p -> ptr[x2][y2] = '_';
					hp = 0;
					flag = 0;
					p -> spawn_one();
					break;
				case '_':
					log << "\t\t\t\tI meet free geks!" << endl;
					p -> ptr[x2][y2] = 'O';
					p -> ptr[x][y] = '_';
					x = x2;
					y = y2;
					hp--;
					if (hp == 0) {
						flag = 0;
						p -> ptr[x2][y2] = '_';
					}
					break;
			}
	} else if (command >= 32 && command <= 39) {
		log << "\t\tSmart to go" << endl;
		switch (command) {
			case 32: x2++; y2--;
				break;
			case 33: x2++;
				break;
			case 34: x2++; y2++;
				break;
			case 35: y2++;
				break;
			case 36: x2--; y2++;
				break;
			case 37: x2--;
				break;
			case 38: x2--; y2--;
				break;
			case 39: y2--;
				break;
		}
		log << "\t\t\tTo go: x2 = " << x2
			<< "; y2 = " << y2 << endl;
		switch (p -> ptr[x2][y2]) {
				case 'O':
				case 'X':
					log << "\t\t\t\tI meet bot/wall!" << endl;
					hp--;
					if (hp == 0) {
						flag = 0;
						p -> ptr[x][y] = '_';
					}
					break;
				case 'f':
					log << "\t\t\t\tI meet food!" << endl;
					p -> ptr[x2][y2] = 'O';
					p -> ptr[x][y] = '_';
					x = x2;
					y = y2;
					lp += 10;
					hp += 10;
					if (hp > 100) {
						hp = 100;
					}
					hp--;
					p -> spawn_one();
					break;
				case 'p':
					log << "\t\t\t\tI meet poison!" << endl;
					p -> ptr[x2][y2] = 'O';
					p -> ptr[x][y] = '_';
					x = x2;
					y = y2;
					lp += 10;
					hp += 10;
					if (hp > 100) {
						hp = 100;
					}
					hp--;
					p -> spawn_one();
					break;
				case '_':
					log << "\t\t\t\tI meet free geks!" << endl;
					p -> ptr[x2][y2] = 'O';
					p -> ptr[x][y] = '_';
					x = x2;
					y = y2;
					hp--;
					if (hp == 0) {
						flag = 0;
						p -> ptr[x2][y2] = '_';
					}
					break;
			}
	}

	grn++;
	if (grn >= gquant) {
		grn = grn - gquant - 1;
	}
	log << "\tEnd turn (command: " << command << ")" << endl;
}
