#include "Rectangle.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight) 
	: m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	if (!isValidRectangle(bottomLeft, topRight))
	{
		m_bottomLeft= Vertex(20,10);
		m_topRight = Vertex(30,20);
	}
}

Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1])
{
}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	: Rectangle(Vertex(x0, y0), Vertex(x1, y1))
{
}

Rectangle::Rectangle(const Vertex& start, double width, double height)
	: Rectangle(start, Vertex(start.m_col + width, start.m_row + height))
{
	if (width < 0 || height < 0)
	{
		// If either width or height is negative, set default values
		m_bottomLeft = Vertex(20,10);
		m_topRight = Vertex(30,20);
	}
}

bool Rectangle::isValidRectangle(Vertex bottomLeft, Vertex topRight) const
{
	return ((bottomLeft.isValid() && topRight.isValid()) &&
		(topRight.isToTheRightOf(bottomLeft) || sameRow(bottomLeft, topRight)) &&
		(topRight.isHigherThan(bottomLeft) || sameCol(bottomLeft, topRight)));
}

Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}

Vertex Rectangle::getBottomRight() const
{
	return (Vertex(m_topRight.m_col, m_bottomLeft.m_row));
}

Vertex Rectangle::getTopLeft() const
{
	return (Vertex(m_bottomLeft.m_col, m_topRight.m_row));
}

Vertex Rectangle::getTopRight() const
{
	return m_topRight;
}

double Rectangle::getWidth() const
{
	return(m_topRight.m_col - m_bottomLeft.m_col);
}

double Rectangle::getHeight() const
{
	return(m_topRight.m_row - m_bottomLeft.m_row);
}

void Rectangle::draw(Board& board) const
{
	board.drawLine(m_bottomLeft, getBottomRight());
	board.drawLine(m_bottomLeft, getTopLeft());
	board.drawLine(m_topRight, getBottomRight());
	board.drawLine(m_topRight, getTopLeft());
}

Rectangle Rectangle::getBoundingRectangle() const
{
	return (Rectangle(m_bottomLeft, m_topRight));
}

double Rectangle::getArea() const
{
	return(getWidth() * getHeight());
}

double Rectangle::getPerimeter() const
{
	return((getWidth() + getHeight()) * 2);
}

Vertex Rectangle::getCenter() const
{
	double middleHeight = getHeight() / 2;
	double middleWidth = getWidth() / 2;

	return(Vertex(m_bottomLeft.m_col + middleWidth, m_bottomLeft.m_row + middleHeight));
}

bool Rectangle::scale(double factor)
{
	if (factor < 0)
	{
		return false;
	}

	Vertex bottomLeft, topRight, center;

	center = getCenter();

	bottomLeft.m_col = center.m_col - ((center.m_col - m_bottomLeft.m_col) * factor);
	bottomLeft.m_row = center.m_row - ((center.m_row - m_bottomLeft.m_row) * factor);
	topRight.m_col = center.m_col - ((center.m_col - m_topRight.m_col) * factor);
	topRight.m_row = center.m_row - ((center.m_row - m_topRight.m_row) * factor);

	if (!isValidRectangle(bottomLeft,topRight))
	{
		return false;
	}
	m_bottomLeft = bottomLeft;
	m_topRight = topRight;
	return true;
}



