#include "../place/header_place.hh"

void population(Bot* a, unint q_bot, Predator* dat, unint q_dat)
{
	a[0].log << "\tCome in population func" << endl;
	a[0].log << "#POPULATION" << endl;

	unint i = 0, j = 0, k = 0, next = 0;
	int free = -1;
	unint g_bot = (unint)sqrt(q_bot);
	unint g_dat = (unint)sqrt(q_dat);

	a[0].log << "\t\tEvery bot must geting " << (g_bot - 1) << " childrens" << endl;
	a[0].log << "\t\tsqrt(q_bot) = " << g_bot << endl;

	ofstream pointer;
	pointer.open("live.txt", ios::app);

	// we must structurization the massive
	unint live = 0;
	a[0].log << "\t\t\tStandarization of Bot..." << endl;
	for (i = 0; i < q_bot; i++) {
		a[i].grn = 0;
		a[i].hp = 50;
		live += a[i].lp;
		a[i].lp = 50;
		a[i].x = 0;
		a[i].y = 0;
	}
	live = (unint)(live / q_bot);
	pointer << "Medium life of Bots = " << live << endl;
	a[0].log << "\t\t\t\tEnd of standarization..." << endl;
	for (i = 0; i < g_bot; i++) {
		if (a[i].flag == 0) {
			free = i;
			a[0].log << "\t\t\tfree = " << free << endl;
			for (k = free + 1; k < q_bot; k++) {
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
	for (i = 0; i < g_bot; i++) {
		next = i;
		while (next < q_bot) {
			for (int j = 0; j < a[0].gquant; j++) {
				a[next].gen[j] = a[i].gen[j];
			}
			a[next].flag = 1;
			next += g_bot;
		}
	}

	unint t = 1;
	for (i = 0; i < q_bot; i++) {
		if (!a[i].flag) {
			t = 0;
		}
	}
	a[0].log << "\t\tTrue? (" << t << ")" << endl;

	dat[0].log << "\t\tEvery Predator must geting " << (g_dat - 1) << " childrens" << endl;
	dat[0].log << "\t\tsqrt(q_dat) = " << g_dat << endl;

	// we must structurization the massive
	live = 0;
	dat[0].log << "\t\t\tStandarization of Predators..." << endl;
	for (i = 0; i < q_dat; i++) {
		dat[i].grn = 0;
		dat[i].hp = 70;
		live += dat[i].lp;
		dat[i].lp = 70;
		dat[i].x = 0;
		dat[i].y = 0;
	}
	live = (unint)(live / q_dat);
	pointer << "\tMedium life of Predators = " << live << endl;
	dat[0].log << "\t\t\t\tEnd of standarization..." << endl;
	for (i = 0; i < g_dat; i++) {
		if (dat[i].flag == 0) {
			free = i;
			dat[0].log << "\t\t\tfree = " << free << endl;
			for (k = free + 1; k < q_dat; k++) {
				if (a[k].flag == 1) {
					dat[0].log << "\t\t\tk = " << k << endl;
					for (int j = 0; j < dat[0].gquant; j++) {
						dat[free].gen[j] = dat[k].gen[j];
					}
					dat[free].flag = 1;
					dat[k].flag = 0;
				}
			}
		}
	}

	dat[0].log << "\t\tequivalence" << endl;
	for (i = 0; i < g_dat; i++) {
		next = i;
		while (next < q_dat) {
			for (int j = 0; j < dat[0].gquant; j++) {
				dat[next].gen[j] = dat[i].gen[j];
			}
			dat[next].flag = 1;
			next += g_dat;
		}
	}

	t = 1;
	for (i = 0; i < q_dat; i++) {
		if (!dat[i].flag) {
			t = 0;
		}
	}
	dat[0].log << "\t\tTrue? (" << t << ")" << endl;


	pointer.close();
	dat[0].log << "\tEND population func" << endl;
}
