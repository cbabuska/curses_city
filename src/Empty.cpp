#include "Empty.h"

using std::vector;
using std::map;

void Empty::update_state(const vector<vector<Cell*> >& grid, map<int, Status_grid*>& status_grids)
{
  return;
}

unsigned char Empty::draw(const vector<vector<Cell*> >& grid, int& color_pair)
{
  color_pair = color;
  return symbol;
}

