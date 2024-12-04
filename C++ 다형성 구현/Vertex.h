#pragma once
#ifndef _Vertex
#define _Vertex

struct Vertex
{
	double x{}, y{};

	Vertex();
	Vertex(double, double);
	Vertex(const Vertex&) = default;
};
#endif // !_Vertex
