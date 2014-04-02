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
			int temp;
			int meilleur = 0;
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
			if(pathStartToExit->Top()->value == 'S')
			{
				switch (meilleur)
				{
				case 0:
					//do nothing
					break;
				case 1:
					pathStartToExit = new Stack(*leftRobot->pathStartToExit);

					break;
				case 2:
					pathStartToExit = new Stack(*upperRobot->pathStartToExit);

					break;
				case 3:
					pathStartToExit = new Stack(*lowerRobot->pathStartToExit);

					break;
				case 4:
					pathStartToExit = new Stack(*rightRobot->pathStartToExit);

					break;
				default:
					return -1;

					break;
				}
			}

			delete leftRobot;
			upperRobot;
			rightRobot;
			lowerRobot;

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
			if (currentSquare->value != 'S')
			{
				return -1;
			}

		}

		if(plusPetitChemin != -1)
		{
			cheminParcouru +=  plusPetitChemin;
		}
		else
		{
			cheminParcouru = 0;
		}
	}while (cheminsPossibles == 1 || currentSquare->value != 'S');
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