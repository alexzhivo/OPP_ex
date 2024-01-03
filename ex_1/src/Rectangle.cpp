#include "Rectangle.h"

//Rectangle::Rectangle(const Vertex vertices[2])
//		 : Rectangle(vertices[0], vertices[1])
//{
//}
//
//bool Rectangle::isValidRectangle(Vertex bottomLeft, Vertex topRight) const
//{
//	return ((bottomLeft.isValid() && topRight.isValid()) &&
//		(topRight.isToTheRightOf(bottomLeft) || sameRow(bottomLeft, topRight)) &&
//		(topRight.isHigherThan(bottomLeft) || sameCol(bottomLeft, topRight)));
//}

// constructors

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (!bottomLeft.isValid() || !topRight.isValid()) {
		m_bottomLeft.m_col = 20;
		m_bottomLeft.m_row = 10;
		m_topRight.m_col = 30;
		m_topRight.m_row = 20;
	} else {
		m_bottomLeft = bottomLeft;
		m_topRight = topRight;
	}
}

// get functions
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
	double width = m_topRight.m_col - m_bottomLeft.m_col;
	return width;
}

double Rectangle::getHeight() const
{
	double height = m_topRight.m_row - m_bottomLeft.m_row;
	return height;
}

bool Rectangle::isValidRectangle(Vertex bottomLeft, Vertex topRight) const
{
	if (bottomLeft.)
}