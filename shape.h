#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>
#include <iomanip>
using namespace std;
//----------------------------------------------------------------
class Shape
{
int no;
public:
virtual int getArea()=0;
};
//----------------------------------------------------------------
class Point
{
int x;
int y;
};

//----------------------------------------------------------------
class Rectangle: public Shape
{
int width;
int height;
Point leftUp;

public:
Rectangle(int no = 0, int width = 0, int height = 0, int x = 0, int y = 0)
:: Shape(no), width_(width), height_(height), leftUp_(Point(x,y)){ }

virtual int getArea() const{
     return width_ * height_; 
}

virtual void print() const { 
     cout << "Rect No." << setw(2) << setfill('0') \
    << this->getNo() << "\'s area: " << this->getArea() << endl; 
}

virtual ~Rectangle() { }
};

//----------------------------------------------------------------
class Circle: public Shape
{
Point center;
int radius;

public:
	Circle(int no = 0, int radius = 0, int x = 0, int y = 0)
	: Shape(no), radius_(radius), center_(Point(x, y)) { }
	
	virtual int getArea() const {
	     return PI * radius_ * radius_; 
	}
	virtual void print() const { 
	     cout << "Cir  No." << setw(2) << setfill('0') << this->getNo()\
	     << "\'s area: " << this->getArea() << endl;
	}
	virtual ~Circle() { } 
};



#endif
//__SHAPE_H__
//end of this shape.h flie

