#include <iostream>
using namespace std;

struct Node 
{
  int val;
  Node* next = NULL;
};

// Инициализации элемента односвязного списка нулями
void init(Node* node)
{
	node->val = 0;
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
	while (cur->next != NULL) cur = cur->next;

	cur->next = new Node;
	cur->val = node->val;
} 



//Написать функцию сдвига значений влево на n-элементов с переносом вытесненных элементов в конец
void lRoundShiftNode(Node* root, int n, int size) 
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

int testFunction()
{
  Node* root = new Node;
  
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

	return ((f1 && f2 && f3)? 0 : -1);
}



static void runTest(int (*testFunction)(),const string& testName)
{
  if(testFunction()==0)
    std::cout << "Test "<< testName << " - OK" << std::endl;
  else 
    std::cout << "Test "<< testName << " - FAIL" << std::endl;
}

int main() 
{
  runTest(testlRoundShiftNode,"testSkoFromList");
}
