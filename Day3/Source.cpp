#include <iostream>
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

void write(DataList* ls, double h, double v, double a, double t)
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

		write(output, h, v, -g, 0);
	}
	else	
	{
		//мяч уже падает, считаем только время падения
		apogee_t = 0;
		apogee_h = h;
		touch_t = (-abs(v) + sqrt(v * v + 2 * a * h)) / a;
		

		write(output, h, v, g, 0);
	}

	double ct = dt;
	//рассматриваем состояния dt во время движения вверх и записываем в DataList
	while (ct <= apogee_t)
	{
		h += v * dt - a * dt * dt / 2;
		v -= a * dt;
		write(output, h, v, -g, ct);
		ct += dt;
	}
	//обновляем параметры (тк в следующий момент dt шарик уже мог опуститься)
	v = a * (ct - apogee_t); 
	h = apogee_h - a * (ct - apogee_t) * (ct - apogee_t) / 2;
	write(output, h, -v, g, ct);
	ct += dt;
	//рассматриваем состояния dt во время движения вниз и записываем в DataList
	while (ct < apogee_t + touch_t)
	{
		h -= v * dt + a * dt * dt / 2;
		v += a * dt;
		write(output, h, -v, g, ct);
		ct += dt;
	}

	write(output, 0, 0, 0, ct);
	cout << "Simulation has been stopped due to changeless environment" << endl;
/*
	//рассматриваем состояния dt после падения и записываем в DataList
	if (ct <= apogee_t + touch_t)
	{
		write(output, 0, 0, 0, ct + dt);
		cout << "Simulation stopped due to changeless environment" << endl;
	}
*/
	return output;
}

void print(DataList* ls, double t)
{
	DataList* cur_dl = ls;
	while (cur_dl->next != NULL && cur_dl->t < t)
	{


	}

}

int main()
{
	
	DataList* dl = simulate(g, 2 * g, 1);
	print(dl, );
}
