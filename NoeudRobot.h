#include "FileRobot.h"

class NoeudRobot
{
public:
	NoeudRobot();
	~NoeudRobot();
	NoeudRobot* getNext();
	void setNext(NoeudRobot* _noeudRobot);
	Robot* getRobot();
	void setRobot(Robot* _robot);

private:
	NoeudRobot* suivant;
	Robot* contenu;
};