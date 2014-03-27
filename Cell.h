#pragma once
#include <iostream>
#include "Square.cpp"
using namespace std;

class Cell
    {
    public:
        Square* element;
        Cell* next;

        Cell(Square* _element, Cell* _next);
    private:

    };