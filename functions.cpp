#include"Paint.h"
#include"graphics.h"
#include<iostream>
using namespace std;

//global functions
void saveImage() {
	writeimagefile(NULL, 100, 50, 1000, 700);
}
void loadImage() {
	readimagefile(NULL, 100, 50, 1000, 700);
}
void intialization() {
	//selection bar
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 100, 1000);
	bar(0, 0, 1000, 50);
	//canvas making
	setfillstyle(SOLID_FILL, WHITE);
	bar(100, 50, 1000, 1000);
	//set color panel
	for (int i = 10; i <= 30; i++)
	{
		for (int j = 60; j <= 80; j++)
		{
			putpixel(i, j, RED);
		}
	}
	for (int i = 50; i <= 70; i++)
	{
		for (int j = 60; j <= 80; j++)
		{
			putpixel(i, j, BLUE);
		}
	}
	for (int i = 10; i <= 30; i++)
	{
		for (int j = 90; j <= 110; j++)
		{
			putpixel(i, j, YELLOW);
		}
	}
	for (int i = 50; i <= 70; i++)
	{
		for (int j = 90; j <= 110; j++)
		{
			putpixel(i, j, GREEN);
		}
	}
	for (int i = 10; i <= 30; i++)
	{
		for (int j = 120; j <= 140; j++)
		{
			putpixel(i, j, BROWN);
		}
	}
	for (int i = 50; i <= 70; i++)
	{
		for (int j = 120; j <= 140; j++)
		{
			putpixel(i, j, WHITE);
		}
	}
	for (int i = 10; i <= 30; i++)
	{
		for (int j = 150; j <= 170; j++)
		{
			putpixel(i, j, CYAN);
		}
	}
	for (int i = 50; i <= 70; i++)
	{
		for (int j = 150; j <= 170; j++)
		{
			putpixel(i, j, MAGENTA);
		}
	}
	for (int i = 10; i <= 30; i++)
	{
		for (int j = 180; j <= 200; j++)
		{
			putpixel(i, j, LIGHTGREEN);
		}
	}
	for (int i = 50; i <= 70; i++)
	{
		for (int j = 180; j <= 200; j++)
		{
			putpixel(i, j, BLACK);
		}
	}
	//bucket selection
	for (int i = 10; i <= 70; i++)
	{
		for (int j = 230; j <= 270; j++)
		{
			putpixel(i, j, WHITE);
		}
	}
	//circle selection
	for (int i = 10; i <= 30; i++)
	{
		for (int j = 290; j <= 310; j++)
		{
			putpixel(i, j, WHITE);
		}
	}
	setcolor(BLACK);
	circle(20, 300, 10);
	//rectangle selection
	for (int i = 50; i <= 70; i++)
	{
		for (int j = 290; j <= 310; j++)
		{
			putpixel(i, j, WHITE);
		}
	}
	setcolor(BLACK);
	rectangle(52, 295, 67, 305);
	//triangle selection
	readimagefile("triangle.jpg", 10, 330, 30, 350);
	//line selection
	for (int i = 50; i <= 70; i++)
	{
		for (int j = 330; j <= 350; j++)
		{
			putpixel(i, j, WHITE);
		}
	}
	setcolor(BLACK);
	line(52, 335, 67, 345);
	//pen selection
	readimagefile("pen1.jpg", 10, 360, 70, 380);
	//eraser selection
	readimagefile("eraser_1.jpg", 10, 390, 70, 420);
	//colorfill shapes
	readimagefile("bucket_1.jpg", 10, 430, 70, 460);
	//textbox
	for (int i = 10; i <= 30; i++)
	{
		for (int j = 470; j <= 490; j++)
		{
			putpixel(i, j, BLACK);
		}
	}
	setcolor(WHITE);
	outtextxy(15, 475, "A");
	setcolor(BLACK);
	//save
	readimagefile("save.jpg", 100, 10, 150, 40);
	//load
	readimagefile("load.jpg", 920, 10, 970, 40);
}
void selectOption(int& sx, int& sy)
{
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(500);
	}
	getmouseclick(WM_LBUTTONDOWN, sx, sy);

}
int SelectColour(int cx, int cy)
{
	if (cx >= 10 && cx <= 30 && cy >= 60 && cy <= 80) {
		return RED;
	}
	if (cx >= 50 && cx <= 70 && cy >= 60 && cy <= 80) {
		return BLUE;
	}
	if (cx >= 10 && cx <= 30 && cy >= 90 && cy <= 110) {
		return YELLOW;
	}
	if (cx >= 50 && cx <= 70 && cy >= 90 && cy <= 110) {
		return GREEN;
	}
	if (cx >= 10 && cx <= 30 && cy >= 120 && cy <= 140) {
		return BROWN;
	}
	if (cx >= 50 && cx <= 70 && cy >= 120 && cy <= 140) {
		return WHITE;
	}
	if (cx >= 10 && cx <= 30 && cy >= 150 && cy <= 170) {
		return CYAN;
	}
	if (cx >= 50 && cx <= 70 && cy >= 150 && cy <= 170) {
		return MAGENTA;
	}
	if (cx >= 10 && cx <= 30 && cy >= 180 && cy <= 200) {
		return LIGHTGREEN;
	}
	if (cx >= 50 && cx <= 70 && cy >= 180 && cy <= 200) {
		return BLACK;
	}
}
void Drag_drop(int&startx, int&starty, int&endx, int&endy) {
	int  x = -1, y = -1;
	bool t = true;
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_LBUTTONDOWN);
	while (t == true) {
		if (ismouseclick(WM_LBUTTONUP)) {
			getmouseclick(WM_LBUTTONUP, x, y);
			if (x != -1 && y != -1) {
				endx = x;
				endy = y;
				clearmouseclick(WM_LBUTTONUP);
				cout << startx << "  " << starty << "  " << endx << "  " << endy << endl;
				t = false;
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (x != -1 && y != -1) {
				startx = x;
				starty = y;
				clearmouseclick(WM_LBUTTONDOWN);
			}
		}

	}
}
void selectCoordinates(int& x1, int& y1)
{
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(500);
	}
	getmouseclick(WM_LBUTTONDOWN, x1, y1);
	cout << x1 << " " << y1 << endl;
	clearmouseclick(WM_LBUTTONDOWN);

	return;
}
int PaintSelection(Board*& b1)
{
	int x, y = 0;
	selectCoordinates(x, y);
	b1->paint_selection(x, y);
	int cl = SelectColour(x, y);
	return cl;
}
void bucketcolor_normal() {
	setviewport(0, 0, 1000, 1000, 1);
	//bucket selection
	for (int i = 10; i <= 70; i++)
	{
		for (int j = 230; j <= 270; j++)
		{
			putpixel(i, j, WHITE);
		}
	}
}

