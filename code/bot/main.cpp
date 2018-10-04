#include "header_bot.h"
#include <unistd.h>

void relationship(cBot* a, cPlace b);
void population(Bot* a, unint q);
void save(Place*, Bot*, int);


int main()
{
	ofstream log_m;
	//log_m.open("log.txt");
	log_m << "Program:" << endl;

	// starting place
		sPlace a;
		a.lenght = 20;
		a.height = 20;
		a.bot = 9;
		a.food = 72;
		a.poison = 36;
		a.wall = 30;
		a.file = "\0";

	Place p(a);
	Bot* b = new Bot[p.bot];

	unint score = 0;
	int index = -1, g = 0, z = 0;
	unint q = p.bot;
	unint deadline = q - (unint)sqrt(q);
	int way = read(&p, b, &z);

	if (!way) {	// new
		p.generate_place();
		p.spawn_wall();
		p.spawn_food();
		p.spawn_bot();
		p.spawn_poison();
		p.print_place();
		relationship(&p, b);
		save(&p, b, z);
	}

	while (z < 4000) { // 4000 поколений
		score = 0;
		while (score < deadline) {
			for (int i = 0; i < q && score < deadline; i++) {
				if (b[i].flag) {
					b[i].turn(&p);
					p.print_place();
					if (!b[i].flag) {
						score++;
					}
				}
			}
		}	
		g = 0;
		index = -1;
		// we want found first undead bot
		while (index == -1 && g < q) {
			if (b[g].flag) {
				index = g;
			}
			g++;
		}
		// we found minimal lp with all undead bots
		for (int j = 1; j < q; j++) {
			if ((b[j].lp < b[index].lp) && b[j].flag) {
				index = j;
			}
		}
		printf("End of Pupulation %d\n", z);
		z++;
		b[index].mutation();
		population(b, q);
		// pause?
		p.generate_place();
		p.spawn_wall();
		p.spawn_food();
		p.spawn_bot();
		p.spawn_poison();
		p.print_place();
		relationship(&p, b);
		save(&p, b, z);
		sleep(3);
	}

	return 0;
}
