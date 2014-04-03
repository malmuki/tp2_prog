#include "Robot.h"

using namespace std;

Robot:: Robot()
    {
    pathStartToExit = new Stack;
    leftRobot = NULL;
    rightRobot = NULL;
    upperRobot = NULL;
    lowerRobot = NULL;
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
    int cheminParcouru = 0;
    bool leftValid;
    bool rightValid;
    bool upperValid;
    bool lowerValid;
    int meilleur = 0;
    if (currentSquare == NULL)
        {
        currentSquare = _labyrinth->GetStartSquare();
        }
    do
        {
        int plusPetitChemin = -1;
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
            int temp;
            if(leftValid)
                {
                pathStartToExit->Push(currentSquare);
                leftRobot = new Robot(*this);
                leftRobot->currentSquare = currentSquare->leftSquare;
                temp = leftRobot->Explore(_labyrinth);
                if(temp != -1)
                    {
                    plusPetitChemin = temp;
                    meilleur = 1;
                    }
                }

            if(upperValid)
                {
                pathStartToExit->Push(currentSquare);
                upperRobot = new Robot(*this);
                upperRobot->currentSquare = currentSquare->upperSquare;
                temp = upperRobot->Explore(_labyrinth);
                if (plusPetitChemin < temp && temp != -1)
                    {
                    plusPetitChemin = temp;
                    meilleur = 2;
                    }
                }

            if(rightValid)
                {
                pathStartToExit->Push(currentSquare);
                rightRobot = new Robot(*this);
                rightRobot->currentSquare = currentSquare->rightSquare;
                temp = rightRobot->Explore(_labyrinth);
                if(plusPetitChemin < temp && temp != -1)
                    {
                    plusPetitChemin = temp;
                    meilleur = 4;
                    }
                }

            if(lowerValid)
                {
                pathStartToExit->Push(currentSquare);
                lowerRobot = new Robot(*this);
                lowerRobot->currentSquare = currentSquare->lowerSquare;
                temp = lowerRobot->Explore(_labyrinth);
                if(plusPetitChemin < temp && temp != -1)
                    {
                    plusPetitChemin = temp;
                    meilleur = 3;
                    }
                }
            }
        else if(cheminsPossibles==1)
            {
            if(leftValid)
                {
                currentSquare = currentSquare->leftSquare;
                plusPetitChemin = 1;
                pathStartToExit->Push(currentSquare);
                }

            if(upperValid)
                {
                currentSquare = currentSquare->upperSquare;
                plusPetitChemin = 1;
                pathStartToExit->Push(currentSquare);
                }

            if(lowerValid)
                {
                currentSquare = currentSquare->lowerSquare;
                plusPetitChemin = 1;
                pathStartToExit->Push(currentSquare);
                }

            if(rightValid)
                {
                currentSquare = currentSquare->rightSquare;
                plusPetitChemin = 1;
                pathStartToExit->Push(currentSquare);
                }
            }
        else
            {
            if (currentSquare->value != 'S' )
                {
                return -1;
                }
            }
        switch (meilleur)
            {
            case 0:
                //do nothing
                break;
            case 1:
                delete pathStartToExit;
                pathStartToExit = new Stack(*leftRobot->pathStartToExit);
                while (leftRobot->pathStartToExit->Top() != currentSquare)
                    {
                    leftRobot->pathStartToExit->Top()->visited =false;
                    leftRobot->pathStartToExit->Pop();
                    }
                break;
            case 2:
                delete pathStartToExit;
                pathStartToExit = new Stack(*upperRobot->pathStartToExit);
                while (upperRobot->pathStartToExit->Top() != currentSquare)
                    {
                    upperRobot->pathStartToExit->Top()->visited =false;
                    upperRobot->pathStartToExit->Pop();
                    }
                break;
            case 3:
                delete pathStartToExit;
                pathStartToExit = new Stack(*lowerRobot->pathStartToExit);
                while (lowerRobot->pathStartToExit->Top() != currentSquare)
                    {
                    lowerRobot->pathStartToExit->Top()->visited =false;
                    lowerRobot->pathStartToExit->Pop();
                    }
                break;
            case 4:
                delete pathStartToExit;
                pathStartToExit = new Stack(*rightRobot->pathStartToExit);
                while (leftRobot->pathStartToExit->Top() != currentSquare)
                    {
                    rightRobot->pathStartToExit->Top()->visited =false;
                    rightRobot->pathStartToExit->Pop();
                    }
                break;
            }
        if(plusPetitChemin != -1)
            {
            cheminParcouru +=  plusPetitChemin;
            }
        }while (currentSquare->value != 'S');
        return cheminParcouru;
    }

string Robot::getSolution()
    {
    return pathStartToExit -> ToStringReverse();
    }

Square* Robot::getCurrentSquare()
    {
    return currentSquare;
    }