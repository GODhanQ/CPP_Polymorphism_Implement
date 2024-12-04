#pragma once
#include "Vertex.h"
#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(const Vertex&, const Vertex&);
	Rectangle(const Rectangle&);
	~Rectangle();

	virtual void draw() const override;
	virtual Rectangle* clone() const override;
private:
	Vertex p1, p2;
};