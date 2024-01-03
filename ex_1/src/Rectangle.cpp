#include "Rectangle.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight) 
		 : m_bottomLeft(bottomLeft), m_topRight(topRight)
{
}

Rectangle::Rectangle(const Vertex vertices[2])
		 : Rectangle(vertices[0], vertices[1])
{
}

bool Rectangle::isValidRectangle(Vertex bottomLeft, Vertex topRight) const
{
	return ((bottomLeft.isValid() && topRight.isValid()) &&
		(topRight.isToTheRightOf(bottomLeft) || sameRow(bottomLeft, topRight)) &&
		(topRight.isHigherThan(bottomLeft) || sameCol(bottomLeft, topRight)));
}