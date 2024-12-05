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
	std::cout << "Circle - center (" << center.x << ", " << center.y
		<< ") radius " << rad << '\n';
}

Circle* Circle::clone() const
{
	return new Circle(*this);
}