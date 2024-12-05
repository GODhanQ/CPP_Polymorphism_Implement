#include <iostream>
#include <print>
#include "ShapeManager.h"
#include "Vertex.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Menu.h"
using namespace std;

void Menu()
{
	print("\n");
	print("		Menu			v command number \n");
	print("- Draw all of Shapes :			1 \n");
	print("- Put shapes what you want \n");
	print("		- Triangle :		2 \n");
	print("		- Rectangle :		3 \n");
	print("		- Circle :		4 \n");
	print("		- Line :		5 \n");
	print("- Delete what you want \n");
	print("		- Designation :		6 \n");
	print("		- Triangle :		7 \n");
	print("		- Rectangle :		8 \n");
	print("		- Circle :		9 \n");
	print("		- Line :		10 \n");
	print("- Exit Program :			0 \n");
	print("\n");
}
