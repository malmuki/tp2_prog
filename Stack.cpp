#include "Stack.h"
#include <iostream>
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

void Stack::Pop()
    {
    square* contenu = NULL ;
    if (first != NULL)
        {
        contenu = first->element;
        Cell* noeudAEnlever = first;
        first = first->next ;
        delete noeudAEnlever ; }
    };

void Stack::Push(square* _element)
    {
    Cell *nouveauNoeud= new Cell(_element,first);
    first = nouveauNoeud ;
    };

square* Stack::Top()
    {

    return first->element;
    };

bool Stack::IsEmpty()
    {
    return (Top() == NULL);
    };

string Stack::ToStringReverse()
    {
    string stringReverse;
    while (!IsEmpty())
        {
        stringReverse += "(";
        stringReverse += Top()->x;
        stringReverse += ",";
        stringReverse += Top()->y;
        stringReverse += ")";
        Pop();
        }
    return stringReverse;
    };