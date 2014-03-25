#include <iostream>
#include "Cell.h"
using namespace std;

Cell::Cell(square* _element, Cell* _next)
    {
    element = _element;
    next = _next; 
    }