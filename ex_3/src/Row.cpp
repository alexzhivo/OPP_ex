#include "Row.h"

// constructor
Row::Row(int size, const Tile& value) : m_size(size) {
    m_data = new Tile[m_size];
	if (m_data == nullptr) {
		std::cerr << "failed to allocate new Tile\n"; 
		exit(EXIT_FAILURE);
	}
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = value;
    }
}

// copy constructor
Row::Row(const Row& other)
	: m_size(other.m_size)
{
	m_data = new Tile[m_size];

	for (int i = 0; i < m_size; i++) {
		m_data[i] = other.m_data[i];
	}
}

// assignment operator
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

// destructor
Row::~Row()
{
	delete[] m_data;
}

// return a tile by index (for reading)
const Tile& Row::at(int index) const
{
	return m_data[index];
}

// return a tile by index (for writing)
Tile& Row::at(int index)
{
	return m_data[index];
}

// inserts another tile cell to row
void Row::push_back(const Tile& val)
{
	Tile* new_data = new Tile[m_size + 1];

	for (int i = 0; i < m_size; i++) {
		new_data[i] = m_data[i];
	}

	new_data[m_size] = val;

	delete[] m_data;

	m_data = new_data;
	m_size++;
}

// returns size of row
int Row::size() const
{
	return m_size;
}

// checks if row is empty
bool Row::empty() const
{
	if (m_size == 0) {
		return true;
	}
	return false;
}