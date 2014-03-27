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
		return first->element;
	}else
		return NULL;
	{
	}
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