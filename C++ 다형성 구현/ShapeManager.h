#pragma once
#include "Shape.h"

class ShapeManager {
public:
	explicit ShapeManager(int n);
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;
	ShapeManager(const ShapeManager& other);
	ShapeManager& operator=(const ShapeManager& other);

	int current_capacity() const;
	void insert(Shape*);
	void draw() const;
	void removeShapes(int);
	void removeSpecificShapes(const type_info& type);

private:
	int nShape;
	int capacity;
	Shape** shapes;
};