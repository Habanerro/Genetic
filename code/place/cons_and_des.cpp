#include "header_place.hh"

Place::Place(sPlace a)
{
	lenght = a.lenght;
	height = a.height;
	all = lenght * height;
	bot = a.bot;
	predator = a.predator;
	food = a.food;
	poison = a.poison;
	wall = a.wall;
	file = a.file;

	ptr = new char*[height];
	for (int i = 0; i < height; i++) {
		ptr[i] = new char[lenght];
	}
	//log.open("log.txt", ios::app);
	log << "\t*--normal constructor-place-*" << endl;
}

Place::Place()
{
	lenght = 0;
	height = 0;
	all = 0;
	bot = 0;
	predator = 0;
	food = 0;
	poison = 0;
	wall = 0;
	file = "\0";

	char** ptr = NULL;
	log.open("log.txt", ios::app);
	log << "\t*--default constructor-place-*" << endl;
}

Place::~Place()
{
	lenght = 0;
	height = 0;
	all = 0;
	bot = 0;
	predator = 0;
	food = 0;
	poison = 0;
	wall = 0;
	file = "\0";

	delete ptr;
	log << "\t*--destructor-place-*" << endl;
	log.close();
}
