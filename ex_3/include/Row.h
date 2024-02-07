#pragma once
#include "Tile.h"

class Row {
public:
	explicit Row(int size = 0, const Tile& value = Tile());
	Row(const Row& other);
	Row& operator=(const Row& other);
	~Row();

	const Tile& at(int index) const;	// reading option
	Tile& at(int index);				// writing option
	void push_back(const Tile& val);
	bool empty() const;
	int size() const;
private:
	Tile* m_data;			// array of tiles
	int m_size;
};