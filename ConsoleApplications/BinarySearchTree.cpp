

#include <iostream>
using namespace std;

struct node {
	int num;
	node* left;
	node* right;
};

void writeNode(int currentValue, node** root) {
	node* currentNode = new node();
	node* parent = NULL;
	currentNode->num = currentValue;
	currentNode->left = NULL;
	currentNode->right = NULL;
	if (*root == NULL) { 
		* root = currentNode;
	} else {
		node* current = *root;
		while (current) {
			parent = current;
			if (currentNode->num > current->num) {
				current = current->right;
			} else {
				current = current->left;
			}
		}
		if (currentNode->num < parent->num) {
			parent->left = currentNode;
		} else {
			parent->right = currentNode;
		}
	}
}

void printTree(node* p, int delta) {
	if (p != NULL) {
		printTree(p->right, delta + 1);
		for (int i = 1; i <= delta; i++) {
			cout << "\t";
		}
		cout << p->num << endl;
		printTree(p->left, delta + 1);
	}
}

int main()
{
	node* root = NULL;
	int x,i,nodes;
	cout << "Enter number of nodes: ";
	cin >> nodes;
	for (int i = 0; i < nodes; i++)
	{
		cout << "Enter node: ";
		cin >> x;
		writeNode(x, &root);
	}
	printTree(root, 0);
}
