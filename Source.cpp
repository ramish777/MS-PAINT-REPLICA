#include"Paint.h"
#include"graphics.h"
#include<iostream>
using namespace std;
//global functions
void saveImage();
void loadImage();
void intialization();
void selectOption(int& sx, int& sy);
int SelectColour(int cx, int cy);
void Drag_drop(int& startx, int& starty, int& endx, int& endy);
void selectCoordinates(int& x1, int& y1);
int PaintSelection(Board*& b1);
void bucketcolor_normal();

//driver class
int main()
{
	initwindow(1000, 7100, "Fast Paint");
	Driver d1;
	d1.drive();
	system("pause");
	return 0;
}
