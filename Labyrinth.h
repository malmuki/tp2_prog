#include <iostream>
#include "square.cpp"
using namespace std;

class Labyrinth
{
public:
	 Labyrinth(string entree_fileName);
	~ Labyrinth();
	string ToString();
	square* GetStartSquare();

private:
	square* startSquare;
	square* tabSquare[20][20];

};

 Labyrinth:: Labyrinth(string entree_fileName)
{
}

 Labyrinth::~ Labyrinth()
{
}