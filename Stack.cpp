#include "Stack.h"
#include <iostream>
#include <sstream>
using namespace std;

Stack::Stack()
    {
    first = NULL;
    }

Stack::~Stack()
    {
    while (first != NULL)
        {
        Pop ( );
        }
    }

Stack::Stack(const Stack& _copie)
    {
    Stack copie ;
    copie = _copie;
    Stack temp;
    while (copie.first != NULL)
        {
        Cell* cell = new Cell(copie.Top(),first);
        temp.Push(cell->element);
        copie.Pop();
        }

    while (temp.first != NULL)
        {
        Cell* cell = new Cell(temp.Top(),first);
        Push(cell->element);
        temp.Pop();
        }
    }

void Stack::Pop()
    {
    Square* contenu = NULL ;
    if (first != NULL)
        {
        contenu = first->element;
        Cell* noeudAEnlever = first;
        first = first->next ;
        delete noeudAEnlever ; }
    };

void Stack::Push(Square* _element)
    {
    Cell *nouveauNoeud= new Cell(_element,first);
    first = nouveauNoeud ;
    };

Square* Stack::Top()
    {
    if (first != NULL)
        {
        return this->first->element;
        }else
        {
        return NULL;
            }
    };

bool Stack::IsEmpty()
    {
    return (Top() == NULL);
    };

string Stack::ToStringReverse()
    {
    string stringReverse;
    ostringstream oss;
    oss.str("");
    while (!IsEmpty())
        {
        oss << Top()->x;
        stringReverse += + "(" + oss.str() + ",";
        oss.str("");
        oss << Top()->y;
        stringReverse += oss.str() + ") \n";
        Pop();
        }
    return stringReverse;
    };