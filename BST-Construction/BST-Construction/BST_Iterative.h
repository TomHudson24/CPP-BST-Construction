#pragma once
#include "BST_Base.h"
#include <vector>
#include <iostream>
class BST_Iterative :
    public BST_Base
{
public:
    int value;
    BST_Iterative* left;
    BST_Iterative* right;

    BST_Iterative(int val) : value(val), left(NULL), right(NULL) {}
    BST_Iterative& insert(int val) override;
    bool contains(int val) override;
    BST_Iterative& remove(int val, BST_Iterative* parent = NULL);

    void printTreeBranchValues(int val);



private:

    int getMinValue()override;
};

