#ifndef Paint_H
#define Paint_H
#include<iostream>
#pragma once
using namespace std;

class Board
{
private:
	int x, y;
public:
	void paint_selection(int x, int y);
	virtual void make_circle(int a, int b, int c, int d, int cl) {};
	virtual void make_rectangle(int a, int b, int c, int d, int cl) {};
	virtual void make_triangle(int startx, int starty, int cx, int cy, int tx, int ty, int cl) {};
	virtual void make_Line(int startx, int starty, int cx, int cy, int cl) {};
	virtual void Pen_draw(int cl) {};
	virtual void Eraser_draw() {};
	virtual void bucket_color(int cl) {};
	virtual void writeinbox(int& startx, int& starty, Board* b1) {};
	virtual void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1) = 0;
	friend void saveImage();
	friend void loadImage();
	~Board() {
		cout << "Destructor called" << endl;
	}
};
class Circle :public Board {
private:
	int div1y = 0, div2y = 0, div1x = 0, div2x = 0, div3 = 0, circleratio = 0;
public:
	void make_circle(int startx, int starty, int cx, int cy, int cl);
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1);
};
class Rectangle_Shape :public Board {
private:
	int div1 = 0, div2 = 0;
public:
	void make_rectangle(int startx, int starty, int cx, int cy, int cl);
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1);
};
class Triangle :public Board {
	int div1 = 0;
	int div2 = 0;
public:
	void make_triangle(int startx, int starty, int cx, int cy, int tx, int ty, int cl);
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1);
};
class Line : public Board {
int div1 = 0, div2 = 0;
public:
	void make_Line(int startx, int starty, int cx, int cy, int cl);
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1);
};
class Bucket :public Board {
public:
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int col, Board* b1);
	void bucket_color(int cl);
};
class Pen :public Board {
private:
	int px, py;
public:
	void Pen_draw(int cl);
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1);
};
class Eraser :public Board {
private:
	int ex, ey;
public:
	void Eraser_draw();
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1);
};
class Textbox :public Board {
public:
	void fill_shapes(int x, int y, int cx, int cy, int zx, int zy, int cl, Board* b1);
	void writeinbox(int& startx, int& starty, Board* b1);
};
class Driver{
public:
	void drive();
};
#endif // Paint_H




