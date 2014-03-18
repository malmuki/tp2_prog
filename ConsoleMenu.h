#pragma once
class ConsoleMenu
    {
    public:
        void Run();
    private:
        char readValidInput(char _tabValidInputs[], int _nbElements);
        void displayMenu();
        bool manageChoice(char  _input );
    };
