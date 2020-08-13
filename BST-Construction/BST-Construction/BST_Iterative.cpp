#include "BST_Iterative.h"

BST_Iterative& BST_Iterative::insert(int val) {
		// Write your code here.
	BST_Iterative* currentNode = this;
		while (true)
		{
			if (val < currentNode->value)//go down the left subtree
			{
				if (currentNode->left == NULL)//if there is not left node
				{
					BST_Iterative* newNode = new BST_Iterative(val);//make a new one with the specified value
					currentNode->left = newNode;//assign the pointer to it
					break;
				}
				else
				{
					currentNode = currentNode->left;
				}
			}
			else
			{//going down the right sub tree
				if (currentNode->right == NULL)//no current right node
				{
					BST_Iterative* newNode = new BST_Iterative(val);//create the node and assign the specified value to it
					currentNode->right = newNode;//point to the new node
					break;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}
		}
		return *this;
	}



	bool BST_Iterative::contains(int val) {
		// Write your code here.
		BST_Iterative* currentNode = this;
		while (currentNode != NULL)//as long as it isn't pointing to nothing
		{
			if (val < currentNode->value)//go down left sub tree
			{
				currentNode = currentNode->left;//move along the left subtree's branch
			}
			else if (val > currentNode->value)//go down right sub tree
			{
				currentNode = currentNode->right;//move along the right subtree's branch
			}
			else
			{
				return true;//value is found so back up 
			}
		}
		return false;//value not found and the while loop has ended due to the currentNode being on a non existent leaf
	}

	BST_Iterative& BST_Iterative::remove(int val, BST_Base* parentNode) {
		// Write your code here.
		BST_Iterative* currentNode = this;
		while (currentNode != NULL)
		{
			if (val < currentNode->value)
			{
				parentNode = currentNode;
				currentNode = currentNode->left;
			}
			else if (val > currentNode->value)
			{
				parentNode = currentNode;
				currentNode = currentNode->right;
			}
			else
			{
				if (currentNode->left != NULL && currentNode->right != NULL)
				{
					currentNode->value = currentNode->right->getMinValue();
					currentNode->right->remove(currentNode->value, currentNode);
				}
				else if (parentNode == NULL)
				{
					if (currentNode->left != NULL)
					{
						currentNode->value = currentNode->left->value;
						currentNode->right = currentNode->left->right;
						currentNode->left = currentNode->left->left;
					}
					else if (currentNode->right != NULL)
					{
						currentNode->value = currentNode->right->value;
						currentNode->left = currentNode->right->left;
						currentNode->right = currentNode->right->right;
					}
					else
					{
						//One node in the tree so do nothing
					}
				}
				else if (parentNode->left == currentNode)
				{
					parentNode->left = currentNode->left != NULL ? currentNode->left : currentNode->right;
				}
				else if (parentNode->right == currentNode)
				{
					parentNode->right = currentNode->left != NULL ? currentNode->left : currentNode->right;
				}
				break;
			}
		}
		// Do not edit the return statement of this method.
		return *this;
	}

	int BST_Iterative::getMinValue()
	{
		if (left == NULL)
		{
			return value;
		}
		else
		{
			return left->getMinValue();
		}
	}

