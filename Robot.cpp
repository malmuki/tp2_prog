#include "Robot.h"

using namespace std;

Robot:: Robot()
{
	pathStartToExit = new Stack;
	leftRobot = NULL;
	rightRobot = NULL;
	upperRobot = NULL;
	lowerRobot = NULL;
	foundExit = false;
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
	leftRobot = NULL;
	rightRobot = NULL;
	upperRobot = NULL;
	lowerRobot = NULL;
	foundExit = false;
}

void Robot::SetRobot(int _direction)
{
	switch (_direction)
	{
	case 0:
		this->leftRobot = new Robot(*this);
		leftRobot->currentSquare = currentSquare->leftSquare;
		break;
	case 1:
		this->upperRobot = new Robot(*this);
		upperRobot->currentSquare = currentSquare->upperSquare;
		break;
	case 2:
		this->lowerRobot = new Robot(*this);
		lowerRobot->currentSquare = currentSquare->lowerSquare;
		break;
	case 3:
		this->rightRobot = new Robot(*this);
		rightRobot->currentSquare = currentSquare->rightSquare;
		break;
	}
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
		int plusPetitChemin = 400;
		leftValid = false;
		int leftPath = 400;
		rightValid = false;
		int rightPath = 400;
		upperValid = false;
		int upperPath = 400;
		lowerValid = false;
		int lowerPath = 400;
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
				SetRobot(0);
				leftPath = leftRobot->Explore(_labyrinth);
				if (leftPath == -1)
				{
					leftValid = false;
					delete leftRobot;
					leftRobot = NULL;
				}
			}

			if(upperValid)
			{
				SetRobot(1);
				upperPath = upperRobot->Explore(_labyrinth);
				if (upperPath == -1)
				{
					upperValid = false;
					delete upperRobot;
					upperRobot = NULL;
				}
			}

			if(lowerValid)
			{
				SetRobot(2);
				lowerPath = lowerRobot->Explore(_labyrinth);
				if (lowerPath == -1)
				{
					lowerValid = false;
					delete lowerRobot;
					lowerRobot = NULL;
				}
			}

			if(rightValid)
			{
				SetRobot(3);
				rightPath = rightRobot->Explore(_labyrinth);
				if (rightPath == -1)
				{
					rightValid = false;
					delete rightRobot;
					rightRobot = NULL;
				}
			}

			if (leftValid)
			{
				if (leftRobot->foundExit == true)
				{
					foundExit = true;
				}
				if (plusPetitChemin > leftPath)
				{
					if (rightPath > leftPath)
					{
						if (upperPath > leftPath)
						{
							if (lowerPath > leftPath)
							{
								plusPetitChemin = leftPath;
							}
						}
					}
				}
			}

			if (rightValid)
			{
				if (rightRobot->foundExit == true)
				{
					foundExit = true;
				}
				if (plusPetitChemin > rightPath)
				{
					if (leftPath > rightPath)
					{
						if (upperPath > rightPath)
						{
							if (lowerPath > rightPath)
							{
								plusPetitChemin = rightPath;
							}
						}
					}
				}
			}

			if (upperValid)
			{
				if (upperRobot->foundExit == true)
				{
					foundExit = true;
				}
				if (plusPetitChemin > upperPath)
				{
					if (rightPath > upperPath)
					{
						if (leftPath > upperPath)
						{
							if (lowerPath > upperPath)
							{
								plusPetitChemin = upperPath;
							}
						}
					}
				}
			}

			if (lowerValid)
			{
				if (lowerRobot->foundExit == true)
				{
					foundExit = true;
				}
				if (plusPetitChemin > lowerPath)
				{
					if (rightPath > lowerPath)
					{
						if (upperPath > lowerPath)
						{
							if (leftPath > lowerPath)
							{
								plusPetitChemin = lowerPath;
							}
						}
					}
				}
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
			plusPetitChemin = 1;
		}

		else
		{
			if (foundExit == false)
			{
				if (currentSquare->value != 'S')
				{
					return -1;
				}
				else
				{
					foundExit = true;
					return cheminParcouru +  plusPetitChemin;
				}
			}
			else
			{
				return cheminParcouru  +  plusPetitChemin;
			}

		}

		if (plusPetitChemin != 400)
		{
			cheminParcouru +=  plusPetitChemin;
		}

	} while (currentSquare->value != 'S');

	pathStartToExit->Push(currentSquare);
	return cheminParcouru;
}

string Robot::getSolution()
{
	string out;

	if (this->leftRobot != NULL)
	{
		out+= leftRobot->getSolution();
	}
	if (this->upperRobot != NULL)
	{
		out+= upperRobot->getSolution();
	}
	if (this->lowerRobot != NULL)
	{
		out+= lowerRobot->getSolution();
	}
	if (this->rightRobot != NULL)
	{
		out+= rightRobot->getSolution();
	}
	else
	{
	return pathStartToExit->ToStringReverse() + out;
	}
}

Square* Robot::getCurrentSquare()
{
	return currentSquare;
}