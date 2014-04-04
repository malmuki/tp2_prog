#pragma once
#include <iostream>
#include "Cell.h"

class Stack
{
public:
	Stack();
    Stack(const Stack& _copie);
	~Stack();
	void Pop();
	void Push(Square* _element);
	Square* Top();
	bool IsEmpty();
	string ToStringReverse();

private:
	Cell* first;
};
