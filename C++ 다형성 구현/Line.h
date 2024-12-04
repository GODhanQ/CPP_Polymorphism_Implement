#pragma once
#include "Vertex.h"
#include "Shape.h"

class Line : public Shape {
public:
	Line();
	Line(const Vertex&, const Vertex&);
	Line(const Line&);
	~Line();

	virtual void draw() const override;
	virtual Line* clone() const override;
private:
	Vertex p1, p2;
};