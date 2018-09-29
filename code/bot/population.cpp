#include "header_bot.h"

void population(Bot* a, unint q)
{
	a[0].log << "\tCome in population func" << endl;
	a[0].log << "#POPULATION" << endl;

	unint i = 0, j = 0, k = 0, next = 0;
	int free = -1;
	unint g = (unint)sqrt(q);

	a[0].log << "\t\tEvery bot must geting " << (g - 1) << " childrens" << endl;
	a[0].log << "\t\tsqrt(q) = " << g << endl;

	ofstream pointer;
	pointer.open("live.txt", ios::app);

	// we must structurization the massive
	unint live = 0;
	a[0].log << "\t\t\tStandarization..." << endl;
	for (i = 0; i < q; i++) {
		a[i].grn = 0;
		a[i].hp = 50;
		live += a[i].lp;
		a[i].lp = 50;
		a[i].x = 0;
		a[i].y = 0;
	}
	live = (unint)(live / q);
	pointer << "Middle live pointers = " << live << endl;
	a[0].log << "\t\t\t\tEnd of standarization..." << endl;
	for (i = 0; i < g; i++) {
		if (a[i].flag == 0) {
			free = i;
			a[0].log << "\t\t\tfree = " << free << endl;
			for (k = free + 1; k < q; k++) {
				if (a[k].flag == 1) {
					a[0].log << "\t\t\tk = " << k << endl;
					for (int j = 0; j < a[0].gquant; j++) {
						a[free].gen[j] = a[k].gen[j];
					}
					a[free].flag = 1;
					a[k].flag = 0;
				}
			}
		}
	}

	a[0].log << "\t\tequivalence" << endl;
	for (i = 0; i < g; i++) {
		next = i;
		while (next < q) {
			for (int j = 0; j < a[0].gquant; j++) {
				a[next].gen[j] = a[i].gen[j];
			}
			a[next].flag = 1;
			next += g;
		}
	}

	unint t = 1;
	for (i = 0; i < q; i++) {
		if (!a[i].flag) {
			t = 0;
		}
	}
	a[0].log << "\t\tTrue? (" << t << ")" << endl;
	pointer.close();

	a[0].log << "\tEND population func" << endl;
}
