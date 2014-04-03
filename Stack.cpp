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

void Stack::Pop()
{
	Square* contenu = NULL ;
	if (first != NULL)
	{
		contenu = first->element;
		Cell* noeudAEnlever = first;
		first = first->next ;
		delete noeudAEnlever ; }
}

void Stack::Push(Square* _element)
{
	Cell *nouveauNoeud= new Cell(_element,first);
	first = nouveauNoeud ;
}

Square* Stack::Top()
{
	if (first != NULL)
	{
		return first->element;
	}
	else
	{
		return NULL;
	}
}

bool Stack::IsEmpty()
{
	return (Top() == NULL);
}

string Stack::ToStringReverse()
{
	string stringReverse;
	ostringstream oss;
	Stack temp;
	while (this->first != NULL)
	{
		Cell* cell = new Cell(this->Top(),this->first);
		temp.Push(cell->element);
		this->Pop();
	}
	while (!temp.IsEmpty())
	{
		oss.str("");
		oss << temp.Top()->x;
		stringReverse += "(" + oss.str() + ",";
		oss.str("");
		oss << temp.Top()->y;
		stringReverse += oss.str() + ") \n";
		temp.Pop();
	}
	return stringReverse;
}