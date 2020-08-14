#include <iostream>
#include"BST_Recursive.h"
#include "BST_Iterative.h"
/*
The recursive version of the BST runs on average in O(log(n)) time and space where n is the size of the BST. 
The worst case for the recursive version would switch the time and space complexity to O(n) where n is the size of the BST.
This is determined if the tree is balanced or not, preferably balanced, obviously.
*/
int main(int argc, char** argv)
{
	//Recursive method
#if 0
	BST_Recursive *bst_R = new BST_Recursive(5);
	
	
	bool it = bst_R->contains(5);
	std::cout << it << std::endl;
	bool no = bst_R->contains(6);
	if (!no)
	{
		std::cout << "Not in there\n";
	}
	else 
	{
		std::cout << "In there\n";
	}
	bst_R->insert(6);
	bst_R->insert(9);
	bst_R->insert(4);
	bst_R->insert(7);
	bst_R->printTreeBranchValues(9);
#endif
	//Iterative method
#if 1
	BST_Iterative* bst_I = new BST_Iterative(10);
	bool InTree = bst_I->contains(10);
	if (InTree)
	{
		std::cout << "In There\n";
	}
	bst_I->insert(5);
	std::cout << bst_I->contains(5) << std::endl;
	bst_I->insert(12);
	bst_I->insert(15);
	bst_I->insert(18);
	bst_I->insert(22);
	bst_I->insert(26);
	bst_I->insert(21);
	bst_I->insert(4);
	bst_I->insert(11);
	
	bst_I->printTreeBranchValues(26);

#endif
	return 0;
}