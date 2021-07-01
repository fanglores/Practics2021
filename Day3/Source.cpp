#include <iostream>
#include <iomanip>
using namespace std;

/*
Задача 6
Вариант 2

Разработать программу для моделирования полета брошенного с высоты h  со скоростью v шарика массой m. 
При соударении с землей шарик прилипает к поверхности.
Программа должна иметь функции:
- Вычисления положения (h) и параметров движения шарика (v, a) через заданный промежуток времени
- Позволять записывать параметы движения шарика и метку времении в односвязный список
- Печатать на экран информацию о траектории движения шарика за заданный промежуток времени

Тесты
*/

const double g = 9.80665;

struct DataList
{
	double h, v, a, t;
	DataList* next;
};

void initList(DataList* root)
{
	root->t = 0;
	root->h = 0;
	root->v = 0;
	root->a = 0;
	root->next = NULL;
}

void writeList(DataList* ls, double h, double v, double a, double t)
{
	DataList* ls_end = ls;
	while (ls_end->next != NULL)
		ls_end = ls_end->next;

	ls_end->t = t;
	ls_end->h = h;
	ls_end->v = v;
	ls_end->a = a;

	ls_end->next = new DataList;
	initList(ls_end->next);
}

DataList* simulate(double h, double v, double dt)
{
	DataList* output = new DataList;
	initList(output);
	

	double a = g;
	double apogee_t, touch_t, apogee_h;
	if (v > 0)
	{
		//считаем время достижения наивысшей точки, увеличение высоты, время падения из наивысшей точки
		apogee_t = v / a;
		double dh = v * v / (2 * a);
		apogee_h = h + dh;
		touch_t = sqrt(2 * apogee_h / a);

		writeList(output, h, v, -g, 0);
	}
	else	
	{
		//мяч уже падает, считаем только время падения
		apogee_t = 0;
		apogee_h = h;
		touch_t = (-abs(v) + sqrt(v * v + 2 * a * h)) / a;
		

		writeList(output, h, v, g, 0);
	}

	double ct = dt;
	//рассматриваем состояния dt во время движения вверх и записываем в DataList
	while (ct <= apogee_t)
	{
		h += v * dt - a * dt * dt / 2;
		v -= a * dt;
		writeList(output, h, v, -g, ct);
		ct += dt;
	}
	//обновляем параметры (тк в следующий момент dt шарик уже мог опуститься)
	v = a * (ct - apogee_t); 
	h = apogee_h - a * (ct - apogee_t) * (ct - apogee_t) / 2;
	writeList(output, h, -v, -g, ct);
	ct += dt;
	//рассматриваем состояния dt во время движения вниз и записываем в DataList
	while (ct < apogee_t + touch_t)
	{
		h -= v * dt + a * dt * dt / 2;
		v += a * dt;
		writeList(output, h, -v, -g, ct);
		ct += dt;
	}

	writeList(output, 0, 0, 0, ct);
	cout << "Simulation has been stopped due to changeless environment" << endl;

	return output;
}

void print(DataList* ls, double t)
{
	cout << "Printing data sheet..." << endl;
	cout << "Time\tHeight\tVelocity\tAcceleration" << endl;

	DataList* cur_dl = ls;
	while (cur_dl->next != NULL && cur_dl->t <= t)
	{
		cout << fixed << showpoint;
		cout << setprecision(2);
		cout << (double)cur_dl->t << "\t" << cur_dl->h << "\t" << cur_dl->v << "\t\t" << cur_dl->a << endl;
		cur_dl = cur_dl->next;
	}
}

bool testDataListInit()
{
	DataList* tmp = new DataList;
	initList(tmp);
	tmp->next = new DataList;
	initList(tmp->next);
	if (tmp->a == 0 && tmp->next != NULL)
		if (tmp->next->a == 0 && tmp->next->next == NULL) 
			return true;

	return false;
}

bool testDataListWrite()
{
	DataList* tmp = new DataList;
	initList(tmp);

	writeList(tmp, 1.2345, 1, 1, 0.000001);
	writeList(tmp->next, -1, 1000, -1.09876, 1);

	if (tmp->h == 1.2345 && tmp->t == 0.000001)
		if (tmp->next->a == -1.09876 && tmp->next->v == 1000)
			return true;
	
	return false;
}

bool testSimulate()
{
	DataList* out = simulate(g, 2 * g, 1.0);

	if (out->h - g < 0.001 && out->a == -g && out->v == 2 * g && out->t == 0)	//t = 0
	{
		out = out->next;
		if (out->h - 2.5 * g < 0.001 && out->a == -g && out->v == g && out->t == 1)	//t = 1
		{
			out = out->next;
			if (out->h - 3.0 * g < 0.001 && out->a == -g && out->v == 0 && out->t == 2)	//t = 2
			{
				out = out->next;
				if (out->h - 2.5 * g < 0.001 && out->a == -g && out->v == -g && out->t == 3)	//t = 3
				{
					out = out->next;
					if (out->h - g < 0.001 && out->a == -g && out->v == -2 * g && out->t == 4)	//t = 4
					{
						out = out->next;
						if (out->h == 0 && out->a == 0 && out->v == 0 && out->t == 5)	//t = 5
						{
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction() == true)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
	runTest(testDataListInit, "DataListInit");
	runTest(testDataListWrite, "DataListWrite");
	runTest(testSimulate, "Simulation");
	//DataList* dl = simulate(g, 2 * g, 1.0);
	//print(dl, 100);
}