//classes function
void Board::paint_selection(int x, int y) {
	bool t = true;
	
	while (t == true) {
		if (x >= 10 && x <= 30 && y >= 60 && y <= 80) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, RED);
				}
			}
		}
		if (x >= 50 && x <= 70 && y >= 60 && y <= 80) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, BLUE);
				}
			}
		}
		if (x >= 10 && x <= 30 && y >= 90 && y <= 110) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, YELLOW);
				}
			}
		}
		if (x >= 50 && x <= 70 && y >= 90 && y <= 110) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, GREEN);
				}
			}
		}
		if (x >= 10 && x <= 30 && y >= 120 && y <= 140) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, BROWN);
				}
			}
		}
		if (x >= 50 && x <= 70 && y >= 120 && y <= 140) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, WHITE);
				}
			}
		}
		if (x >= 10 && x <= 30 && y >= 150 && y <= 170) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, CYAN);
				}
			}
		}
		if (x >= 50 && x <= 70 && y >= 150 && y <= 170) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, MAGENTA);
				}
			}
		}
		if (x >= 10 && x <= 30 && y >= 180 && y <= 200) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, LIGHTGREEN);
				}
			}
		}
		if (x >= 50 && x <= 70 && y >= 180 && y <= 200) {
			for (int i = 10; i <= 70; i++)
			{
				for (int j = 230; j <= 270; j++)
				{
					putpixel(i, j, BLACK);
				}
			}
		}
		t = false;
		if (t == false) {
			break;
		}
	}
}
void Circle:: make_circle(int startx, int starty, int cx, int cy, int cl) {
	div1y = starty-100;
	div2y = cy-100;
	div2y -= div1y;
	circleratio = div2y;
	if (circleratio < 0) {
		circleratio *= -1;
	}
	cout << startx << "  " << starty << "  " << "  " << circleratio << endl;
	setcolor(cl);
	circle((startx-50), (starty), circleratio/2);
}
void Circle:: fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1) {
	if (x >= 10 && x <= 70 && y >= 430 && y <= 460) {
		setviewport(0, 0, 1000, 1000, 1);
		int startx = 0, starty = 0;
		cout << "fill shape selected" << endl;
		int cl = PaintSelection(b1);
		setfillstyle(SOLID_FILL, cl);
		selectCoordinates(startx, starty);
		setviewport(100, 50, 1000, 1000, 1);
		floodfill(startx - 100, starty - 50, col);
		cout << "fill shape x,y" << endl;
		cout << startx << "  " << starty << endl;
		bucketcolor_normal();
	}
}
void Rectangle_Shape::make_rectangle(int startx, int starty, int cx, int cy, int cl) {
	cout << startx << "  " << starty << "  " << endl;
	setcolor(cl);
	rectangle(startx - 100, starty - 50, cx - 100, cy - 50);
}
void Rectangle_Shape::fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1) {
	if (x >= 10 && x <= 70 && y >= 430 && y <= 460) {
		setviewport(0, 0, 1000, 1000, 1);
		int startx = 0, starty = 0;
		cout << "fill shape selected" << endl;
		int cl = PaintSelection(b1);
		setfillstyle(SOLID_FILL, cl);
		selectCoordinates(startx, starty);
		setviewport(100, 50, 1000, 1000, 1);
		floodfill(startx - 100, starty - 50, col);
		cout << "fill shape x,y" << endl;
		cout << startx << "  " << starty << endl;
		bucketcolor_normal();
	}
}
void Triangle::make_triangle(int startx, int starty, int cx, int cy, int tx, int ty, int cl)
{
	setcolor(cl);
	line(startx - 100, starty - 50, cx - 100, cy - 50);
	line(cx - 100, cy - 50, tx - 100, ty - 50);
	line(tx - 100, ty - 50, startx - 100, starty - 50);
}
void Triangle::fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1)
{
	if (x >= 10 && x <= 70 && y >= 430 && y <= 460) {
		setviewport(0, 0, 1000, 1000, 1);
		int startx = 0, starty = 0;
		cout << "fill shape selected" << endl;
		int cl = PaintSelection(b1);
		setfillstyle(SOLID_FILL, cl);
		selectCoordinates(startx, starty);
		setviewport(100, 50, 1000, 1000, 1);
		floodfill(startx - 100, starty - 50, col);
		cout << "fill shape x,y" << endl;
		cout << startx << "  " << starty << endl;
		bucketcolor_normal();
	}
}
void Line::make_Line(int startx, int starty, int cx, int cy, int cl) {
	setcolor(cl);
	line(startx - 100, starty - 50, cx - 100, cy - 50);
}
void Line::fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1) {}
void Pen::Pen_draw(int cl) {
	int startx, starty;
	bool t = true;
	setcolor(cl);
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_LBUTTONDOWN);
	while (t == true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			startx = mousex();
				starty = mousey();
				setfillstyle(SOLID_FILL, cl);
				fillellipse(startx - 100, starty - 50, 10, 10);
			
		}
		if (ismouseclick(WM_LBUTTONUP)) {
			getmouseclick(WM_LBUTTONUP, startx, starty);
			if (startx != -1 && starty != -1) {
				startx = mousex();
				starty = mousey();
				clearmouseclick(WM_LBUTTONUP);
				cout << "Pen stopped" << endl;
				t = false;
			}
		}
	}
}
void Pen::fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1) {}
void Eraser::Eraser_draw() {
	int startx, starty;
	bool t = true;
	setcolor(WHITE);
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_LBUTTONDOWN);
	while (t == true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			startx = mousex();
			starty = mousey();
			setfillstyle(SOLID_FILL, WHITE);
			fillellipse(startx - 100, starty - 50, 10, 10);

		}
		if (ismouseclick(WM_LBUTTONUP)) {
			getmouseclick(WM_LBUTTONUP, startx, starty);
			if (startx != -1 && starty != -1) {
				startx = mousex();
				starty = mousey();
				clearmouseclick(WM_LBUTTONUP);
				cout << "ERASER stopped" << endl;
				t = false;
			}
		}
	}
}
void Eraser::fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1) {}
void Textbox::fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1) {}
void Textbox::writeinbox(int& startx, int& starty, Board* b1) {
	try {
		char array1[100];
		int num1, num2, cl;
		cout << " Please enter the size of the text(1-8): " << endl;
		cin >> num2;
		if (num2 > 8)
		{
			throw num2;
		}
		settextstyle(1, 0, num2);
		cout << "Please enter a text: " << endl;
		cin.ignore();
		cin.getline(array1, 100);
		setviewport(0, 0, 1000, 1000, 1);
		cl = PaintSelection(b1);
		setcolor(cl);
		setbkcolor(WHITE);
		setviewport(100, 50, 1000, 1000, 1);
		selectCoordinates(startx, starty);
		outtextxy(startx - 100, starty - 50, array1);
		bucketcolor_normal();
	}
	catch (int a)
	{
		cout << " The value " << a << " Doesnt exist for a text style " << endl;
	}
}
void Bucket::fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1) {};
void Bucket::bucket_color(int cl) {
		setviewport(0, 0, 1000, 1000, 1);
		int startx = 0, starty = 0;
		cout << "fill shape selected" << endl;
		setfillstyle(SOLID_FILL, cl);
		selectCoordinates(startx, starty);
		setviewport(100, 50, 1000, 1000, 1);
		floodfill(startx - 100, starty - 50, BLACK);
		cout << "fill shape x,y" << endl;
		cout << startx << "  " << starty << endl;
		bucketcolor_normal();
}
void Driver::drive() {
	{
		intialization();
		setcolor(BLACK);
		int cx = 0, cy = 0, startx = 0, starty = 0,spx,spy;
		int x, y;
		Board* b1;
		Circle c1;
		Rectangle_Shape r1;
		Triangle T1;
		Pen p1;
		Eraser e1;
		Textbox t1;
		Line l1;
		selectOption(startx, starty);
		while (true) {
			//circle
			if (startx >= 10 && startx <= 30 && starty >= 290 && starty <= 310) {
				b1 = new Circle;
				int cl;
				cout << "circle  selected" << endl;
				setviewport(0, 0, 1000, 700, 1);
				//Paint selection bar
				cl = PaintSelection(b1);
				Drag_drop(x, y, cx, cy);
				setviewport(100, 50, 1000, 1000, 1);
				b1->make_circle(x, y, cx, cy, cl);
				bucketcolor_normal();
				setcolor(BLACK);
				selectOption(startx, starty);
				if (startx >= 10 && startx <= 70 && starty >= 430 && starty <= 460) {
					b1->fill_shapes(startx, starty, cx, cy, x, y, cl, b1);
					selectOption(startx, starty);
				}
			}
			//rectangle
			else if (startx >= 50 && startx <= 70 && starty >= 290 && starty <= 310) {
				cout << "rectangle selected" << endl;
				b1 = &r1;
				int cl;
				setviewport(0, 0, 1000, 1000, 1);
				//Paint selection bar
				cl = PaintSelection(b1);
				Drag_drop(cx, cy, x, y);
				setviewport(100, 50, 1000, 1000, 1);
				b1->make_rectangle(cx, cy, x, y, cl);
				bucketcolor_normal();
				selectOption(startx, starty);
				if (startx >= 10 && startx <= 70 && starty >= 430 && starty <= 460) {
					b1->fill_shapes(startx, starty, cx, cy, x, y, cl, b1);
					selectOption(startx, starty);
				}
			}
			//Triangle 
			else if (startx >= 10 && startx <= 30 && starty >= 330 && starty <= 350) {
				int tx, ty;
				cout << " Triangle selected  " << endl;
				b1 = &T1;
				int cl;
				setviewport(0, 0, 1000, 1000, 1);
				//Paint selection bar
				cl = PaintSelection(b1);
				selectCoordinates(cx, cy);
				selectCoordinates(x, y);
				selectCoordinates(tx, ty);
				cout << cx << " " << cy << " " << x << " " << y << " " << tx << " " << ty << endl;
				setviewport(100, 50, 1000, 1000, 1);
				b1->make_triangle(cx, cy, x, y, tx, ty, cl);
				bucketcolor_normal();
				selectOption(startx, starty);
				if (startx >= 10 && startx <= 70 && starty >= 430 && starty <= 460) {
					b1->fill_shapes(startx, starty, cx, cy, x, y, cl, b1);
					selectOption(startx, starty);
				}
			}
			//Line
			else if (startx >= 50 && startx <= 70 && starty >= 330 && starty <= 350) {
				cout << " Line selected  " << endl;
				b1 = &l1;
				int cl;
				setviewport(0, 0, 1000, 1000, 1);
				//Paint selection bar
				cl = PaintSelection(b1);
				Drag_drop(cx, cy, x, y);
				cout << cx << " " << cy << " " << x << " " << y << endl;
				setviewport(100, 50, 1000, 1000, 1);
				b1->make_Line(x, y, cx, cy, cl);
				bucketcolor_normal();
				selectOption(startx, starty);
			}
			//PEN DRAW
			else if (startx >= 10 && startx <= 70 && starty >= 360 && starty <= 380) {
				cout << "PEN selected" << endl;
				int px, py;
				int cl;
				b1 = &p1;
				setviewport(0, 0, 1000, 1000, 1);
				cl = PaintSelection(b1);
				setviewport(100, 50, 1000, 1000, 1);
				b1->Pen_draw(cl);
				bucketcolor_normal();
				selectOption(startx, starty);
			}
			//ERASER
			else if (startx >= 10 && startx <= 70 && starty >= 390 && starty <= 420) {
				cout << "Eraser selected" << endl;
				setviewport(0, 0, 1000, 1000, 1);
				b1 = &e1;
				setviewport(100, 50, 1000, 1000, 1);
				b1->Eraser_draw();
				selectOption(startx, starty);
			}
			//TEXTBOX
			else if (startx >= 10 && startx <= 30 && starty >= 470 && starty <= 490) {
				cout << "Textbox selected" << endl;
				setviewport(0, 0, 1000, 1000, 1);
				b1 = &t1;
				setviewport(100, 50, 1000, 1000, 1);
				b1->writeinbox(startx, starty, b1);
				selectOption(startx, starty);
			}
			//Bucket
			else if (startx >= 10 && startx <= 70 && starty >= 430 && starty <= 460) {
			    cout << "Bucket selected" << endl;
				Bucket b2;
				b1 = &b2;
				int cl = PaintSelection(b1);
				b1->bucket_color(cl);
				selectOption(startx, starty);
			}
			//SAVE
			else if (startx >= 100 && startx <= 150 && starty >= 10 && starty <= 40) {
				saveImage();
				selectOption(startx, starty);
			}
			//LOAD
			else if (startx >= 920 && startx <= 970 && starty >= 10 && starty <= 40) {
				loadImage();
				selectOption(startx, starty);
			}
			else {
			cout << "Wrong Selection" << endl;
			selectOption(startx, starty);
}
		}
	}
}
