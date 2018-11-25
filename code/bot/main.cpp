#include "header_bot.hh"
#include <unistd.h>

void relationship(Place b, Bot* a, Predator* dat);
void population(Bot* a, unint q);
void save(Place*, Bot*, int);
int read(Place*, Bot*, int);

int main()
{
	ofstream log_m;
	log_m.open("log.txt");
	log_m << "Program:" << endl;

	// starting place
		sPlace a;
		a.lenght = 28;
		a.height = 21;
		a.bot = 36;
		a.predator = 16;
		a.food = 110;
		a.poison = 70;
		a.wall = 20;
		a.file = "\0";

	Place p(a);
	Bot* b = new Bot[p.bot];
	Predator* dat = new Predator[p.predator];

	unint score = 0;
	int index = -1, g = 0, z = 0;
	unint q_bot = p.bot, q_dat = p.predator;
	unint deadline_bot = q_bot - (unint)sqrt(q_bot);
	unint deadline_predator = q_dat - (unint)sqrt(q_dat);
	int way = read(&p, b, &z);

	if (!way) {	// new
		p.generate_place();
		p.spawn_wall();
		p.spawn_food();
		p.spawn_bot();
		p.spawn_predator();
		p.spawn_poison();
		p.print_place();
		relationship(&p, b, dat);
		save(&p, b, z);
	}

	while (z < 10000) { // 10000 поколений
		score = 0;
		while (score < deadline_bot) {
			for (int i = 0; i < q_bot && score < deadline_bot; i++) {
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
		while (index == -1 && g < q_bot) {
			if (b[g].flag) {
				index = g;
			}
			g++;
		}
		// we found minimal lp with all undead bots
		for (int j = 1; j < q_bot; j++) {
			if ((b[j].lp < b[index].lp) && b[j].flag) {
				index = j;
			}
		}
		printf("End of Pupulation %d\n", z);
		z++;
		b[index].mutation();
		b[index].mutation();
		b[index].mutation();

		population(b, q_bot);
		p.generate_place();
		p.spawn_wall();
		p.spawn_food();
		p.spawn_bot();
		p.spawn_predator();
		p.spawn_poison();
		p.print_place();
		relationship(&p, b, dat);
		save(&p, b, z);
		sleep(3);
	}

	return 0;
}
