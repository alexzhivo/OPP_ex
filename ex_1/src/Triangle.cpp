#include "Triangle.h"

// ------------------- constructors ------------------------
Triangle::Triangle(const Vertex vertices[3])
	: m_vertices{ vertices[0], vertices[1] , vertices[2] }
{
	setDefaultValues();
}

Triangle::Triangle(const Vertex& left, const Vertex& right, double height)
	: m_vertices{left, Vertex((left.m_col + right.m_col) / 2, left.m_row + height), right}
{
	setDefaultValues();
}

// ---------------- all classes functions -------------------
 
// Draw the triangle on the board by drawing its three sides.
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

// Scale the triangle by a given factor.
bool Triangle::scale(double factor)
{
	if (factor < 0)
		return false;

	Vertex centerV = getCenter();
	Vertex newVertices[3];

	// Calculate new vertices after scaling.
	for (int i = 0; i < 3; i++) {
		double disX = m_vertices[i].m_col - centerV.m_col;
		double disY = m_vertices[i].m_row - centerV.m_row;
		newVertices[i].m_col = centerV.m_col + (disX * factor);
		newVertices[i].m_row = centerV.m_row + (disY * factor);

		if (!newVertices[i].isValid()) {
			return false;
		}
	}

	// Update the triangle with the new vertices.
	for (int i = 0; i < 3; i++) {
		m_vertices[i] = newVertices[i];
	}

	return true;
}

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

// ----------------- accessor functions ---------------------
// 
// Check if the given vertices form a valid triangle.
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

// Set default values for the triangle if the provided vertices are not valid.
void Triangle::setDefaultValues()
{
	if (!isValid(m_vertices)) {
		m_vertices[0] = Vertex(20, 20);
		m_vertices[1] = Vertex(25, 20 + sqrt(75));
		m_vertices[2] = Vertex(30, 20);
	}
}

// Check if the triangle is standing (pointing upwards) or not.
bool Triangle::isStanding() const
{
	if (m_vertices[1].isHigherThan(m_vertices[0]))
		return true;
	else
		return false;
}        