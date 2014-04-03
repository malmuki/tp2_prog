#pragma once
#include <iostream>
#include "Cell.h"

class Stack
{
public:
	Stack();
	~Stack();
	void Pop();
	void Push(Square* _element);
	Square* Top();
	bool IsEmpty();
	string ToStringReverse();

private:
	Cell* first;
};
