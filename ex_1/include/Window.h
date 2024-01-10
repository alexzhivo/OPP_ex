// prevent multiple inclusions of header file
#pragma once

// Declaration of class Window.
#include <Rectangle.h>
#include <Vertex.h>
#include <Utilities.h>

// Window definition
class Window {

public:
	// constructors
	Window(const Rectangle& outer, const Rectangle& inner);                        
	Window(const Rectangle& outer, double verticalThickness, double horizonalThickness);

	// functions
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getVerticalThickness() const;
	double getHorizontalThickness() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	// members
	Rectangle m_inner;
	Rectangle m_outer;

	// helper functions
	bool isValidWindow(const Rectangle outer, const Rectangle inner) const;
	bool isValidThickness(Rectangle outer) const;
}; // end class Window
