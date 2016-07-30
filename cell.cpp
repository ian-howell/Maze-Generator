#include "cell.h"
#define NULL 0

Cell::Cell(int row, int col, Cell* parent)
{
    this->row = row;
    this->col = col;
    this->parent = parent;
}

Cell* Cell::get_opposite()
{
    if (parent->row - row == 0)
    {
        if (parent->col - col == -1)
            return new Cell(row, col + 1, NULL);
        else
            return new Cell(row, col - 1, NULL);
    }
    else
    {
        if (parent->row - row == -1)
            return new Cell(row + 1, col, NULL);
        else
            return new Cell(row - 1, col, NULL);
    }
}

bool is_valid(int r, int c, int max_row, int max_col)
{
    return r >= 0 && r < max_row && c >= 0 && c < max_col;
}

