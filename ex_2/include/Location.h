#pragma once

struct Location
{
    int row;
    int col;

    Location(int col = 0, int row = 0) : col(col), row(row) {}
};
