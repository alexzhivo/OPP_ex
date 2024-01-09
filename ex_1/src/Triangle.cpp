#include "Triangle.h"
#include "Vertex.h"
#include "Utilities.h"
#include "Board.h"
#include "cmath"

// constructors
Triangle::Triangle(const Vertex vertices[3])
	: m_vertices{ vertices[0], vertices[1] , vertices[2] }
{
	setDefaultValues(vertices);
}

Triangle::Triangle(const Vertex& left, const Vertex& right, double height)
	: m_vertices{left, Vertex((left.m_col + right.m_col) / 2, left.m_row + height), right}
{
	setDefaultValues(m_vertices);
}

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
	double center_x = (m_vertices[0].m_col + m_vertices[1].m_col + m_vertices[2].m_col) / 3;
	double center_y = (m_vertices[0].m_row + m_vertices[1].m_row + m_vertices[2].m_row) / 3;

	return Vertex(center_x, center_y);
}

bool Triangle::scale(double factor) 
{

	if (factor < 0)
	{
		return false;
	}
	Vertex vertex0, vertex1, vertex2, center;

	center = getCenter();

	vertex0.m_col = center.m_col - ((center.m_col - m_vertices[0].m_col) * factor);
	vertex0.m_row = center.m_row - ((center.m_row - m_vertices[0].m_row) * factor);
	
	vertex1.m_col = m_vertices[0].m_col;
	vertex1.m_row = center.m_row + ((m_vertices[1].m_row - center.m_row) * factor);
	
}

// accessor functions
Vertex Triangle::getVertex(int index) const
{
	return m_vertices[index];
}

double Triangle::getLength() const
{
	return distance(m_vertices[0],m_vertices[2]);
}

double Triangle::getHeight() const
{
	return abs(m_vertices[1].m_row - m_vertices[0].m_row);
}

// utility functions
bool Triangle::isValid(const Vertex vertices[3]) const
{
	if (vertices[0].isValid() && vertices[2].isValid() &&
		vertices[1].isValid() && sameRow(vertices[0], vertices[2]) &&
		vertices[2].isToTheRightOf(vertices[1]) &&
		vertices[1].isToTheRightOf(vertices[0]) &&
		doubleEqual(distance(vertices[0], vertices[2]), distance(vertices[1], vertices[2])) &&
		doubleEqual(distance(vertices[0], vertices[2]), distance(vertices[0], vertices[1])))
		return true;
	else
		return false;
}

void Triangle::setDefaultValues(const Vertex vertices[3])
{
	if (!isValid(m_vertices)) {
		m_vertices[0] = Vertex(20, 20);
		m_vertices[1] = Vertex(25, 20 + sqrt(75));
		m_vertices[2] = Vertex(30, 20);
	}
}

bool Triangle::isStanding() const
{
	if (m_vertices[1].isHigherThan(m_vertices[0]))
		return true;
	else
		return false;
}        