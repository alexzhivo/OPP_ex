#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Triangle {
public:
	// constructors
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& left, const Vertex& right, double height);

	// functions
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
	// members
	Vertex m_vertices[3];

	// helper functions
	void setDefaultValues();
	bool isValid(const Vertex vertices[3]) const;
	bool isStanding() const;
};