#pragma once
#include <iostream>
#include "Cell.h"
using namespace std;

class Stack
    {
    public:
        Stack();
        ~Stack();
        void Pop();
        void Push(square* _element);
        square* Top();
        bool IsEmpty();
        string ToStringReverse();

    private:
        Cell* first;
    };
