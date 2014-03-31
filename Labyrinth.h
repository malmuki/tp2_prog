#pragma once
#include <iostream>
#include "square.cpp"

class Labyrinth
{
public:
	Labyrinth(string _fileName);
	~ Labyrinth();
	string ToString();
	Square* GetStartSquare();

private:
	Square* startSquare;
	Square* tabSquare[20][20];
};