#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Triangle {
public:
	Triangle(const Vertex vertices[3]);
	// Triangle(const Vertex& left, const Vertex& right, double height);

	Vertex getVertex(int index) const;
	double getLength() const;
	double getHeight() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Vertex m_vertices[3];

	double edgeLength(const Vertex& v1, const Vertex& v2) const;
	bool isValid() const;
	bool isStanding() const;
};