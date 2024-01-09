#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Triangle.h"

class Hexagram {
public:
	Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3]);
	// Hexagram(const Triangle& t1, const Triangle& t2);

	double getTotalHeight() const;
	double getLength() const;

	// void draw(Board& board) const;
	// Rectangle getBoundingRectangle() const;
	// double getArea() const;
	// double getPerimeter() const;
	// Vertex getCenter() const;
	// bool scale(double factor);

private:
	Vertex m_firstTriangle[3];
	Vertex m_secondTriangle[3];
};