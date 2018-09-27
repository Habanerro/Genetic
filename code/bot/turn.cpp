#include "header_bot.h"

int Bot::turn(Place* p)
{
	log << "\tTurn (x = " << x << "; y = " << y << ")" << endl;

	unint command = gen[grn];	// summaty command
	log << "\t\tgen[gnr] = " << command << endl;
		// 7 < command < 16 || 31 < command < 40

	while (command >= 0 && command <= 7) {
		switch(command) {
			case 0:
				// x++ y--
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
		}
	}

	log << "\tEnd turn (command: " << command << ")" << endl;
}