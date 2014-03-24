#pragma once
#include <iostream>
#include "Square.cpp"
using namespace std;


class Cell
{
public:
	square* element;
	Cell* next;

	Cell(square* _element, Cell* _next);
private:
};