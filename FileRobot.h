#pragma once
#include "Robot.h"

class FileRobot
{
public:
	FileRobot();
	~FileRobot();	
    Robot* retirer();
    Robot* Top();
    void AddRobot(Robot* robot);

private:
	class NoeudRobot
	{
	public:
		NoeudRobot* suivant;
		Robot* contenu;

	};

	NoeudRobot* premier;
	NoeudRobot* dernier;
};