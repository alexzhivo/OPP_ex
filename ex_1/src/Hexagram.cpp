#include "Hexagram.h"
#include "Vertex.h"
#include "Utilities.h"

// constructors

Hexagram::Hexagram(Vertex firstTriangle[3], Vertex secondTriangle[3])
	: m_firstTriangle{firstTriangle[0],firstTriangle[1],firstTriangle[2]},
	  m_secondTriangle{secondTriangle[0],secondTriangle[1],secondTriangle[2]}
{

}

// all classes functions

// accessor functions
double Hexagram::getTotalHeight() const
{
	return distance(m_firstTriangle[1], m_secondTriangle[1]);
}

double Hexagram::getLength() const
{
	return distance(m_firstTriangle[0], m_firstTriangle[2]);
}

