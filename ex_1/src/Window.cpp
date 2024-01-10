#include <Window.h>

Window::Window(const Rectangle& outer, const Rectangle& inner) 
	:m_outer(outer), m_inner(inner)
{
	if (!isValidWindow(outer, inner))
	{
		m_inner = Rectangle(Vertex(20, 10), Vertex(30, 20));
		m_outer = Rectangle(Vertex(20, 10), Vertex(30, 20));
	}
}

Window::Window(const Rectangle& outer, double verticalThickness, double horizontalThickness)
	:Window(outer, Rectangle(Vertex(m_outer.getBottomLeft().m_col + horizontalThickness,
									m_outer.getBottomLeft().m_row + verticalThickness),
							 Vertex(m_outer.getTopRight().m_col - horizontalThickness,
									m_outer.getTopRight().m_row - verticalThickness)))
{
	if (!isValidThickness(outer))
	{
		m_inner = Rectangle(Vertex(20, 10), Vertex(30, 20));
		m_outer = Rectangle(Vertex(20, 10), Vertex(30, 20));
	}
}

bool Window::isValidWindow(const Rectangle outer, const Rectangle inner) const
{
	Vertex innerCenter, outerCenter;

	innerCenter = inner.getCenter();
	outerCenter = outer.getCenter();

	return(doubleEqual(innerCenter.m_col, outerCenter.m_col) &&
		doubleEqual(innerCenter.m_row, outerCenter.m_row));
}

bool Window::isValidThickness(Rectangle outer) const 
{
	return((getVerticalThickness() < (outer.getHeight() / 2) ||
			doubleEqual(getVerticalThickness(), (outer.getHeight() / 2))) &&
			(getHorizontalThickness() < (outer.getWidth() / 2) ||
			 doubleEqual(getHorizontalThickness(), (outer.getWidth() / 2))));

}

Vertex Window::getBottomLeft() const
{
	return m_outer.getBottomLeft();
}

Vertex Window::getTopRight() const
{
	return m_outer.getTopRight();
}

double Window::getVerticalThickness() const
{
	return(getTopRight().m_row - m_inner.getTopRight().m_row);
}

double Window::getHorizontalThickness() const
{
	return(getTopRight().m_col - m_inner.getTopRight().m_col);
}

void Window::draw(Board& board) const
{
	m_inner.draw(board);
	m_outer.draw(board);
}

Rectangle Window::getBoundingRectangle() const
{
	return m_outer;
}

double Window::getArea() const
{
	return m_outer.getArea() - m_inner.getArea();
}

double Window::getPerimeter() const
{
	return m_outer.getPerimeter() + m_outer.getPerimeter();
}

Vertex Window::getCenter() const
{
	return m_outer.getCenter();
}

bool Window::scale(double factor)
{
	// Save the original inner and outer rectangles in case scaling is not successful
	Rectangle originalInner(m_inner), originalOuter(m_outer);

	// Scale the inner and outer rectangles
	bool innerScaled = m_inner.scale(factor);
	bool outerScaled = m_outer.scale(factor);

	// If scaling was not successful, revert to the original rectangles and return false
	if (!innerScaled || !outerScaled || !isValidWindow(m_outer, m_inner))
	{
		m_inner = originalInner;
		m_outer = originalOuter;
		return false;
	}

	// If scaling was successful, return true
	return true;
}


