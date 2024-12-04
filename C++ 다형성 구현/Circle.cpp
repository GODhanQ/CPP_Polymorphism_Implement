#include <iostream>
#include "Circle.h"

Circle::Circle()
	: center{ }, rad{ 0.0 }
{

}

Circle::Circle(const Vertex& c, double r)
	: center{ c }, rad{ r }
{

}

Circle::Circle(const Circle& other)
	: center{ other.center }, rad{ other.rad }
{

}

Circle::~Circle()
{

}

void Circle::draw() const
{
	std::cout << "원 - 중심점(" << center.x << ", " << center.y
		<< ") 반지름 " << rad << '\n';
}

Circle* Circle::clone() const
{
	return new Circle(*this);
}