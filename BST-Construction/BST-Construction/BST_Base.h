#pragma once
#include <vector>
class  BST_Base
{
public:
	int value;
	BST_Base* left;
	BST_Base* right;

	BST_Base(int val) : value(val), left(NULL), right(NULL) {}
	BST_Base() = default;
	virtual BST_Base& insert(int val);
	virtual bool contains(int val);
	virtual BST_Base& remove(int val, BST_Base* parent = NULL);
	virtual int getMinValue();
};

