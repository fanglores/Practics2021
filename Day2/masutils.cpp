#include <iostream>
using namespace std;

const int MASSIZE = 1000;
int mas[MASSIZE];

// Вариант 7:
// Написать функцию сдвига влево на n-элементов с переносом вытесненных элементов в конец
void lRoundShiftMas(int* source,int n, int size) 
{

}

// Тесты
// Вариант 7:
// Написать функцию сдвига влево на n-элементов с переносом вытесненных элементов в конец
int testlRoundShiftMas() 
{
  return -1;
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

