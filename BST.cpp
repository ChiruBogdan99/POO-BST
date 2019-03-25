#include "BST.h"
#include "node.h"
#include <iostream>

using namespace std;

BST::BST()
{
	root = NULL;
}
/*
BST::BST(BST& tree) :root(NULL)
{
	if (tree.root == NULL)
		root = NULL;
	else
		copy(this->root, tree.root);
}
*/
BST::~BST()
{
	//deleteTree(root);
}

void BST::copy(node* & root1, node* & root2)
{
	if (root2 == NULL)
		root1 = NULL;
	else
	{
		root1 = new node;
		root1->left = NULL;
		root1->right = NULL;
		root1->key = root2->key;
		copy(root1->left, root->left);
		copy(root1->right, root->right);
	}
}

node* BST::deleteTree(node* root)
{
	if(root == NULL)
		return root;
	else
	{
		root->left = deleteTree(root->left);
		root->right = deleteTree(root->right);
	}
	delete root;
}

node* BST::create(int x)
{
	node* elem = new node;
	elem->key = x;
	elem->left = NULL;
	elem->right = NULL;
	return elem;
}

void BST::insert(int x, node* & root)
{
	if (root == NULL)
		root = create(x);
	else
	{
		if (x < root->key)
			insert(x, root->left);
		else if (x > root->key)
			insert(x, root->right);
		//else if (x == root->key)
			//cout << "Nodul se afla deja in arbore." << endl;
	}
}

void BST::remove(int x, node* & root)
{
	if (root == NULL)
		return;
	else if (root->key < x)
		remove(x, root->right);
	else if (root->key > x)
		remove(x, root->left);
	else if (root->key == x)
	{
		if (root->left == NULL && root->right != NULL)
			root = root->right;
		else if (root->left != NULL && root->right == NULL)
			root = root->left;
		else if (root->left == NULL && root->right == NULL)
			root = NULL;
		else if (root->left != NULL && root->right != NULL)
		{
			node* temp = findMin(root->right);
			root->key = temp->key;
			remove(temp->key, root->right);
		}
	}
}

node* BST::findMin(node* root)
{
	if (root->left == NULL)
		return root;
	else
		return findMin(root->left);
}

node* BST::findMax(node* root)
{
	if (root->right == NULL)
		return root;
	else
		return findMin(root->right);
}

void BST::inorder(node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

void BST::leafs(node* start)
{
	if (root != NULL)
	{
		inorder(root->left);
		if(root->left == NULL && root->right == NULL)
			cout << root->key << " ";
		inorder(root->right);
	}
}

int BST::height(node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int hLeft = height(root->left);
		int hRight = height(root->right);

		if (hLeft < hRight)
			return hRight + 1;
		else
			return hLeft + 1;
	}
}

// PUBLIC

void BST::insert(int x)
{
	insert(x, root);
}
void BST::remove(int x)
{
	remove(x, root);
}
void BST::display()
{
	inorder(root);
	cout << endl;
}
int BST::height()
{
	return height(root);
}
void BST::leafs()
{
	leafs(root);
	cout << endl;
}


// OPERATORI

BST BST::operator+(int x)
{
    this->insert(x);
}

istream& operator>>(istream& in, BST& tree)
{
	int x;
	in >> x;
	tree.insert(x);
	return in;
}

ostream& operator<<(ostream& out, BST tree)
{
	tree.display();
	return out;
}
