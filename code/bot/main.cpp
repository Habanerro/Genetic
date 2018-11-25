#include "header_bot.hh"
#include <unistd.h>

void relationship(Place b, Bot* a, Predator* dat);
void population(Bot* a, unint q, Predator*, unint c);
void save(Place*, Bot*, int, Predator*);
int read(Place*, Bot*, int, Predator*);

int main()
{
	ofstream log_m;
	//log_m.open("log.txt");
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

	unint score_bot = 0, score_dat = 0;
	int index_bot = -1, index_dat = -1, g = 0, z = 0;
	unint q_bot = p.bot, q_dat = p.predator;

	unint deadline_bot = q_bot - (unint)sqrt(q_bot);
	unint deadline_predator = q_dat - (unint)sqrt(q_dat);

	int way = read(&p, b, &z, dat);

	if (!way) {	// new
		p.generate_place();
		p.spawn_wall();
		p.spawn_food();
		p.spawn_bot();
		p.spawn_predator();
		p.spawn_poison();
		p.print_place();
		relationship(&p, b, dat);
		save(&p, b, z, dat);
	}

	while (z < 10000) { // 10000 поколений
		score_bot = 0, score_dat = 0;

		// go while not dealine
		while (score_bot < deadline_bot || score_dat < deadline_predator) {
			for (int i = 0; i < q_bot && score_bot < deadline_bot; i++) {
				if (b[i].flag) {
					b[i].turn(&p);
					p.print_place();
					if (!b[i].flag) {
						score_bot++;
					}
				}
			}
			for (int i = 0; i < q_dat && score_dat < deadline_predator; i++) {
				if (dat[i].flag) {
					score_bot += dat[i].turn(&p, b);
					p.print_place();
					if (!dat[i].flag) {
						score_dat++;
					}
				}
			}
		}


		g = 0;
		index_bot = -1;
		// we want found first undead bot
		while (index_bot == -1 && g < q_bot) {
			if (b[g].flag) {
				index_bot = g;
			}
			g++;
		}
		// we found minimal lp with all undead bots
		for (int j = 1; j < q_bot; j++) {
			if ((b[j].lp < b[index_bot].lp) && b[j].flag) {
				index_bot = j;
			}
		}
		log_m << "&&index_bot = " << index_bot << endl;

		g = 0;
		index_dat = -1;
		// we want found first undead predator
		while (index_dat == -1 && g < q_dat) {
			if (dat[g].flag) {
				index_dat = g;
			}
			g++;
		}
		// we found minimal lp with all undead predators
		for (int j = 1; j < q_dat; j++) {
			if ((dat[j].lp < dat[index_dat].lp) && dat[j].flag) {
				index_dat = j;
			}
		}
		log_m << "&&index_bot = " << index_dat << endl;


		z++;
		b[index_bot].mutation();
		sleep(1);
		b[index_bot].mutation();
		sleep(1);
		b[index_bot].mutation();
		sleep(1);
		dat[index_dat].mutation();
		sleep(1);
		dat[index_dat].mutation();
		sleep(1);
		dat[index_dat].mutation();

		// хищники могли съесть часть ботов, пока те бездействовали
		// мог быть нарушен баланс: количество ботов могло упасть ниже
		// минимального порога, необходимого для "воскрешения" популяции
		unint diff = score_bot - deadline_bot;
		if (diff > 0) {
			// есть необходимость промежуточного воскрешения
			for (int i = 0; i < diff; i++) {
				g = 0;
				index_bot = -1;
				// we want found first dead bot
				while (index_bot == -1 && g < q_bot) {
					if (!b[g].flag) {
						index_bot = g;
					}
					g++;
				}
				// we found maximal lp with all dead bots
				for (int j = 1; j < q_bot; j++) {
					if ((b[j].lp > b[index_bot].lp) && !b[j].flag) {
						index_bot = j;
					}
				}
				b[index_bot].flag = 1;
			}
		} else if (diff < 0) {
			cout << "Error#1" << endl;
			sleep(2);
			return 0;
		}

		population(b, q_bot, dat, q_dat);
		p.generate_place();
		p.spawn_wall();
		p.spawn_food();
		p.spawn_bot();
		p.spawn_predator();
		p.spawn_poison();
		p.print_place();
		relationship(&p, b, dat);
		save(&p, b, z, dat);
		sleep(3);
	}

	return 0;
}
