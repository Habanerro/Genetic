#include "header_place.h"

Place::Place(sPlace a)
{
	lenght = a.lenght;
	height = a.height;
	all = lenght * height;
	bot = a.bot;
	food = a.food;
	poison = a.poison;
	wall = a.wall;
	file = a.file;

	char** ptr = NULL; 
}

Place::~Place()
{
	lenght = 0;
	height = 0;
	all = 0;
	bot = 0;
	food = 0;
	poison = 0;
	wall = 0;
	file = "\0";

	delete ptr;
}