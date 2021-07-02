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

struct Image {
	int mx = 0;
	int my = 0;
	int* pixels;
	/*
	Image(int tmx, int tmy)
	{
		mx = tmx;
		my = tmy;
		pixels = new int[mx * my + 1];
	}
	
	~Image()
	{
		delete []pixels;
	}
	*/
	
};

void createImage(Image* img, int tmx, int tmy)
{
	img->mx = tmx;
	img->my = tmy;
	img->pixels = new int[tmx * tmy]{ 1 };
}

void setPointImage(Image* img, int x, int y, int color)
{
	img->pixels[(y * img->mx + x)] = color;
}

int getPointImage(Image* img, int x, int y)
{
	return img->pixels[y * img->mx + x];
}

void showImage(Image* img)
{
	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++)
		{
			cout << img->pixels[i * img->mx + j] << " ";
			//color output?
		}
		cout << endl;
	}
}

void saveImage(Image* img, const string filename)
{
	fstream out;
	out.open(filename, fstream::out);
	out << "P1" << endl;
	out << img->mx << " " << img->my << endl;

	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++)
		{
			out << img->pixels[i * img->mx + j] << " ";
		}
		out << endl;
	}

	out.close();
}


bool testCreateImage()
{
	Image* im = new Image;
	createImage(im, 2, 5);

	if (im->pixels[0] == 0 && im->pixels[9] == 0 && im->mx == 2 && im->my == 5)
		return true;

	return false;
}

bool testGetPointImage()
{
	Image* im = new Image;
	createImage(im, 2, 5);
	im->pixels[9] = 255;

	if (getPointImage(im, 1, 4) == 255 && getPointImage(im, 1, 2) == 0)
		return true;

	return false;
}

bool testSetPointImage()
{
	Image* im = new Image;
	createImage(im, 2, 5);
	setPointImage(im, 1, 0, 127);
	setPointImage(im, 1, 4, 255);

	if (getPointImage(im, 1, 0) == 127 && getPointImage(im, 1, 4) == 255)
		return true;
	
	return false;
}

void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction())
		cout << "Test " << testName << " - OK" << endl;
	else
		cout << "Test " << testName << " - FAIL" << endl;
}

int main()
{
	runTest(testCreateImage, "CreateImage");
	runTest(testGetPointImage, "GetPointImage");
	runTest(testSetPointImage, "SetPointImage");

	Image* img_ptr = new Image;
	createImage(img_ptr, 3, 3);
	setPointImage(img_ptr, 0, 0, 1);
	setPointImage(img_ptr, 1, 1, 1);
	setPointImage(img_ptr, 2, 2, 1);
	showImage(img_ptr);
	saveImage(img_ptr, "hello_image.pnm");
}
