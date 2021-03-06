#pragma once
#include <string>
#include "Stack.h"
#include "Labyrinth.h"


class Robot
{
public:
	Robot();
	~ Robot();
	Robot(const Robot& _copie);
	void SetRobot(int _direction);
	int Explore(Labyrinth* entree_labyrinth);
	string getSolution();
    Square* getCurrentSquare();
private:
	Stack* pathStartToExit;
	Square* currentSquare;
	Robot* leftRobot;
	Robot* rightRobot;
	Robot* upperRobot;
	Robot* lowerRobot;
	bool foundExit;
};
