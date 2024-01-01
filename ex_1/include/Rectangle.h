// Declaration of class Rectangle.

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
	Vertex bottomLeft;
	Vertex TopRight;
	double Width;
	double Height;

}; // end class Rectangle
