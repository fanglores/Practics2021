#include <iostream>
using namespace std;

const int MASSIZE = 1000;
int mas[MASSIZE];

//default swap function
void swap(int& a, int& b)
{
	a += b;
	b = a - b;
	a -= b;
}


// Вариант 7:
// Написать функцию сдвига влево на n-элементов с переносом вытесненных элементов в конец
void lRoundShiftMas(int* source,int n, int size) 
{
  int* tmp = new int[n];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = source[i];
		source[i] = source[n + i];
	}

	for (int i = n; i < size - n; i++)
	{
		source[i] = source[n + i];
	}

	for (int i = size - n; i < size; i++)
	{
		source[i] = tmp[i - size + n];
	}
}

// Тесты
//compare two arrays. If both are identical, return 1; else 0.
bool CompareMas(int* a, int* b, int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] != b[i]) return false;

	return true;
}

// Вариант 7:
// Написать функцию сдвига влево на n-элементов с переносом вытесненных элементов в конец
int testlRoundShiftMas() 
{
 	int tmas1[5] = {1,2,3,4,5};
	int amas1[5] = {4,5,1,2,3};
	lRoundShiftMas(tmas1, 3, 5);	
	bool f1 = CompareMas(tmas1, amas1, 5);

	int tmas2[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int amas2[10] = { 6,5,4,3,2,1,10,9,8,7 };
	lRoundShiftMas(tmas2, 4, 10);
	bool f2 = CompareMas(tmas2, amas2, 10);

	int tmas3[10] = { -1,-3,-5,-7,-9,0,8,6,4,2 };
	int amas3[10] = { 0,8,6,4,2,-1,-3,-5,-7,-9 };
	lRoundShiftMas(tmas3, 5, 10);
	bool f3 = CompareMas(tmas3, amas3, 10);

	return ((f1 && f2 && f3)? 0 : -1);
}

void runTest(int (*testFunction)(),const std::string& testName)
{
  if(testFunction()==0)
    std::cout << "Test "<< testName << " - OK" << std::endl;
  else 
    std::cout << "Test "<< testName << " - FAIL" << std::endl;
}

int main() 
{
   runTest(testlRoundShiftMas,"testlRoundShiftMas");
}

