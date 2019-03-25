class BST;

class node
{
friend class BST;
	int key;
	node *left, *right;
public:
	node();
	~node();
};

