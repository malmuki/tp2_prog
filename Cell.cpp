#include <iostream>
#include "Cell.h"
using namespace std;

Cell::Cell(Square* _element, Cell* _next)
    {
    element = _element;
    next = _next; 
    }