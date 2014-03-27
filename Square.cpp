#pragma once
#include <iostream>
using namespace std;

struct Square
    {
    public:

        int x;
        int y;
        char value;
        bool visited;
        Square* upperSquare;
        Square* rightSquare;
        Square* leftSquare;
		Square* lowerSquare;
    };