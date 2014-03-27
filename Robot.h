#pragma once
#include "Stack.h"
#include "Labyrinth.h"
#include <string>

using namespace std;

class Robot
{
public:
	Robot();
	~ Robot();
	Robot(const Robot& _copie);
	void Explore(Labyrinth* entree_labyrinth);
	string getSolution();
private:
	Stack* pathStartToExit;
	Square* currentSquare;
};
