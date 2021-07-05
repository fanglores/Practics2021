#include <iostream>
#include <fstream>
#include <string>
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

class Image 
{
private:
	int mx;
	int my;
	int* pixels;

public:
	Image() 
	{
		mx = 0;
		my = 0;
	}

	Image(int tmx, int tmy)
	{
		mx = tmx;
		my = tmy;
		pixels = new int[tmx * tmy]{ 1 };
	}

	void setPointImage(int x, int y, int color)
	{
		pixels[(y * mx + x)] = color;
	}

	int getPointImage(int x, int y)
	{
		return pixels[y * mx + x];
	}

	void showImage()
	{
		for (int i = 0; i < my; i++)
		{
			for (int j = 0; j < mx; j++)
				cout << pixels[i * mx + j] << " ";

			cout << endl;
		}
	}

	void saveImage(const string filename)
	{
		fstream out;
		out.open(filename, fstream::out);
		out << "P1" << endl;
		out << mx << " " << my << endl;

		for (int i = 0; i < my; i++)
		{
			for (int j = 0; j < mx; j++)
				out << pixels[i * mx + j] << " ";
			
			out << endl;
		}

		out.close();
	}
};


int main()
{
	Image img(3, 3);
	img.setPointImage(0, 0, 1);
	img.setPointImage(1, 1, 1);
	img.setPointImage(2, 2, 1);
	img.showImage();
	img.saveImage("hello_image.pnm");
}
