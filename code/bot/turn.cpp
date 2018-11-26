#include "../place/header_place.hh"

void Bot::turn(Place* p)
{
	srand( time(NULL) );
	log << "\tTurn (x = " << x << "; y = " << y << ")" << endl;

	unint score = 0, cycle = 0, max = 3;	// anticycle
	unint xl, yl;	// coordinates for look
	unint xg, yg;	// coordinate for go
	unint command;	// command for doing

	command = gen[grn];
	xl = x; yl = y;
	xg = x; yg = y;
	score = 0;
	log << "\t\tcommand = " << command << "; grn = " << grn << endl;
	log	<< "\t\txlook = " << xl << "; ylook = " << yl << endl;
	log	<< "\t\txgo = " << xg << "; ygo " << yg << endl;

	while (((command >= 0 && command <= 7) || (command >= 16 && command <= 31)) && cycle == 0) {
		if (command >= 0 && command <= 7) {
			xl = x;
			yl = y;
			log << "\t\t\tLook (" << command << ")" << endl;
			switch (command) {
				case 0: xl++; yl--; break;
				case 1: xl++; break;
				case 2: xl++; yl++; break;
				case 3: yl++; break;
				case 4: xl--; yl++; break;
				case 5: xl--; break;
				case 6: xl--; yl--; break;
				case 7: yl--; break;
			}
			switch (p -> ptr[xl][yl]) {
				case '_': grn += 1; break;
				case 'f': grn += 2; break;
				case 'p': grn += 3; break;
				case 'X': grn += 4; break;
				case 'O': grn += 5; break;
				case '#': grn += 6; break;
			}
			if (grn > gquant) {
				grn = grn - gquant - 1;
			} else if (grn == gquant) {
				grn = 0;
			}
			command = gen[grn];
			log << "\t\t\tLook: grn -> " << grn
				<< "; command -> " << command << endl;
			
			score++;
			if (score == max) {
				log << "\t#CYCLE" << endl;
				cycle = 1;
			}
		} else {
			log << "\t\t\tTo go (" << command << ")" << endl;
			grn += command;
			if (grn > gquant) {
				grn = grn - gquant - 1;
			} else if (grn == gquant) {
				grn = 0;
			}
			command = gen[grn];
			log << "\t\t\tTo go: grn -> " << grn
				<< "; command -> " << command << endl;

			score++;
			if (score == max) {
				log << "\t#CYCLE" << endl;
				cycle = 1;
			}
		}

		if (cycle == 1) {
			grn = grn + rand() % max;
			if (grn > gquant) {
				grn = grn - gquant - 1;
			} else if (grn == gquant) {
				grn = 0;
			}
			command = gen[grn];
			score = 0;
			cycle = 0;
			xl = x;
			yl = y;
			log << "\t\t\tRestart: grn -> " << grn
				<< "; command -> " << command << endl;
		}
	}

	if (command >= 8 && command <= 15) {
		log << "\t\tSimple: " << command << endl;
		switch (command) {
			case 8: xg++; yg--; break;
			case 9: xg++; break;
			case 10: xg++; yg++; break;
			case 11: yg++; break;
			case 12: xg--; yg++; break;
			case 13: xg--; break;
			case 14: xg--; yg--; break;
			case 15: yg--; break;
		}
		switch (p -> ptr[xg][yg]) {
			case 'O': case 'X': case '#':
				hp--;
				if (hp == 0) {
					flag = 0;
					p -> ptr[x][y] = '_';
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				}
				break;

			case 'f':
				lp += 10;
				hp += 10;
				if (hp > 100) {
					hp = 100;
				}
				p -> ptr[x][y] = '_';
				p -> ptr[xg][yg] = 'O';
				x = xg;
				y = yg;
				hp--;
				p -> spawn_one();
				break;

			case 'p':
				hp = 0;
				flag = 0;
				p -> ptr[x][y] = '_';
				log << "\t\t\tgo out: x = " << x
					<< "; y = " << y << endl;
				break;

			case '_':
				hp--;
				if (hp == 0) {
					flag = 0;
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				} else {
					p -> ptr[xg][yg] = 'O';
				}
				p -> ptr[x][y] = '_';
				x = xg;
				y = yg;
			 	break;
		}
	} else if (command >= 32 && command <= 39) {
		log << "\t\tSmart: " << command << endl;
		switch (command) {
			case 32: xg++; yg--; break;
			case 33: xg++; break;
			case 34: xg++; yg++; break;
			case 35: yg++; break;
			case 36: xg--; yg++; break;
			case 37: xg--; break;
			case 38: xg--; yg--; break;
			case 39: yg--; break;
		}
		switch (p -> ptr[xg][yg]) {
			case 'O': case 'X': case '#':
				hp--;
				if (hp == 0) {
					flag = 0;
					p -> ptr[x][y] = '_';
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				}
				break;

			case 'f': case 'p':
				lp += 10;
				hp += 10;
				if (hp > 100) {
					hp = 100;
				}
				p -> ptr[x][y] = '_';
				p -> ptr[xg][yg] = 'O';
				x = xg;
				y = yg;
				hp--;
				p -> spawn_one();
				break;

			case '_':
				hp--;
				if (hp == 0) {
					flag = 0;
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				} else {
					p -> ptr[xg][yg] = 'O';
				}
				p -> ptr[x][y] = '_';
				x = xg;
				y = yg;
			 	break;
		}
	} else {
		log << "\tOUTSIDE: " << command << endl;
	}

	grn++;
	if (grn > gquant) {
		grn = grn - gquant - 1;
	} else if (grn == gquant) {
		grn = 0;
	}
	
	log << "\tEnd turn!" << endl;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

int Predator::turn(Place* p, Bot* b)
{
	srand( time(NULL) );
	log << "\tPredator's turn (x = " << x << "; y = " << y << ")" << endl;

	unint score = 0, cycle = 0, max = 3;	// anticycle
	unint xl, yl;	// coordinates for look
	unint xg, yg;	// coordinate for go
	unint command;	// command for doing
	unint search = 0, getBack = 0;

	command = gen[grn];
	xl = x; yl = y;
	xg = x; yg = y;
	score = 0;
	log << "\t\tcommand = " << command << "; grn = " << grn << endl;
	log	<< "\t\txlook = " << xl << "; ylook = " << yl << endl;
	log	<< "\t\txgo = " << xg << "; ygo " << yg << endl;

	while (((command >= 0 && command <= 7) || (command >= 16 && command <= 31)) && cycle == 0) {
		if (command >= 0 && command <= 7) {
			xl = x;
			yl = y;
			log << "\t\t\tLook (" << command << ")" << endl;
			switch (command) {
				case 0: xl++; yl--; break;
				case 1: xl++; break;
				case 2: xl++; yl++; break;
				case 3: yl++; break;
				case 4: xl--; yl++; break;
				case 5: xl--; break;
				case 6: xl--; yl--; break;
				case 7: yl--; break;
			}
			switch (p -> ptr[xl][yl]) {
				case '_': grn += 1; break;
				case 'f': grn += 2; break;
				case 'p': grn += 3; break;
				case 'X': grn += 4; break;
				case 'O': grn += 5; break;
				case '#': grn += 6; break;
			}
			if (grn > gquant) {
				grn = grn - gquant - 1;
			} else if (grn == gquant) {
				grn = 0;
			}
			command = gen[grn];
			log << "\t\t\tLook: grn -> " << grn
				<< "; command -> " << command << endl;
			
			score++;
			if (score == max) {
				log << "\t#CYCLE" << endl;
				cycle = 1;
			}
		} else {
			log << "\t\t\tTo go (" << command << ")" << endl;
			grn += command;
			if (grn > gquant) {
				grn = grn - gquant - 1;
			} else if (grn == gquant) {
				grn = 0;
			}
			command = gen[grn];
			log << "\t\t\tTo go: grn -> " << grn
				<< "; command -> " << command << endl;

			score++;
			if (score == max) {
				log << "\t#CYCLE" << endl;
				cycle = 1;
			}
		}

		if (cycle == 1) {
			grn = grn + rand() % max;
			if (grn > gquant) {
				grn = grn - gquant - 1;
			} else if (grn == gquant) {
				grn = 0;
			}
			command = gen[grn];
			score = 0;
			cycle = 0;
			xl = x;
			yl = y;
			log << "\t\t\tRestart: grn -> " << grn
				<< "; command -> " << command << endl;
		}
	}

	if (command >= 8 && command <= 15) {
		log << "\t\tSimple: " << command << endl;
		switch (command) {
			case 8: xg++; yg--; break;
			case 9: xg++; break;
			case 10: xg++; yg++; break;
			case 11: yg++; break;
			case 12: xg--; yg++; break;
			case 13: xg--; break;
			case 14: xg--; yg--; break;
			case 15: yg--; break;
		}
		switch (p -> ptr[xg][yg]) {
			case 'X': case '#':
				hp--;
				if (hp == 0) {
					flag = 0;
					p -> ptr[x][y] = '_';
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				}
				break;

			case 'f':
				lp += 10;
				hp += 10;
				if (hp > 100) {
					hp = 100;
				}
				p -> ptr[x][y] = '_';
				p -> ptr[xg][yg] = '#';
				x = xg;
				y = yg;
				hp--;
				p -> spawn_one();
				break;

			case 'p':
				hp = 0;
				flag = 0;
				p -> ptr[x][y] = '_';
				log << "\t\t\tgo out: x = " << x
					<< "; y = " << y << endl;
				break;

			case '_':
				hp--;
				if (hp == 0) {
					flag = 0;
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				} else {
					p -> ptr[xg][yg] = '#';
				}
				p -> ptr[x][y] = '_';
				x = xg;
				y = yg;
			 	break;

			 case 'O':
			 	lp += 30;
				hp += 30;
				if (hp > 100) {
					hp = 100;
				}
				p -> ptr[x][y] = '_';
				p -> ptr[xg][yg] = '#';
				x = xg;
				y = yg;
				hp--;
				// search bot with xg and yg coordinates
				for (search = 0; search < p -> bot; search++) {
					if (b[search].x == xg && b[search].y == yg) {
						b[search].flag = 0;
						getBack = 1;
						log << "\t\t\tOverkill: (" << search
							<< ") x = " << xg << "y = " << yg
							<< "flag = " << b[search].flag << endl;
					}
				}
			 	break;
		}
	} else if (command >= 32 && command <= 39) {
		log << "\t\tSmart: " << command << endl;
		switch (command) {
			case 32: xg++; yg--; break;
			case 33: xg++; break;
			case 34: xg++; yg++; break;
			case 35: yg++; break;
			case 36: xg--; yg++; break;
			case 37: xg--; break;
			case 38: xg--; yg--; break;
			case 39: yg--; break;
		}
		switch (p -> ptr[xg][yg]) {
			case 'X': case '#':
				hp--;
				if (hp == 0) {
					flag = 0;
					p -> ptr[x][y] = '_';
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				}
				break;

			case 'f': case 'p':
				lp += 10;
				hp += 10;
				if (hp > 100) {
					hp = 100;
				}
				p -> ptr[x][y] = '_';
				p -> ptr[xg][yg] = '#';
				x = xg;
				y = yg;
				hp--;
				p -> spawn_one();
				break;

			case '_':
				hp--;
				if (hp == 0) {
					flag = 0;
					log << "\t\t\tgo out: x = " << x
						<< "; y = " << y << endl;
				} else {
					p -> ptr[xg][yg] = '#';
				}
				p -> ptr[x][y] = '_';
				x = xg;
				y = yg;
			 	break;

			 case 'O':
			 	lp += 30;
				hp += 30;
				if (hp > 100) {
					hp = 100;
				}
				p -> ptr[x][y] = '_';
				p -> ptr[xg][yg] = '#';
				x = xg;
				y = yg;
				hp--;
				// search bot with xg and yg coordinates
				for (search = 0; search < p -> bot; search++) {
					if (b[search].x == xg && b[search].y == yg) {
						b[search].flag = 0;
						getBack = 1;
						log << "\t\t\tOverkill: (" << search
							<< ") x = " << xg << "y = " << yg
							<< "flag = " << b[search].flag << endl;
					}
				}
			 	break;
		}
	} else {
		log << "\tOUTSIDE: " << command << endl;
	}

	grn++;
	if (grn > gquant) {
		grn = grn - gquant - 1;
	} else if (grn == gquant) {
		grn = 0;
	}
	
	log << "\tEnd Predator's turn!" << endl;
	return getBack;
}
