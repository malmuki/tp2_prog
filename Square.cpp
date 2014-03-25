#pragma once
#include <iostream>
using namespace std;

struct square
    {
    public:

        int x;
        int y;
        char value;
        bool visited;
        square* upperSquare;
        square* rightSquare;
        square* leftSquare;
        square* lowerSquare;
    };