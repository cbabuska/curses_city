#include "Grid.h"

using std::vector;
using std::map;
using std::string;

#include "Constants.h"
#include "Cell.h"
#include "Cell_factory.h"

Grid::Grid()
{
  grid.resize(Y_SIZE);
  for (unsigned int y=0; y<grid.size(); ++y)
  {
    grid[y].resize(X_SIZE);
    for (unsigned int x=0; x<grid[y].size(); ++x)
    {
      grid[y][x] = Cell_factory::create_cell('x', y, x);
    }
  }
}

Grid::~Grid()
{
  for (unsigned int y=0; y<grid.size(); ++y)
  {
    for (unsigned int x=0; x<grid[y].size(); ++x)
    {
      delete(grid[y][x]);
    }
  }
}

std::string Grid::build(int y, int x, Cell* new_cell, Status& status)
{
  if (grid[y][x]->get_type() != LAND)
  {
    delete new_cell;
    return " Land must be clear ";
  }

  if (new_cell->get_price() > status.get_money())
  {
    delete new_cell;
    return " Not enough money ";
  }

  else
  {
    status.sub_money(new_cell->get_price());

    Cell* temp = grid[y][x];
    grid[y][x] = new_cell;
    delete temp;
             
    return "";
  }

}

std::string Grid::replace(int y, int x, Cell* new_cell)
{
  Cell* temp = grid[y][x];
  grid[y][x] = new_cell;
  delete temp;

  return "";
}

void Grid::collect_taxes(Status& status)
{
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      grid[y][x]->collect_taxes(status);
    }
  }
}

void Grid::pay_for_services(Status& status)
{
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      grid[y][x]->pay_for_services(status);
    }
  }
}

void Grid::calculate_land_values(map<string, Status_grid*>& status_grids)
{
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      grid[y][x]->calculate_land_values(status_grids);
    }
  }
}

void Grid::update_state()
{
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      grid[y][x]->update_state();
    }
  }
}
