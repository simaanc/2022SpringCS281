#include "BST.h"

BST::BST()
{
	Root = nullptr;
	current = nullptr;
}

BST::~BST()
{
	makeEmpty();
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

void BST::empty(Node* root) //post order traversal Left Right Middle
{
	if (root->left != nullptr)
		empty(root->left);

	if (root->right != nullptr)
		empty(root->right);

	delete root;

}

void BST::putItem(int item)
{ 
	if (isEmpty())
	{
		Root = new Node(item);
	}
	else
		put(Root, item);

	/*
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
	*/
}

void BST::deleteNode(Node *root)
{

	Node*parent= findParent(root);

	if (root->left == nullptr && root->right == nullptr)
	{
		//no children
		if (parent == nullptr)
		{
			Root = nullptr;
		}
		else if (parent->left == root)
			parent->left = nullptr;
		else
			parent->right = nullptr;

		delete root;

	}
	else if (root->left != nullptr && root->right == nullptr)
	{
		if (parent == nullptr)
		{
			Root = root->left;
		}
		else if(parent->left == root)
		{
			parent->left = root->left;
		}
		else
		{
			parent->right = root->left;
		}

		delete root;
	}
	else if (root->right != nullptr && root->left == nullptr)
	{

		if (parent == nullptr)
		{
			Root = root->right;
		}
		else if (parent->left == root)
			parent->left = root->right;
		else
			parent->right = root->right;

		delete root;
	}
	else //right and left child
	{
		if (parent == nullptr) //deleting root
		{

			Node* rightMost = rightMostLeft(root->left);
			int temp = rightMost->data;

			deleteNode(rightMost);

			root->data = temp;
		}
	}


	
	//todo two children


}

Node* BST::findParent(Node* child)
{
	Node* parent;
	if (child == Root)
	{
		parent = nullptr;
		return parent;
	}
		
	parent = Root;
	

	while (parent != nullptr )
	{
		if (child->data < parent->data)
		{
			if (parent->left == child)
				return parent;
			else
				parent = parent->left;
		}
		else
		{
			if (parent->right == child)
				return parent;
			else
				parent = parent->right;
		}

	}

	return nullptr;
}


//finds right most child on left side of current node.
Node* BST::rightMostLeft(Node* rightMost)
{
	while (rightMost->right != nullptr)
		rightMost = rightMost->right;

	return rightMost;

}

bool BST::deleteItem(int item)
{
	if (isEmpty())
		return false;

	if (!findItem(item))
		return false;
	else
		deleteNode(current);



}


//Sets current to location if item is found.
bool BST::findItem(int item)
{
	if (isEmpty())
		return false;

	current = Root;
	bool found = false;

	while (current != nullptr && found == false)
	{
		if (current->data == item)
			found = true;
		else if (item < current->data)
			current = current->left;
		else
			current = current->right;
	}

	return found;
}

bool BST::isEmpty()
{
	if (Root == nullptr)
		return true;
	else
		return false;
}

void BST::makeEmpty()
{
	if (isEmpty())
		return;

	empty(Root);//recursive function

	Root = nullptr;
	current = nullptr;

}

void BST::orderPrint(Node* root)
{
	// inorder Traversal (LMR)

	if (root->left != nullptr)
		orderPrint(root->left);

	std::cout << root->data << " ";
		
	
	if (root->right != nullptr)
		orderPrint(root->right);
}

void BST::printOrderedList()
{
	if (isEmpty())
		std::cout << "Tree Empty!" << std::endl;

	orderPrint(Root);
	std::cout << std::endl;

}

int BST::getCurrent()
{
	if (current == nullptr)
		return -9999;

	return current->data;
}
