#include "shape.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const double PI = 3.141592; 
const int count = 20;//长度为 20 的数组

//---------------------------print shape function -------------------------------------

void Print_Shape(Shape* myshape[], int cnt) {
	for (int i=0; i<cnt; ++i) {
		myshape[i]->print();
	}
}


//---------------------------clear the myshape data -----------------------------------

void Delete_Data(Shape* myshape[], int cnt) {
	for (int i=0; i<cnt; ++i) {
		delete myshape[i];
		myshape[i] = nullptr;
	}
}

//----------------------------delete the area of shape less than 50------------------

int Filte_Shape(Shape* myshape[], int cnt) {
	int ncnt = 0;
	for (int i=0; i<cnt; ++i) {
		if (myshape[i]->getArea()>=50) {
			myshape[ncnt++] = myshape[i];
		} else {
			delete myshape[i];
			myshape[i] = nullptr;
		}
	}
	return ncnt;
}

//-----------------------------create and set the shape--------------------------------

void Set_Shape(Shape* shape[], int cnt) {
	time_t t;
	srand((unsigned)time(&t));
	for (int i=0; i<cnt/2; ++i) {
		int w = rand()%10 + 1;
		int h = rand()%10 + 1;
		int x = rand()%10 + 1;
		int y = rand()%10 + 1;
		shape[i] = new Rectangle(i+1, w, h, x, y);
	}
	for (int i=cnt/2; i<cnt; ++i) {
		int c = rand()%10 + 1;
		int x = rand()%10 + 1;
		int y = rand()%10 + 1;
		shape[i] = new Circle(i+1, c, x, y);
	}
}

//------------------------------  main function    ----------------------------------

int main(int argc, char** argv){

	Shape* myshape[count];
	Set_Shape(myshape, count);	
	
	cout << "******************   Before filter ******************" << endl;
	Print_Shape(myshape, count);	
	
	cout << "******************   After filter  ******************" << endl;
	int ncnt = Filter_Shape(myshape, count);
	Print_Shape(myshape, ncnt);	
	Delete_Data(myshape, ncnt);
	
	return 0;
}



