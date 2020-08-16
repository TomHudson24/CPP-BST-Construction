#pragma once
#include "BST_Base.h"
#include<iostream>
class BST_Recursive :
    public BST_Base
{
public:
    int value;
    BST_Recursive* left;
    BST_Recursive* right;
    
    BST_Recursive(int val) : value(val), left(NULL), right(NULL) {}
    BST_Recursive& insert(int val) override;
    bool contains(int val) override;
    BST_Recursive& remove(int val, BST_Recursive* parent = NULL);

    void printTreeBranchValues(int val);
   

    
private:
    
    int getMinValue()override;
};

