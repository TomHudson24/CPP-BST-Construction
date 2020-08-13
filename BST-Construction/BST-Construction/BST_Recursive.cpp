#include "BST_Recursive.h"

BST_Recursive &BST_Recursive::insert(int val)
{
	if (val < value)//go down the left side of the tree
	{
		if (left == NULL)//if there is no left node create one and assign it
		{
			BST_Recursive* newBST = new BST_Recursive(val);
			left = newBST;
		}
		else//if there is a left node then recurse down and repeat process until there is no left node
		{
			left->insert(val);
		}
	}
	else//the value must be larger so check the right subtree
	{
		if (right == NULL)//if there is no right node, great add that new node in with the value
		{
			BST_Recursive* newBST = new BST_Recursive(val);
			right = newBST;
		}
		else//recurse down the tree and repeat the insertion func until there is no right node
		{
			right->insert(val);
		}
	}
	// Do not edit the return statement of this method.
	return *this;
}

bool BST_Recursive::contains(int val)
{
	// Write your code here.
	if (val < value)//search down the left subtree for the value
	{
		if (left == NULL)//if no left node the value is not in the tree
		{
			return false;
		}
		else//if there is a left node recurse down the tree and repeat process
		{
			return left->contains(val);
		}
	}
	else if (val > value)//search down the right subtree for the value
	{
		if (right == NULL)//if no right node the value is not in the tree
		{
			return false;
		}
		else//recurse down the right subtree 
		{
			return right->contains(val);
		}
	}
	else//when the value has been found return true
	{
		return true;
	}
}

BST_Recursive& BST_Recursive::remove(int val, BST_Base* parent)
{
	// Write your code here.
	if (val < value)//go down the left subtree
	{
		if (left != NULL)//if the node exists recurse down into it 
		{//passing the value we want to delete and this node as the parent
			left->remove(val, this);
		}
	}
	else if (val > value)//go down the right subtree
	{
		if (right != NULL)//if the node exists recruse down into it
		{//passing the value we want to delete and this node as the parent
			right->remove(val, this);
		}
	}
	else//edge cases
	{
		if (left != NULL && right != NULL)//there is both a left and right node
		{
			value = right->getMinValue();//go down the right subtree and find
			//the leftmost (lowest) value
			right->remove(value, this);//recurse down and remove that value we just found using getMinValue()
		}
		else if (parent == NULL)//there is no parent node
		{
			if (left != NULL)//there is a left node
			{
				value = left->value;//set the left nodes value to the parent value
				right = left->right;//set the right node of the left node to be the parent node right node
				left = left->left;//set the left node of the left node, creating the current node to be the parent node
			}
			else if (right != NULL)//there is a right node
			{
				value = right->value;//set the right nodes value to be the parent value
				left = right->left;//set the left node of the right node to be the parent nodes left node
				right = right->right;//set the right node of the right node, creating the current node to be the parent node
			}
			else
			{
				//Do nothing as only one node in the tree
			}
		}
		else if (parent->left == this)//on the left node in the call stack
		{
			parent->left = left != NULL ? left : right;//ternary operator used to overwrite nodes depending on what is not null in the next nodes
		}
		else if (parent->right == this)//on the right node in the call stack
		{
			parent->right = left != NULL ? left : right;//ternary operator used to overwrite nodes depending on what is not null in the next nodes
		}
	}
	return *this;
}

void BST_Recursive::printTreeBranchValues(int val)
{
	if (val < value)//search down the left subtree for the value
	{
		if (left == NULL)//if no left node the value is not in the tree
		{
			std::cout << "End of left branch...\n";
		}
		else//if there is a left node recurse down the tree and repeat process
		{
			std::cout << value << ", ";
			left->printTreeBranchValues(val);
		}
	}
	else if (val > value)//search down the right subtree for the value
	{
		if (right == NULL)//if no right node the value is not in the tree
		{
			"End of right branch...\n";
		}
		else//recurse down the right subtree 
		{
			std::cout << value << ", ";
			right->printTreeBranchValues(val);
		}
	}
	else
	{
		std::cout << value;
	}
}

int BST_Recursive::getMinValue()
{
	if (left == NULL)//great we have the leftmost value in the right subtree - replace head with that value
	{
		return value;
	}
	else //recurse down the tree again to find that leftmost value in the right subtree
	{
		return left->getMinValue();
	}
}