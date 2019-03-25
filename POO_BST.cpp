#include <iostream>
#include "node.h"
#include "BST.h"

using namespace std;

int main()
{
	BST tree;
	cout << "Numarul de noduri:";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nodul " << i + 1 << ": ";
		int x;
		cin >> x;
		tree.insert(x);
	}
	cout << "Primul arbore creat prin functia insert: " << endl;
	cout << tree;

	BST tree1;
	cout << "Numarul de noduri:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nodul " << i + 1 << ": ";
		cin >> tree1;
	}
	cout << "Al doilea arbore creat prin supraincarcarea operatorului '>>': " << endl;
	cout << tree1;

    tree1+3;
    cout<<tree1;
}
