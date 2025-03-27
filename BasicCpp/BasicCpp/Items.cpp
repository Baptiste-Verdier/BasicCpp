#include "Items.h"
#include <iostream>
using std::cout;

Items::Items() :
	mPrice{0},
	mName{"Apple"}
{}
Items::Items(string name, int price) :
	mPrice{price},
	mName{name}
{}

Items::~Items()
{
}

void Items::GetName() const
{
	cout << " " << mName << " \n";
}