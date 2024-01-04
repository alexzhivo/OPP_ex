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

}