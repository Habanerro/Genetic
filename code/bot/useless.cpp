#include "header_bot.hh"

Prev::Prev()
{
	useless = 0;
}

Prev::~Prev()
{
	useless = 0;
}

void Prev::put(int a)
{
	useless = a;
}

int Prev::get()
{
	return useless;
}
