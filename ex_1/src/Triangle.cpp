#include "Triangle.h"
#include "Vertex.h"
#include "Board.h"
#include "cmath"

// constructors
Triangle::Triangle(const Vertex vertices[3])
	: m_vertices{ vertices[0], vertices[1] , vertices[2] }
{
	if (!isValid()) {
		m_vertices[0] = Vertex(20, 20);
		m_vertices[1] = Vertex(25, 20 + sqrt(75));
		m_vertices[2] = Vertex(30, 20);
	}
}

// Triangle::Triangle(const Vertex& left, const Vertex& right, double height) {}

// all classes functions
void Triangle::draw(Board& board) const
{
	board.drawLine(m_vertices[0], m_vertices[1]);
	board.drawLine(m_vertices[1], m_vertices[2]);
	board.drawLine(m_vertices[0], m_vertices[2]);
}

Rectangle Triangle::getBoundingRectangle() const
{
	if (isStanding())
		return Rectangle(m_vertices[0], Vertex(m_vertices[2].m_col, m_vertices[1].m_row));
	else 
		return Rectangle(Vertex(m_vertices[0].m_col, m_vertices[1].m_row),m_vertices[2]);
}

double Triangle::getArea() const
{
	return getLength() * getHeight() * 0.5;
}

double Triangle::getPerimeter() const
{
	return getLength() * 3;
}

Vertex Triangle::getCenter() const
{
	double center_x = (m_vertices[2].m_col + m_vertices[0].m_col) / 2;
	double center_y = (m_vertices[1].m_row + m_vertices[0].m_row) / 2;

	return Vertex(center_x, center_y);
}

// bool Triangle::scale(double factor) {}

// accessor functions
Vertex Triangle::getVertex(int index) const
{
	return m_vertices[index];
}

double Triangle::getLength() const
{
	return edgeLength(m_vertices[0],m_vertices[2]);
}

double Triangle::getHeight() const
{
	return abs(m_vertices[1].m_row - m_vertices[0].m_row);
}

// utility functions
bool Triangle::isValid() const
{
	if (m_vertices[0].isValid() && m_vertices[2].isValid() &&
		m_vertices[1].isValid() && m_vertices[0].isSameHeightAs(m_vertices[2]) &&
		m_vertices[2].isToTheRightOf(m_vertices[1]) &&
		m_vertices[1].isToTheRightOf(m_vertices[0]) &&
		(edgeLength(m_vertices[0], m_vertices[2]) ==
			edgeLength(m_vertices[0], m_vertices[1]) ==
			edgeLength(m_vertices[1], m_vertices[2])))
		return true;
	else
		return false;
}

double Triangle::edgeLength(const Vertex& v1, const Vertex& v2) const
{
	return sqrt(pow(v2.m_col - v1.m_col,2) + pow(v2.m_row - v1.m_row,2));
}

bool Triangle::isStanding() const
{
	if (m_vertices[1].m_row > m_vertices[0].m_row)
		return true;
	else
		return false;
}