#include "header_bot.h"

void save(Place* p, Bot* a, int z)
{
	cout << "\nAuto save!" << endl;
	
	ofstream log, save_doc;
	//log.open("log.txt");
	save_doc.open("last_save.txt");
	
	log << "\t#NEED SAVE" << endl;
	save_doc << "#ВНИМАНИЕ:\n"
			 << "#Правка документа приведет к НАРУШЕНИЮ РАБОТЫ ПРОГРАММЫ\n" << endl;

	save_doc << "population:\n" << z << endl;

	log << "\t\tSave place..." << endl;
	save_doc << "Place:\n" << endl;

	int i = 0, j = 0, h = 0, k = 0, g = 0;

	for (i = 0; i < p -> height; i++) {
		for (j = 0; j < p -> lenght; j++) {
			save_doc << p -> ptr[i][j] << " ";
		}
		save_doc << endl;
	}

	for (h = 0; h < p -> bot; h++) {
		save_doc << "\nBot[" << h << "]" << endl;
		save_doc << "x =\n" << a[h].x << "\ny =\n" << a[h].y << endl << endl;
		g = 0;
		for (k = 0; k < a[0].gquant; k++) {
			save_doc << " ";
			save_doc << a[h].gen[k];
			g++;
			if (g == 10) {
				save_doc << endl;
				g = 0;
			}
		}
		save_doc << endl;
	}
}
