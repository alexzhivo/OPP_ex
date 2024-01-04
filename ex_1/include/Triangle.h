// Declaration of class Triangle.

#include <Vertex.h>
#include <Utilities.h>

// prevent multiple inclusions of header file
#pragma once

// Triangle definition
class Triangle {

public:
	// constructors
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& left, const Vertex& right, double height);

	// functions
	Vertex getVertex(int index) const;
	double getLength() const;
	double getHeight() const;

private:
	Vertex m_vertices[3];
	
	bool isValidTriangle(const Vertex vertices[3]) const;
	double calcDistance(const Vertex& v1, const Vertex& v2);

}; // end class Triangle
