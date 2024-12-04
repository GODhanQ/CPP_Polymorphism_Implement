#include <iostream>
#include "Line.h"

Line::Line()
	: p1{}, p2{}
{

}

Line::Line(const Vertex& a, const Vertex& b)
	: p1{ a }, p2{ b }
{

}

Line::Line(const Line& other)
	:p1{ other.p1 }, p2{ other.p2 }
{

}

Line::~Line()
{

}

void Line::draw() const
{
	std::cout << "선 - (" << p1.x << ", " << p1.y << "), "
		<< "(" << p2.x << ", " << p2.y << ")" << '\n';
}

Line* Line::clone() const
{
	return new Line(*this);
}