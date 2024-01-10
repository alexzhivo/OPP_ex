#pragma once

#include "Vertex.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Board.h"

class Hexagram {
public:
	// constructors
	Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3]);
	Hexagram(const Triangle& t1, const Triangle& t2);

	// functions
	double getTotalHeight() const;
	double getLength() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	// members
	Triangle m_firstTriangle;
	Triangle m_secondTriangle;

	// helper functions
	void setDefaultValues(const Triangle& t1, const Triangle& t2);
	bool isTrianglesOpposites(const Triangle& t1, const Triangle& t2) const;
	bool isStanding(const Triangle& t1) const;
};