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
	print("- 전체 도형 그리기 :			1 \n");
	print("- 원하는 도형 추가 \n");
	print("		- 삼각형 :		2 \n");
	print("		- 사각형 :		3 \n");
	print("		- 원 :			4 \n");
	print("		- 선 :			5 \n");
	print("- 원하는 도형 삭제 \n");
	print("		- 지정 :		6 \n");
	print("		- 삼각형 :		7 \n");
	print("		- 사각형 :		8 \n");
	print("		- 원 :			9 \n");
	print("		- 선 :			10 \n");
	print("- 프로그램 종료 :			0 \n");
	print("\n");
}
