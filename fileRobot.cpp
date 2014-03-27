#include "FileRobot.h"

FileRobot::FileRobot()
{

}

FileRobot::~FileRobot()
{
	while(dernier != NULL)
	{
		retirer();
	}
}

void FileRobot::AddRobot (Robot* _robot)
{
	NoeudRobot* nouveauNoeud = new NoeudRobot;
	nouveauNoeud->contenu = _robot;
	nouveauNoeud->suivant = NULL;

	if(dernier != NULL)
	{
		dernier->suivant = nouveauNoeud;
	}
	else
	{
		premier = nouveauNoeud;
	}

	dernier = nouveauNoeud;
}

Robot* FileRobot::retirer()
{
	Robot* robot = NULL;

	if(premier != NULL)
	{
		NoeudRobot* noeudARetirer = premier;
		robot = noeudARetirer->contenu;
		premier = noeudARetirer->suivant;
		delete noeudARetirer;

		if(premier == NULL)
		{
			dernier = NULL;
		}
	}
	return robot;
}