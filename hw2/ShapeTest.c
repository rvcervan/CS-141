#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.14159

//maybe
typedef double* (*VirtualMethodPointer)(void *);
//typedef int (*VirtualMethodPointer) (void *);
typedef VirtualMethodPointer * VTableType;
//

typedef struct Shape
{
	VTableType VPointer;
	char* name;
}Shape;

char *Shape_name(Shape * _this)
{
	return _this->name;
}

double Shape_area(Shape * _this)
{
	return 0.0;
}

void Shape_draw(Shape * _this)
{
	printf("Dont see this");
}

void Shape_nums(Shape * _this)
{
	printf("nope dont see this");
}

VirtualMethodPointer Shape_VTable [] = 
{
	(VirtualMethodPointer)Shape_name,
	(VirtualMethodPointer)Shape_area,
	(VirtualMethodPointer)Shape_draw,
	(VirtualMethodPointer)Shape_nums
};

Shape * Shape_Shape(Shape * _this,  char *newName)
{
	_this->VPointer = Shape_VTable;
//	printf(newName);
	//void *memcpy(void *name, const void *newName, size_t n);
	_this->name = newName;
	return _this;
}

typedef struct Triangle
{
	VTableType VPointer;
	char name[50];
	double myHeight;
	double myBase;
	Shape* parent;
}Triangle;

char *Triangle_name(Triangle * _this)
{
	//printf(_this->name);
	return _this->parent->name;
}
double* Triangle_area(Triangle * _this)
{
//	printf("hlle");
//	printf("%f", _this->myHeight);
	double n = .5 * _this->myHeight * _this->myBase;
	double *m = malloc(sizeof(n));
	*m = n;
	return m;
//	return .5 * _this->myHeight * _this->myBase;
}
void Triangle_draw(Triangle * _this)
{
	printf("     *\n    * *\n   *   *\n  *     *\n *       *\n* * * * * *");
}
void Triangle_nums(Triangle * _this)
{
	printf("(");
	printf("%f",_this->myHeight);
	printf(", ");
	printf("%f",_this->myBase);
	printf(") : ");
}

VirtualMethodPointer Triangle_VTable [] = 
{
	(VirtualMethodPointer)Triangle_name,
	(VirtualMethodPointer)Triangle_area,
	(VirtualMethodPointer)Triangle_draw,
	(VirtualMethodPointer)Triangle_nums
};

Triangle * Triangle_Triangle(Triangle * _this, char *newName, double newHeight, double newBase)
{
//	printf(newName);
//	Shape_Shape((Shape *)_this, newName);
	_this->parent = Shape_Shape((Shape *)_this, newName);
	_this->VPointer = Triangle_VTable;
//	printf("%f", newHeight);
	_this->myHeight = newHeight;
	_this->myBase = newBase;
	return _this;
}

typedef struct Square
{
	VTableType VPointer;
	char name[50];
	double mySide;
	Shape* parent;
}Square;

char *Square_name(Square * _this)
{
	return _this->parent->name;
}
double *Square_area(Square * _this)
{
	double n = _this->mySide * _this->mySide;
	double *m = malloc(sizeof(n));
	*m = n;
	return m;
}
void Square_draw(Square * _this)
{
	printf("* * * * * *\n*         *\n*         *\n*         *\n*         *\n* * * * * *");
}
void Square_nums(Square * _this)
{
	printf("(");
	printf("%f",_this->mySide);
	printf(") : ");
}
	

VirtualMethodPointer Square_VTable [] = 
{
	(VirtualMethodPointer)Square_name,
	(VirtualMethodPointer)Square_area,
	(VirtualMethodPointer)Square_draw,
	(VirtualMethodPointer)Square_nums
};

Square * Square_Square(Square * _this, char *newName, double newSide)
{
	_this->parent = Shape_Shape((Shape *)_this, newName);
	_this->VPointer = Square_VTable;
	_this->mySide = newSide;
	return _this;
}

typedef struct Circle
{
	VTableType VPointer;
	char name[50];
	double myRadius;
	Shape* parent;
}Circle;
	
char *Circle_name(Circle * _this)
{
	return _this->parent->name;
}
double* Circle_area(Circle * _this)
{
	double n = PI * _this->myRadius * _this->myRadius;
	double *m = malloc(sizeof(n));
	*m = n;
	return m;
}
void Circle_draw(Circle * _this)
{
	printf("  * * * *  \n*         *\n*         *\n*         *\n*         *\n  * * * *  ");
}
void Circle_nums(Circle * _this)
{
	printf("(");
	printf("%f",_this->myRadius);
	printf(") : ");
}	

