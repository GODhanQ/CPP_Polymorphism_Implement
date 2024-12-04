#pragma once
#include "Vertex.h"
#include "Shape.h"

class Circle : public Shape {
public:
	Circle();
	Circle(const Vertex&, double);
	Circle(const Circle&);
	~Circle();

	virtual void draw() const override;
	virtual Circle* clone() const override;

private:
	Vertex center{};
	double rad{};
};