#include "Hexagram.h"

// ------------------- constructors ------------------------

// Constructor for Hexagram with two sets of vertices for the triangles.
Hexagram::Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3])
	: m_firstTriangle(Triangle(firstTriangle)),m_secondTriangle(Triangle(secondTriangle))
{
	setDefaultValues(m_firstTriangle, m_secondTriangle);
}

// Constructor for Hexagram with two given triangles.
Hexagram::Hexagram(const Triangle& t1, const Triangle& t2)
	: m_firstTriangle(Triangle(t1)),m_secondTriangle(Triangle(t2))
{
	setDefaultValues(m_firstTriangle, m_secondTriangle);
}

// ------------------------ functions ------------------------

void Hexagram::draw(Board& board) const
{
	m_firstTriangle.draw(board);
	m_secondTriangle.draw(board);
}

// Get the bounding rectangle of the hexagram.
Rectangle Hexagram::getBoundingRectangle() const
{
	Vertex newTopRight, newBottomLeft;

	// Determine the bounding rectangle based on the standing orientation of the first triangle.
	if (isStanding(m_firstTriangle)) {
		newTopRight = {m_firstTriangle.getVertex(2).m_col, m_firstTriangle.getVertex(1).m_row};
		newBottomLeft = {m_secondTriangle.getVertex(0).m_col, m_secondTriangle.getVertex(1).m_row};
	}
	else {
		newTopRight = { m_secondTriangle.getVertex(2).m_col, m_secondTriangle.getVertex(1).m_row };
		newBottomLeft = { m_firstTriangle.getVertex(0).m_col, m_firstTriangle.getVertex(1).m_row };
	}

	return Rectangle(newBottomLeft, newTopRight);
}

Vertex Hexagram::getCenter() const
{
	return m_firstTriangle.getCenter();
}

double Hexagram::getArea() const
{
	return m_firstTriangle.getArea() * 4 / 3;
}

double Hexagram::getPerimeter() const
{
	return m_firstTriangle.getPerimeter() * 4 / 3;
}

bool Hexagram::scale(double factor)
{
	Triangle newFirstTriangle(m_firstTriangle);
	Triangle newSecondTriangle(m_secondTriangle);

	if (newFirstTriangle.scale(factor) && newSecondTriangle.scale(factor)) {
		m_firstTriangle = newFirstTriangle;
		m_secondTriangle = newSecondTriangle;
		return true;
	}

	return false;
}

double Hexagram::getTotalHeight() const
{
	return distance(m_firstTriangle.getVertex(1), m_secondTriangle.getVertex(1));
}

double Hexagram::getLength() const
{
	return distance(m_firstTriangle.getVertex(0), m_firstTriangle.getVertex(2));
}

// ------------------ accessor functions ---------------------

// Set default values for the hexagram if the given triangles do not meet requirements.
void Hexagram::setDefaultValues(const Triangle& t1, const Triangle& t2)
{
	if (doubleEqual(t1.getLength(), t2.getLength()) &&
		sameCol(t1.getCenter(), t2.getCenter()) &&
		sameRow(t1.getCenter(), t2.getCenter()) &&
		isTrianglesOpposites(t1,t2))
		return;

	// Set default vertices for the triangles.
	Vertex firstTriangle[3] = {Vertex(20,20),Vertex(25,20 + sqrt(75)),Vertex(30,20)};
	Vertex SecondTriangle[3] = {Vertex(20,20 + sqrt(75) * 2 / 3),
								Vertex(25,20 - sqrt(75) / 3),
								Vertex(30,20 + sqrt(75) * 2 / 3) };

	// Update the hexagram with the default triangles.
	m_firstTriangle = Triangle(firstTriangle);
	m_secondTriangle = Triangle(SecondTriangle);
}

// Check if the triangles are opposites in orientation (one standing and the other not).
bool Hexagram::isTrianglesOpposites(const Triangle& t1, const Triangle& t2) const
{
	if ((isStanding(t1) && isStanding(t2)) || (!isStanding(t1) && !isStanding(t2)))
		return false;
	else
		return true;
}

// Check if the given triangle is standing (pointing upwards).
bool Hexagram::isStanding(const Triangle& t1) const
{
	return (t1.getVertex(1).isHigherThan(t1.getVertex(0)));
}
