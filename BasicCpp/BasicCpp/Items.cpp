#include "Items.h"
Items::Items() :
	mPrice{0},
	mName{"Apple"}
{}
Items::Items(string name, int price) :
	mPrice{0},
	mName{name}
{}

Items::~Items()
{
}
