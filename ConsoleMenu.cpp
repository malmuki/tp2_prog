#include <iostream>
#include <string>
#include "ConsoleMenu.h"
#include "Robot.h"
#include "Labyrinth.h"

using namespace std;

void ConsoleMenu::Run()
    {
    char input;
    char tabValidInputs[] = {'V', 'v', 'S', 's', 'Q', 'q'};
    const int NB_ELEMENTS = 6;
    do{
        system("cls");
        input = readValidInput(tabValidInputs, NB_ELEMENTS);
        }while(manageChoice(input));
    }

bool ConsoleMenu::manageChoice(char _input)
    {
    bool choix;
    Robot robot;
    Labyrinth labyrinth;
    switch (_input)
        {
        case 'Q':
        case 'q' :
            choix = false;
            break;

        case 'V':
        case 'v' :

            break;

        case 'S':
        case's':

            break;
        }
    return choix;
    }

char ConsoleMenu::readValidInput(char  _tabValidInputs[], int _nbElements)
    {
    string input;
    bool valid = false;

    displayMenu();

    do {
        getline(std::cin, input);
        for (int i = 0; i < _nbElements; i++)
            {
            if (_tabValidInputs[i] == input[0])
                {
                valid = true;
                }
            }
        if (!valid){
            cout << "le type d'entré est invalide!";
            }
        }while(!valid);
    return input[0];
    }
void ConsoleMenu::displayMenu()
    {
    cout << "+------------------------------------+\n";
    cout << "+------------------------------------+\n";
    cout << "+--------------Labyrinth-------------+\n";
    cout << "+------------------------------------+\n";
    cout << "+------------------------------------+\n";
    cout << "pour crypter appuyer sur e \n";
    cout << "pour quitter appuyer sur q \n";
    }