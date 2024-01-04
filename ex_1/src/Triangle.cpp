#include "Triangle.h"
#include <cmath>

// constructors
Triangle::Triangle(const Vertex vertices[3])
{
	if (isValidTriangle(vertices)) {
		for (int index = 0 ; index < 3 ; index++)
			m_vertices[index] = vertices[index];
	}
	else {
		m_vertices[0].m_col = 20;
		m_vertices[0].m_row = 20;
		m_vertices[1].m_col = 25;
		m_vertices[1].m_row = 20 + sqrt(75);
		m_vertices[2].m_col = 30;
		m_vertices[2].m_row = 20;
	}
}

Triangle::Triangle(const Vertex& left, const Vertex& right, double height)
{
	Vertex vertices[3];
	vertices[0] = left;
	vertices[2] = right;
	vertices[1].m_col = (right.m_col + left.m_col) / 2;
	vertices[1].m_row = vertices[0].m_row + height;

	Triangle(vertices);
} 
// end of constructors



// public functions
Vertex Triangle::getVertex(int index) const
{
	return m_vertices[index];
}

double Triangle::getLength() const
{
	return m_vertices[2].m_col - m_vertices[0].m_col;
}

double Triangle::getHeight() const
{
	double height = m_vertices[1].m_row - m_vertices[0].m_row;
	return abs(height);
} 
// end of public functions

// private functions
bool Triangle::isValidTriangle(const Vertex vertices[3]) const
{
	for (int index = 0; index < 3; index++) {
		if (!vertices[index].isValid)
			return false;
	}

	if (!vertices[0].isSameHeightAs(vertices[2]))
		return false;

	if (!(calcDistance(vertices[0], vertices[1]) ==
		calcDistance(vertices[1], vertices[2]) ==
		calcDistance(vertices[0], vertices[3])))
		return false;

	return true;
}

double Triangle::calcDistance(const Vertex& v1, const Vertex& v2)
{
	return sqrt(pow(v2.m_col - v1.m_col,2) + pow(v2.m_row - v2.m_row,2));
}