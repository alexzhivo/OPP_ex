// Declaration of class Rectangle.

#include <Vertex.h>
#include <Utilities.h>

// prevent multiple inclusions of header file
#pragma once

// Rectangle definition
class Rectangle {

public:
	// constructors
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	
	// functions
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;

private:
	Vertex m_bottomLeft;
	Vertex m_topRight;

	bool isValidRectangle(Vertex bottomLeft, Vertex topRight) const;

}; // end class Rectangle
