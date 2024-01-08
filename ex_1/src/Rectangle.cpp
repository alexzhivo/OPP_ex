#include "Rectangle.h"

// Constructors
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	: m_bottomLeft(bottomLeft), m_topRight(topRight) 
{
	if (!m_bottomLeft.isValid() || !m_topRight.isValid() ||
		!m_topRight.isHigherThan(m_bottomLeft) ||
		!m_topRight.isToTheRightOf(m_bottomLeft)) 
	{
		m_bottomLeft = { 20 , 10 };
		m_topRight = { 30 , 20 };
	}
}

Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1]) {}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	: Rectangle(Vertex(x0, y0), Vertex(x1, y1)) {}

Rectangle::Rectangle(const Vertex& start, double width, double height)
	: Rectangle(start,Vertex(start.m_col + width, start.m_row + height)) {}

// all classes functions
void Rectangle::draw(Board& board) const
{
	double width = getWidth();
	
	Vertex bottomRight(m_bottomLeft.m_col + width, m_bottomLeft.m_row);
	Vertex topLeft(m_topRight.m_col - width, m_topRight.m_row);

	board.drawLine(m_bottomLeft, bottomRight);
	board.drawLine(m_bottomLeft, topLeft);
	board.drawLine(m_topRight, topLeft);
	board.drawLine(m_topRight, bottomRight);
}

Rectangle Rectangle::getBoundingRectangle() const
{
	return Rectangle(m_bottomLeft, m_topRight);
}

double Rectangle::getArea() const
{
	return (getWidth() * getHeight());
}

double Rectangle::getPerimeter() const
{
	return (getWidth() + getHeight()) * 2;
}

Vertex Rectangle::getCenter() const
{
	double center_x = (m_bottomLeft.m_col + m_topRight.m_col) / 2;
	double center_y = (m_bottomLeft.m_row + m_topRight.m_row) / 2;
	return Vertex(center_x, center_y);
}

bool Rectangle::scale(double factor)
{
	if (factor <= 0) {
		return false;
	}

	double newWidth = (getWidth() / 2) * factor;
	double newHeight = (getHeight() / 2) * factor;
	Vertex centerV = getCenter();
	
	Vertex newBottomLeft(centerV.m_col - newWidth, centerV.m_row - newHeight);
	Vertex newTopRight(centerV.m_col + newWidth, centerV.m_row + newHeight);

	if (!newBottomLeft.isValid() || !newTopRight.isValid())
		return false;

	m_bottomLeft = newBottomLeft;
	m_topRight = newTopRight;

	return true;
}

// accessor functions
Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}

Vertex Rectangle::getTopRight() const
{
	return m_topRight;
}

double Rectangle::getWidth() const
{
	return m_topRight.m_col - m_bottomLeft.m_col;
}

double Rectangle::getHeight() const
{
	return m_topRight.m_row - m_bottomLeft.m_row;
}