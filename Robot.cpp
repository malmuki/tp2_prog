#include "Robot.h"

using namespace std;

Robot:: Robot()
    {
    pathStartToExit = new Stack;
    }

Robot:: ~Robot()
    {
    while (!pathStartToExit->IsEmpty())
        {
        pathStartToExit->Pop();
        }
    }

Robot:: Robot(const Robot& _copie)
    {
    currentSquare = _copie.currentSquare;

    pathStartToExit = new Stack(*_copie.pathStartToExit);
    }

int Robot::Explore(Labyrinth* _labyrinth)
    {
    int cheminsPossibles = 0;
    int plusPetitChemin = 0;
    bool leftValid = false;
    bool rightValid = false;
    bool upperValid = false;
    bool lowerValid = false;
    Robot* leftRobot =  NULL;
    Robot* rightRobot = NULL;
    Robot* upperRobot = NULL;
    Robot* lowerRobot = NULL;
    if (currentSquare == NULL)
        {
        currentSquare = _labyrinth->GetStartSquare();
        }
    do
        {
        leftValid = false;
        rightValid = false;
        upperValid = false;
        lowerValid = false;
        leftRobot =  NULL;
        rightRobot = NULL;
        upperRobot = NULL;
        lowerRobot = NULL;
        cheminsPossibles = 0;
        currentSquare->visited = true;
        pathStartToExit->Push(currentSquare);
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
            if(leftValid)
                {
                leftRobot = new Robot(*this);
                leftRobot->currentSquare = currentSquare->leftSquare;
                plusPetitChemin = leftRobot->Explore(_labyrinth);
                }

            if(upperValid)
                {
                upperRobot = new Robot(*this);
                upperRobot->currentSquare = currentSquare->upperSquare;
                if (plusPetitChemin < upperRobot->Explore(_labyrinth))
                {
                
                }                   
                }           
            if(lowerValid)
                {
                lowerRobot = new Robot(*this);
                lowerRobot->currentSquare = currentSquare->lowerSquare;
                lowerRobot->Explore(_labyrinth);
                }
            if(rightValid)
                {
                rightRobot = new Robot(*this);
                rightRobot->currentSquare = currentSquare->rightSquare;
                rightRobot->Explore(_labyrinth);
                }            
            }
        else if(cheminsPossibles==1)
            {
            if(leftValid)
                {
                currentSquare = currentSquare->leftSquare;
                }

            if(upperValid)
                {
                currentSquare = currentSquare->upperSquare;
                }

            if(lowerValid)
                {
                currentSquare = currentSquare->lowerSquare;
                }

            if(rightValid)
                {
                currentSquare = currentSquare->rightSquare;
                }
            }
        }while (cheminsPossibles == 1 && currentSquare->value == 'S');
        return plusPetitChemin;
    }

string Robot::getSolution()
    {
    return pathStartToExit -> ToStringReverse();
    }

Square* Robot::getCurrentSquare()
    {
    return currentSquare;
    }