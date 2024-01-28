#include "Row.h"

explicit Row::Row(int size, const Tile& value)
	: m_size(size), m_data(value)
{}

Row::Row(const Row& other)
	: m_size(other.m_size)
{
	m_data = new Tile[m_size];

	for (int i = 0; i < m_size; i++) {
		m_data[i] = other.m_data[i];
	}
}

Row& Row::operator=(const Row& other)
{
	if (this != &other) {
		delete[] m_data;
		
		m_size = other.m_size;

		m_data = new Tile[m_size];
		for (int i = 0; i < m_size; i++) {
			m_data[i] = other.m_data[i];
		}
	}
	return *this;
}

Row::~Row()
{
	delete[] m_data;
}

// for reading
const Tile& Row::at(int index) const
{
	return m_data[index];
}
// for writing
Tile& Row::at(int index)
{
	return m_data[index];
}

void Row::push_back(const Tile& val)
{
	Tile* new_data = new Tile[size + 1];

	for (int i = 0; i < m_size; i++) {
		new_data[i] = m_data[i];
	}

	new_data[m_size] = val;

	delete[] m_data;

	m_data = new_data;
	m_size++;
}


int Row::size() const
{
	return m_size;
}
bool Row::empty() const
{
	if (m_size == 0) {
		return true
	}
	return false;
}