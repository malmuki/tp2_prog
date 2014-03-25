#include "Robot.h"

using namespace std;

Robot:: Robot()
    {
    pathStartToExit = new Stack;
    }

Robot:: ~Robot()
    {
    }

void Robot::Explore(Labyrinth* _labyrinth)
    {
    bool intersection = false;
    int cheminsPossibles = 0;
    bool leftValid = false;
    bool rightValid = false;
    bool upperValid = false;
    bool lowerValid = false;
    currentSquare = _labyrinth->GetStartSquare();
    pathStartToExit->Push(currentSquare);

    while(intersection = false)
        {
        if(currentSquare->leftSquare->value != 'X' && currentSquare->leftSquare->visited == false)
            {
            cheminsPossibles++;
            leftValid = true;
            }

        if(currentSquare->upperSquare->value != 'X' && currentSquare->upperSquare->visited == false)
            {
            cheminsPossibles++;
            upperValid = true;
            }

        if(currentSquare->lowerSquare->value != 'X' && currentSquare->lowerSquare->visited == false)
            {
            cheminsPossibles++;
            lowerValid = true;
            }

        if(currentSquare->rightSquare->value != 'X' && currentSquare->rightSquare->visited == false)
            {
            cheminsPossibles++;
            rightValid = true;
            }

        if(cheminsPossibles>1)
            {
            for(int i = 0; i < cheminsPossibles-1; i++)
                {
                //robot nouveauRobot = new Robot(this);
                //nouveauRobot.explore(_labyrinth);
                }
            //delete this;
            }
        else if(cheminsPossibles==1)
            {
            if(leftValid == true)
                {
                currentSquare->visited = true;
                currentSquare = currentSquare->leftSquare;
                pathStartToExit->Push(currentSquare);
                }

            if(upperValid == true)
                {
                currentSquare->visited = true;
                currentSquare = currentSquare->upperSquare;
                pathStartToExit->Push(currentSquare);
                }

            if(lowerValid == true)
                {
                currentSquare->visited = true;
                currentSquare = currentSquare->lowerSquare;
                pathStartToExit->Push(currentSquare);
                }

            if(rightValid == true)
                {
                currentSquare->visited = true;
                currentSquare = currentSquare->rightSquare;
                pathStartToExit->Push(currentSquare);
                }
            }
        else
            {
            delete this;
            }
        }
    }

string Robot::getSolution()
    {
    return pathStartToExit -> ToStringReverse();
    }