#pragma once
#include "Vertex.h"
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle();
	Triangle(const Vertex&, const Vertex&, const Vertex&);
	Triangle(const Triangle&);
	~Triangle();
	
	virtual void draw() const override;
	virtual Triangle* clone() const override;

private:
	Vertex p1{}, p2{}, p3{};
};