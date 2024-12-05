#pragma once
#include "Shape.h"

class ShapeManager {
public:
	explicit ShapeManager(int n);
	~ShapeManager();
	ShapeManager(const ShapeManager& other) = default;
	
	int current_capacity() const;
	void insert(Shape*);
	void draw() const;
	void removeShapes(int);
	void removeSpecificShapes(const type_info& type);
	void ExpandCapacity(int);
private:
	int nShape;
	int capacity;
	Shape** shapes;
};