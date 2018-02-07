#include "Zone.h"

#include <cstdlib>

#include "Constants.h"
#include "Status_grid.h"

using std::vector;
using std::map;

void Zone::update_state()
{

  if (land_values[type]>100 && rand()%1000<land_values[type])
  {
    state = LOW_DENSITY;

    if (land_values[type]>1000 && rand()%10000<land_values[type])
    {
      state = MEDIUM_DENSITY;

      if (land_values[type]>10000 && rand()%100000<land_values[type])
      {
        state = HIGH_DENSITY;
      } 
    }
  }
  else
  {
    state = INACTIVE;
  }
}

void Zone::collect_taxes(Status& status)
{
  if (state != INACTIVE)
  {
    status.add_money(land_values[type] * 0.05);
  }
}

char Zone::draw(Grid& grid, int& color_pair, bool& acs, bool& bold)
{
  color_pair = color;
  acs = false;
  bold = this->bold;

  switch(state)
  {
    case LOW_DENSITY:
      return low_density_symbol;

    case MEDIUM_DENSITY:
      return medium_density_symbol;

    case HIGH_DENSITY:
      return high_density_symbol;

    default:
      return symbol;
  }
}
