#include <iostream>
#include "Triangle.h"

Triangle::Triangle()
	: p1{}, p2{}, p3{}
{

}

Triangle::Triangle(const Vertex& a, const Vertex& b, const Vertex& c)
	: p1{ a }, p2{ b }, p3{ c }
{

}

Triangle::Triangle(const Triangle& other)
	: p1{ other.p1 }, p2{ other.p2 }, p3{ other.p3 }
{

}

Triangle::~Triangle()
{

}

void Triangle::draw() const
{
	std::cout << "Triangle - (" << p1.x << ", " << p1.y << "), ("
		<< p2.x << ", " << p2.y << "), ("
		<< p3.x << ", " << p3.y << ")" << '\n';
}

Triangle* Triangle::clone() const
{
	return new Triangle(*this);
}