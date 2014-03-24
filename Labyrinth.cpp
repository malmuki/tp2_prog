#include <iostream>
#include <fstream>
#include <string>
#include "Labyrinth.h"

using namespace std;

Labyrinth:: Labyrinth(string _fileName)
    {
    ifstream input(_fileName) ;

    if(input)
        {
        for(int i =0;i<19;i++)
            {
            for(int j =0;j<19;j++)
                {
                tabSquare[i][j] = new square;
                tabSquare[i][j]->visited = false;

                 tabSquare[i][j]->x = j;
                 tabSquare[i][j]->y = i;
                input >>  tabSquare[i][j]->value ;
                if( tabSquare[i][j]->value == 'D' )
                    {
                    startSquare =  tabSquare[i][j];
                    }
                }
            }
        for(int i =0;i<19;i++)
            {
            for(int j =0;j<19;j++)
                {

                if(tabSquare[i][j] -> value != 'X')
                    {
                    tabSquare[i][j] -> upperSquare = tabSquare[i-1][j];
                    tabSquare[i][j] -> lowerSquare = tabSquare[i+1][j];
                    tabSquare[i][j] -> leftSquare = tabSquare[i][j+1];
                    tabSquare[i][j] -> upperSquare = tabSquare[i-1][j-1];
                    }
                }
            }
        }
    input.close();
    }

Labyrinth::~ Labyrinth()
    {
    }

string Labyrinth::ToString()
    {
    string output;
    for(int i =0;i<19;i++)
        {
        for(int j =0;j<19;j++)
            {
           output += tabSquare[i][j] -> value;
            }
        output += "\n";
        }
    return output;
    };

square* Labyrinth::GetStartSquare()
    {
    return startSquare;
    };