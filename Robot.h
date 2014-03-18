#include "Stack.h"
#include "Labyrinth.h"
using namespace std;

class Robot
{
public:
	 Robot();
	~ Robot();
	void Explore(Labyrinth* entree_labyrinth);
	string getSolution();
private:
	Stack* pathStartToExit;
	square* currentSquare;
};

 Robot:: Robot()
{
}

 Robot::~ Robot()
{
}