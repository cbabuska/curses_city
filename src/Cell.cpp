#include "Cell.h"

using std::vector;
using std::map;
using std::string;
using std::pair;

#include "Status_grid.h"

Cell::Cell(int y, int x, int state, std::string type, int price, int monthly_cost, char symbol, int color, bool bold, vector<pair<string, int> > attributes) : 
      y(y), x(x), state(state), type(type), price(price), monthly_cost(monthly_cost), symbol(symbol), color(color), bold(bold), attributes(attributes)
{
  Logger::get_instance().write("Cell constructed"); 
}

void Cell::calculate_land_values(map<string, Status_grid*>& status_grids)
{
  for (int i=0; i<NUMBER_OF_ZONE_TYPES; ++i)
  {
    land_values[ZONE_TYPES[i]] = 0;
  }

  for (int i=0; i<NUMBER_OF_ZONE_REQUIREMENTS; ++i)
  {
    if (status_grids[ZONE_REQUIREMENTS[i]]->get_grid()[y][x] == 0)
    {
      return;
    }
  }

  for (int i=0; i<NUMBER_OF_ZONE_TYPES; ++i)
  {
    land_values[ZONE_TYPES[i]] = 100;
    for (int j=0; j<NUMBER_OF_ATTRIBUTES; ++j)
    {
      land_values[ZONE_TYPES[i]] += (status_grids[ATTRIBUTES[j]]->get_grid()[y][x] * LAND_VALUE_PARAMS[i][j]);
    }
  }
}
