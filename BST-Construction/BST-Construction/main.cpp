#include <iostream>
#include"BST_Recursive.h"
#include "BST_Iterative.h"
/*
The recursive version of the BST runs on average in O(log(n)) time and space where n is the size of the BST. 
The worst case for the recursive version would switch the time and space complexity to O(n) where n is the size of the BST.
This is determined if the tree is balanced or not, preferably balanced, obviously.

The iterative version of the BST runs on average in O(log(n)) time and O(1) space where n is the size of the BST. 
In the worse case scenario the iterative version will have worse time complexity to O(n) but space complexity
will stay the same at O(1). 

The main difference in the algo's is the space complexity, this is because of the use of the call stack 
when running the recursive algorithm. 

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
	bst_R->remove(6);
	bst_R->printTreeBranchValues(9);
#endif
	//Iterative method
#if 1
	BST_Iterative* bst_I = new BST_Iterative(10);
	
	bst_I->insert(5);
	bst_I->insert(15);
	bst_I->insert(12);
	bst_I->insert(8);
	bst_I->insert(22);
	//std::cout << bst_I->contains(23) << std::endl;
	//bst_I->printTreeBranchValues(22);
	bst_I->insert(4);
	bst_I->insert(1);
	bst_I->insert(3);
	bst_I->remove(4);
	bst_I->printTreeBranchValues(1);

#endif
	return 0;
}