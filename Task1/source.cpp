#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	a += b;
	b = a - b;
	a -= b;
}

void lRoundShiftMas(int* source, int n, int size)
{
	int num = source[0];

	for (int i = 0; i < n; i++)
	{
		int index = size - n + i;

		while (index >= 0)
		{
			swap(num, source[index]);

			index -= n;
		}
	}
}

int main()
{
	int mas[] = { 1, 2, 3, 4, 5};

	lRoundShiftMas(mas, 4, 5);

	for (int i : mas) cout << i << " ";
}
