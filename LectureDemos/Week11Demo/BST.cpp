#include "BST.h"

BST::BST()
{
	Root = nullptr;
	current = nullptr;


}


void BST::put(Node* root, int item)
{
	if (item < root->data)//to the left
	{
		if (root->left == nullptr)
			root->left = new Node(item);
		else
			put(root->left, item);
	}
	else//to the right
	{
		if (root->right == nullptr)
			root->right = new Node(item);
		else
			put(root->right, item);
	}
}

void BST::putItem(int item)
{ 
	if (isEmpty())
	{
		Root = new Node(item);
	}
	else if (item < Root->data)
	{
		if (Root->left == nullptr)
			Root->left = new Node(item);
		else
			put(Root->left, item);
	}
	else
	{
		if (Root->right == nullptr)
			Root->right = new Node(item);
		else
			put(Root->right, item);
	}



}

bool BST::isEmpty()
{
	if (Root == nullptr)
		return true;
	else
		return false;
}
