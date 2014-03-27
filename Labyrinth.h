#pragma once
#include <iostream>
#include "square.cpp"
using namespace std;

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