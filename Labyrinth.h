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
        square* GetStartSquare();

    private:
        square* startSquare;
        square* tabSquare[20][20];
    };