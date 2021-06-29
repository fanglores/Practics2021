#define TESTING 1
//place 1 to run testing functions and 0 to run main program

#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next = NULL;	
};

//initialization function
void init(Node* node)
{
	node->val = 0;
}

//print function
void show(Node* root)
{
	Node* cur = root;
	while (cur->next != NULL)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

//push function
void pushNode(Node* root, Node* node)
{
	Node* cur = root;
	while (cur->next != NULL) cur = cur->next;

	cur->next = new Node;
	cur->val = node->val;
}

//round shift function
void lRoundShiftNode(Node* root, int n)
{
	for (int i = 0; i < n; i++)
	{
		Node* cur = root;
		int num = cur->val;
		while (cur->next->next != NULL)
		{
			cur->val = cur->next->val;
			cur = cur->next;
		}
		cur->val = num;
	}
}

bool testFunction(Node* root)
{
	//push test
	pushNode(root, new Node{ 1 });
	pushNode(root, new Node{ 2 });
	bool f1 = (root->next->val == 2 && root->val == 1);

	//init test
	init(root->next);
	bool f2 = (root->next->val == 0);

	//round shift test
	root->next->val = 2;
	pushNode(root, new Node{ 3 });
	pushNode(root, new Node{ 4 });
	lRoundShiftNode(root, 3);
	bool f3 = (root->val == 4 && root->next->val == 1 
		&& root->next->next->val == 2 && root->next->next->next->val == 3);

	return (f1 && f2 && f3);
}

int main()
{
	//node array
	Node* narr = new Node;

	if (TESTING == 0)
	{
		pushNode(narr, new Node{ 1 });
		pushNode(narr, new Node{ 2 });
		pushNode(narr, new Node{ 3 });

		show(narr);
		lRoundShiftNode(narr, 2);
		show(narr);
	}
	else
	{
		if (testFunction(narr) == 1) cout << "All tests successful";
		else cout << "Testing failed";
	}
}
