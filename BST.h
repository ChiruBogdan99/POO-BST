
#include <iostream>
#include "queue.h"
using namespace std;

class node;

class BST
{
	node* root;
	node* deleteTree(node* root);
	node* create(int x);
	void insert(int x, node* & root);
	void remove(int x, node* & root);
	node* findMin(node* root);
	node* findMax(node* root);

	void inorder(node* root);
	void leafs(node* root);
	int height(node* root);
	void copy(node* & tree1, node* & root);
public:
	BST();
	//BST(BST& tree);
	~BST();
	void insert(int x);
	void remove(int x);
	void display();
	int height();
	void leafs();

	BST operator+(int x);

	friend istream& operator>>(istream& in, BST& tree);
	friend ostream& operator<<(ostream& out, BST tree);
};

