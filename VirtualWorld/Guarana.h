#pragma once
#include "Plant.h"
class Guarana :
	public Plant
{
public:
	Guarana(World* world, int x, int y, bool canMove);
	~Guarana();
	bool reproduce();
	bool collision();
};

