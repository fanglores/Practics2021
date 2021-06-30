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

}

// Отображения односвязного списка на экран
void show(Node* root) 
{

}

// Добавления элемента в односвязный список
void pushNode(Node* root, Node* node) 
{

} 



//Написать функцию сдвига значений влево на n-элементов с переносом вытесненных элементов в конец
void lRoundShiftNode(Node* root, int n, int size) 
{

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
