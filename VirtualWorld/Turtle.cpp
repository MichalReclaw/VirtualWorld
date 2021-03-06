#include "Turtle.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

Turtle::Turtle(World* world, int x, int y) : Animal(world,2,1,x,y,'T')
{}

void Turtle::action()
{
	int chance = rand() % 4;
	if (chance == 0) {
		Animal::action();
	}

}

bool Turtle::reproduce()
{
	Turtle* offspring = new Turtle(this->getWorld(), this->getX(), this->getY());
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

bool Turtle::collision(Organism* org)
{
	if (org->getStrength() < 5) {
		cout << "Zwierze " << org->getSymbol() << " ma mniej niz 5 sily. " << org->getSymbol() << " jego atak zostaje odparty i wraca na swoje pole" << endl;
		return false;
	}
	else {
		return this->Animal::collision(org);
	}
}
