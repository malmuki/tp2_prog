#include <iostream>
#include "Square.cpp"
using namespace std;


class Cell
{
public:
	square* element;
	Cell* next;

	Cell(square* entree_element, Cell* entree_next);
private:
};