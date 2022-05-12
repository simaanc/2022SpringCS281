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

void BST::empty(Node* root)
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

void BST::deleteNode(Node *root,int item)
{

	Node*parent= findParent(root);
	if (root == Root)
	{
		//todo
	}
	else if (root->left == nullptr && root->right == nullptr)
	{
		//no children
		if (parent->left == root)
			parent->left = nullptr;
		else
			parent->right = nullptr;

		delete root;

	}
	//todo one child
	//todo two children


}

Node* BST::findParent(Node*)
{


	return nullptr;
}

bool BST::deleteItem(int item)
{
	if (isEmpty())
		return false;

	if (!findItem(item))
		return false;
	else
		deleteNode(current, item);



}

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

	empty(Root);

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
