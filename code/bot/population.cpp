#include "header_bot.h"

Bot* population(Bot* a, unint q)
{
	a[0].log << "\tCome in population func" << endl;

	unint i = 0, j = 0, k = 0, v = 0;
	unint g = (unint)sqrt(q);
	Bot* b = new Bot[q];
	a[0].log << "\t\tsqrt(q) = " << g << endl;

	for (i = 0; i < q; i++) {
		if (a[i].flag) {
			a[0].log << "\t\tWe found undead bot!" << endl;
			k = j;
			for (v = 0; v < g; v++) {
				b[k].grn = a[i].grn;
				b[k].hp = a[i].hp;
				b[k].lp = a[i].lp;
				b[k].flag = 1;
				b[k].gen = a[i].gen;
				a[0].log << "\t\t\tb[" << k << "] = a[" << i << "]" << endl;
				k += g;
			}
			j++;
			a[0].log <<"\t\tj = " << j << endl;
		}
	}
	return b;

	a[0].log << "\tEnd population func" << endl;
}
