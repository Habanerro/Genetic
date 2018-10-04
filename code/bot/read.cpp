#include "header_bot.h"
#include <unistd.h>

int read(Place* p, Bot* a, int* z)
{
	system("cls");
	cout << "Hello!\n"
		<< "New or Continue? (n/c)" << endl;

	char c[2];
	c[0] = -1;
	c[1] = 0;
	int flag = 0;

	while (flag == 0) {
		scanf("%s", c);
		if ((c[0] == 'n' || c[0] == 'N') && c[1] == 0) {
			return 0;
		} else if ((c[0] == 'c' || c[0] == 'C') && c[1] == 0) {
			flag = 1;
		}
	}

	ifstream ifs;
	ifs.open("last_save.txt", ios::in);
	if (!ifs.is_open()) {
		cerr << "Error: file not found!\nNew game after 3 second..." << endl;
		sleep(3);
		return 0;
	}

	// russian language
	// Мы предупредили о невозможности изменения документа last_save.txt
	// Любое изменение - на свой страх и риск
	// мы точно знаем с каких строк начинать считывание
	// Так например:
	// Популяцию считать на 5 строке (на 4, если с 0)
	// поле начинается на 8 строке (на 7 если с 0)
	// оно займет строк = p -> height
	// после последней строки поля надо отступить 3 строки, и считать x
	// ... -> полное отсутствие проверок - только чтение!!

	int num = 1;
	char cbuf = 0;
	string buf;
	int i = 0, j = 0, k = 0, g = 0;


	// population
		for (i = 0; i < 4; i++) {
			getline(ifs, buf);
		}
		ifs >> num;
		*z = num;
		cout << "Population = " << *z << endl;

	// place
		getline(ifs, buf);
		getline(ifs, buf);
		getline(ifs, buf);

		cout << "\nPlace:\n" << endl;
		for (i = 0; i < p -> height; i++) {
			getline(ifs, buf);
			for (j = 0; j < p -> lenght; j++) {
				cbuf = buf[j * 2];
				p -> ptr[i][j] = cbuf;
				//cout << p -> ptr[i][j];
			}
			cout << buf << endl;
		}

	// bots
		for (k = 0; k < p -> bot; k++) {
			getline(ifs, buf);
			getline(ifs, buf);
			getline(ifs, buf);
			getline(ifs, buf);
			ifs >> num;
			a[k].x = num;
			getline(ifs, buf);
			getline(ifs, buf);
			ifs >> num;
			a[k].y = num;
			cout << "\nBot " << k << " x = " << a[k].x << " y = " << a[k].y << endl << endl;
			getline(ifs, buf);
			getline(ifs, buf);
			for (i = 0; i < a[0].gquant; i++) {
				ifs >> num;
				a[k].gen[i] = num;
			}
			g = 0;
			for (j = 0; j < a[0].gquant; j++) {
				cout << " ";
				cout << a[k].gen[j];
				g++;
				if (g == 10) {
					cout << endl;
					g = 0;
				}
			}
			cout << endl;
			getline(ifs, buf);
		}
	sleep(5);
	return 1;
}
