#include <iostream>
using namespace std;

/*
1. Создание изображения
void createImage(Image* img, int tmx, int tmy)


2. Отображения изображения на экран в pnm формате
void showImage(Image* img)


3. Добавления точки на изображение
void setPointImage(Image* img, int x, int y, int color);


4. Получение точки на изображение
int getPointImage(Image* img, int x, int y);


5. Сохранить изображение в pnm формате
void saveToPnmFile(Image* img, string fileName);
*/

struct Image {
	int mx;
	int my;
	int* pixels;
};


int setPointImage(Image* img, int x, int y)
{
	return img->pixels[(y - 1) * img->mx + x - 1];
}

void getPointImage(Image* img, int x, int y, int color)
{
	img->pixels[(y - 1) * img->mx + x - 1] = color;
}

int main()
{


}
