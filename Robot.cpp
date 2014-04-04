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
    string pathParent;

    if (currentSquare == NULL)
        {
        currentSquare = _labyrinth->GetStartSquare();
        }

    do
        {
        pathStartToExit->Push(currentSquare);
        int plusPetitChemin = 0;
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
                    }else
                    {
                    delete leftRobot;
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
                    delete leftRobot;
                    }else
                    {
                    delete upperRobot;
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
                    delete leftRobot;
                    }else
                    {
                    delete lowerRobot;
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
                    delete leftRobot;
                    }else
                    {
                    delete rightRobot;
                        }
                }
            }

        else if(cheminsPossibles==1)
            {
            if(leftValid)
                {
                currentSquare = currentSquare->leftSquare;
                plusPetitChemin = 1;
                if (currentSquare->value == 'S')
                    {
                    meilleur = 5;
                    }
                }

            if(upperValid)
                {
                currentSquare = currentSquare->upperSquare;
                plusPetitChemin = 1;
                if (currentSquare->value == 'S')
                    {
                    meilleur = 5;
                    }
                }

            if(lowerValid)
                {
                currentSquare = currentSquare->lowerSquare;
                plusPetitChemin = 1;
                if (currentSquare->value == 'S')
                    {
                    meilleur = 5;
                    }
                }

            if(rightValid)
                {
                currentSquare = currentSquare->rightSquare;
                plusPetitChemin = 1;
                if (currentSquare->value == 'S')
                    {
                    meilleur = 5;
                    }
                }
            }

        else
            {
            if (currentSquare->value != 'S' )
                {
                return -1;
                }
            }

        //switch (meilleur)
        //    {
        //    case 1: // left
        //        pathParent = leftRobot->printsolutions( pathParent);
        //        break;
        //    case 2: //upper
        //        pathParent = upperRobot->printsolutions( pathParent);
        //        break;
        //    case 3: //lower
        //        pathParent = lowerRobot->printsolutions( pathParent);
        //        break;
        //    case 4: //right
        //        pathParent = rightRobot->printsolutions( pathParent);
        //        break;
        //    case 5: //ligne droite
        //

        //        break;

        //    default:
        //        do nothing
        //        break;
        //    }

        if(plusPetitChemin != -1)
            {
            cheminParcouru +=  plusPetitChemin;
            }
        } while (currentSquare->value != 'S');

        return cheminParcouru;
    }

string Robot::getSolution()
    {
    string out;
    if (currentSquare->value == 'S')
        {
        return out;
        }else
        {
            if (leftRobot)
            {
                out+= leftRobot->getSolution();
            }
            if (upperRobot)
                {
                out+= upperRobot->getSolution();
                }
            if (lowerRobot)
                {
                out+= lowerRobot->getSolution();
                }
            if (rightRobot)
                {
                out+= rightRobot->getSolution();
                }
        }
    }

Square* Robot::getCurrentSquare()
    {
    return currentSquare;
    }