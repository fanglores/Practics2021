#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
};

// Инициализации элемента односвязного списка нулями
void init(Node* node)
{
	node->val = 0;
	node->next = NULL;
}

// Отображения односвязного списка на экран
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

// Добавления элемента в односвязный список
void pushNode(Node* root, Node* node)
{
	Node* cur = root;
	while (cur->next != NULL) 
		cur = cur->next;

	cur->next = new Node;
	init(cur->next);
	cur->val = node->val;
}

//Написать функцию сдвига значений влево на n-элементов с переносом вытесненных элементов в конец
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

//push test
bool testPushNode()
{
	Node* root = new Node;

	init(root);
	pushNode(root, new Node{ 1 });
	pushNode(root, new Node{ 2 });
	return (root->next->val == 2 && root->val == 1);
}

bool testInitNode()
{
	Node* root = new Node;

	init(root);
	return (root->val == 0);

}

bool testlRoundShiftNode()
{
	Node* root = new Node;

	init(root);
	pushNode(root, new Node{ 1 });
	pushNode(root, new Node{ 2 });
	pushNode(root, new Node{ 3 });
	pushNode(root, new Node{ 4 });
	lRoundShiftNode(root, 3);
	return (root->val == 4 && root->next->val == 1 && root->next->next->val == 2 && root->next->next->next->val == 3);

}

static void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction() == 1)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
	runTest(testInitNode, "Init test");
	runTest(testPushNode, "Push test");
	runTest(testlRoundShiftNode, "lRoundShiftTest");
}
