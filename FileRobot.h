#include "Robot.h"

class FileRobot
{
public:
	FileRobot();
	~FileRobot();
	void AddRobot(Robot* robot);
	Robot* retirer();

private:
	class NoeudRobot
	{
	public:
		NoeudRobot();
		NoeudRobot* suivant;
		Robot* contenu;

	private:

	};

	NoeudRobot* premier;
	NoeudRobot* dernier;
};