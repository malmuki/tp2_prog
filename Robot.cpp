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
    pathStartToExit = new Stack;
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
        pathStartToExit->Push(currentSquare);
        int plusPetitChemin = -1;
        leftValid = false;
        rightValid = false;
        upperValid = false;
        lowerValid = false;
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
                upperRobot = new Robot(*this);
                upperRobot->currentSquare = currentSquare->upperSquare;
                temp = upperRobot->Explore(_labyrinth);
                if (plusPetitChemin < temp && temp != -1)
                    {
                    plusPetitChemin = temp;
                    meilleur = 2;
                    }
                }
            if(lowerValid)
                {
                lowerRobot = new Robot(*this);
                lowerRobot->currentSquare = currentSquare->lowerSquare;
                temp = lowerRobot->Explore(_labyrinth);
                if(plusPetitChemin < temp && temp != -1)
                    {
                    plusPetitChemin = temp;
                    meilleur = 3;
                    }
                }
            if(rightValid)
                {
                rightRobot = new Robot(*this);
                rightRobot->currentSquare = currentSquare->rightSquare;
                temp = rightRobot->Explore(_labyrinth);
                if(plusPetitChemin < temp && temp != -1)
                    {
                    plusPetitChemin = temp;
                    meilleur = 4;
                    }
                }           
            }
        else if(cheminsPossibles==1)
            {
            if(leftValid)
                {
                currentSquare = currentSquare->leftSquare;
                plusPetitChemin = 1;
                }

            if(upperValid)
                {
                currentSquare = currentSquare->upperSquare;
                plusPetitChemin = 1;
                }

            if(lowerValid)
                {
                currentSquare = currentSquare->lowerSquare;
                plusPetitChemin = 1;
                }

            if(rightValid)
                {
                currentSquare = currentSquare->rightSquare;
                plusPetitChemin = 1;
                }
            }
        else
            {
            if (currentSquare->value != 'S' )
                {
                return -1;
                }
            }
        Stack inverse;
        switch (meilleur)
            {
            case 0:
                //do nothing
                break;
            case 1:
                leftRobot->pathStartToExit->Push(currentSquare);
                while (leftRobot->pathStartToExit->Top() != NULL)
                    {
                    pathStartToExit->Push(leftRobot->pathStartToExit->Top());
                    leftRobot->pathStartToExit->Top()->visited =false;
                    leftRobot->pathStartToExit->Pop();
                    }
                break;
            case 2:
                upperRobot->pathStartToExit->Push(currentSquare);
                while (upperRobot->pathStartToExit->Top() != NULL)
                    {
                    pathStartToExit->Push(upperRobot->pathStartToExit->Top());
                    upperRobot->pathStartToExit->Top()->visited =false;
                    upperRobot->pathStartToExit->Pop();
                    }
                break;
            case 3:
                lowerRobot->pathStartToExit->Push(currentSquare);
                while (!lowerRobot->pathStartToExit->IsEmpty())
                    {
                    inverse.Push(lowerRobot->pathStartToExit->Top());
                    lowerRobot->pathStartToExit->Pop();
                    }
                while (!inverse.IsEmpty())
                    {
                    pathStartToExit->Push(inverse.Top());
                    inverse.Top()->visited =false;
                    inverse.Pop();
                    }
                break;
            case 4:
                rightRobot->pathStartToExit->Push(currentSquare);
                while (!rightRobot->pathStartToExit->IsEmpty())
                    {
                    inverse.Push(rightRobot->pathStartToExit->Top());
                    rightRobot->pathStartToExit->Pop();
                    }
                while (!inverse.IsEmpty())
                    {
                    pathStartToExit->Push(inverse.Top());
                    inverse.Top()->visited =false;
                    inverse.Pop();
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