VirtualMethodPointer Circle_VTable [] = 
{
	(VirtualMethodPointer)Circle_name,
	(VirtualMethodPointer)Circle_area,
	(VirtualMethodPointer)Circle_draw,
	(VirtualMethodPointer)Circle_nums
};

Circle * Circle_Circle(Circle * _this, char *newName, double newRadius)
{
	_this->parent = Shape_Shape((Shape *)_this, newName);
	_this->VPointer = Circle_VTable;
	_this->myRadius = newRadius;
	return _this;
}

typedef struct Rectangle
{
	VTableType VPointer;
	char name[50];
	double myWidth;
	double myHeight;
	Shape* parent;	
}Rectangle;
	
char *Rectangle_name(Rectangle * _this)
{
	return _this->parent->name;
}
double* Rectangle_area(Rectangle * _this)
{
	double n = _this->myHeight * _this->myWidth;
	double *m = malloc(sizeof(n));
	*m = n;
	return m;
}
void Rectangle_draw(Rectangle * _this)
{
	printf("* * * * * *\n*         *\n*         *\n*         *\n*         *\n*         *\n*         *\n* * * * * *");
}

void Rectangle_nums(Rectangle * _this)
{
	printf("(");
	printf("%f",_this->myWidth);
	printf(", ");
	printf("%f",_this->myHeight);
	printf(") : ");
}

VirtualMethodPointer Rectangle_VTable [] = 
{
	(VirtualMethodPointer)Rectangle_name,
	(VirtualMethodPointer)Rectangle_area,
	(VirtualMethodPointer)Rectangle_draw,
	(VirtualMethodPointer)Rectangle_nums
};

Rectangle * Rectangle_Rectangle(Rectangle * _this, char *newName, double newSide, double newWidth)
{
	_this->parent = Shape_Shape((Shape *)_this, newName);
	_this->VPointer = Rectangle_VTable;
	_this->myHeight = newSide;
	_this->myWidth = newWidth;
	return _this;
}

int main(int argc, char* argv[])
{



//	Shape * s = (Shape *)Triangle_Triangle((Triangle *)malloc(sizeof(Triangle)),"FirstTriangle", 5.0, 5.0);
//	printf((char*)s->VPointer[0](s));
//	printf("%f",*s->VPointer[1](s));
	//s->VPointer[2](s);
	
	int x_int = atoi(argv[1]);
	double x = (double)x_int;
	int y_int = atoi(argv[2]);
	double y = (double)y_int;

	double total = 0.0;

	int spacer = 0;

	Shape * a [] = 
	{

		(Shape *)Triangle_Triangle((Triangle *)malloc(sizeof(Triangle)),"FirstTriangle", x, y),
		(Shape *)Triangle_Triangle((Triangle *)malloc(sizeof(Triangle)),"SecondTriangle", x-1.0, y-1.0),
		
		(Shape *)Circle_Circle((Circle *)malloc(sizeof(Circle)),"FirstCircle", x),
		(Shape *)Circle_Circle((Circle *)malloc(sizeof(Circle)),"SecondCircle", x-1.0),
		
		(Shape *)Square_Square((Square *)malloc(sizeof(Square)),"FirstSquare", x),
		(Shape *)Square_Square((Square *)malloc(sizeof(Square)),"SecondSquare", x-1.0),

		(Shape *)Rectangle_Rectangle((Rectangle *)malloc(sizeof(Rectangle)),"FirstRectangle", x, y),
		(Shape *)Rectangle_Rectangle((Rectangle *)malloc(sizeof(Rectangle)),"SecondRectangle", x-1.0, y-1.0)

	};
//	printf((char*)a[0]->VPointer[0](a[0]));
	for (int i=0; i<sizeof(a)/sizeof(*a); i++)
	{
		total = total +  *a[i]->VPointer[1](a[i]);
		printf("%s", (char*)a[i]->VPointer[0](a[i]));
		a[i]->VPointer[3](a[i]);
		printf("%f", *a[i]->VPointer[1](a[i]));
		printf("\n");
		spacer += 1;
		if(spacer == 2)
		{
			printf("\n");
			spacer = 0;
		}
		
	}
	printf("Total : ");
	printf("%f", total);
	printf("\n\n");

	for (int i=0; i<sizeof(a)/sizeof(*a); i++)
	{
		a[i]->VPointer[2](a[i]);
		printf("\n\n");
	}

}

