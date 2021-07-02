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

void createImage(Image* img, int tmx, int tmy)
{
	img->mx = tmx;
	img->my = tmy;
	img->pixels = new int[tmy * tmx]{ 0 };
}

void setPointImage(Image* img, int x, int y, int color)
{
	img->pixels[(y - 1) * img->mx + x - 1] = color;
}

int getPointImage(Image* img, int x, int y)
{
	return img->pixels[(y - 1) * img->mx + x - 1];
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
/*
void saveImage(Image* img, char& filename)
{
	FILE* out;
	out = fopen_s(filename, "xz");	//color format?
	fprintf(out, "P6\n");
	fprintf(out, "%d %d\n", img->mx, img->my);
	fprintf(out, "%d\n", 255);
	fwrite(img->pixels, 3 * img->mx, img->my, out);

	fclose(out);
}
*/

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

	if (getPointImage(im, 2, 5) == 255 && getPointImage(im, 1, 4) == 0)
		return true;

	return false;
}

bool testSetPointImage()
{
	Image* im = new Image;
	createImage(im, 2, 5);
	setPointImage(im, 1, 3, 127);
	setPointImage(im, 2, 5, 255);

	if (getPointImage(im, 1, 3) == 127 && getPointImage(im, 2, 5) == 255)
		return true;

	return false;
}



bool testSaveImage()
{


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
	Image* img_ptr = new Image;
	runTest(testCreateImage, "CreateImage");
	runTest(testGetPointImage, "GetPointImage");
	runTest(testSetPointImage, "SetPointImage");

}
