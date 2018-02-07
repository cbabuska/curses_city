#include "Municipal.h"

#include <curses.h>

using std::vector;
using std::map;

#include "Constants.h"

void Municipal::pay_for_services(Status& status)
{
  if (status.get_money() < monthly_cost)
  {
    state = INACTIVE;
  }
  else
  {
    status.sub_money(monthly_cost);
    state = ACTIVE;
  }

  return;
}

char Municipal::draw(Grid& grid, int& color_pair, bool& acs, bool& bold)
{
  color_pair = color;
  acs = false;
  bold = this->bold;

  if (type!=ROAD && type!=RAIL)
  {
    return symbol;
  }

  bool adjacencies[4];
  adjacencies[0] = (y>0 && (grid.get_cell(y-1, x)->get_type()==type));
  adjacencies[1] = (x<X_SIZE-1 && (grid.get_cell(y, x+1)->get_type()==type));
  adjacencies[2] = (y<Y_SIZE-1 && (grid.get_cell(y+1, x)->get_type()==type));
  adjacencies[3] = (x>0 && (grid.get_cell(y, x-1)->get_type()==type));

  if (type==ROAD)
  {
    acs = false;

    if ((adjacencies[0] || adjacencies[2]) && (adjacencies[1] || adjacencies[3]))
    {
      return '+';
    }
    else if ((adjacencies[0] || adjacencies[2]))
    {
      return '|';
    }
    else if ((adjacencies[1] || adjacencies[3]))
    {
      return '-';
    }
    else 
    {
      return '-';
    }
  }

  if (type==RAIL)
  {
    acs = true;

    if      ( adjacencies[0] &&  adjacencies[1] &&  adjacencies[2] &&  adjacencies[3])
    {
      return ACS_SSSS;
    }
    else if (!adjacencies[0] &&  adjacencies[1] &&  adjacencies[2] &&  adjacencies[3])
    {
      return ACS_BSSS;
    }
    else if ( adjacencies[0] && !adjacencies[1] &&  adjacencies[2] &&  adjacencies[3])
    {
      return ACS_SBSS;
    }
    else if ( adjacencies[0] &&  adjacencies[1] && !adjacencies[2] &&  adjacencies[3])
    {
      return ACS_SSBS;
    }
    else if ( adjacencies[0] &&  adjacencies[1] &&  adjacencies[2] && !adjacencies[3])
    {
      return ACS_SSSB;
    }

    else if ( adjacencies[0] &&  adjacencies[1] && !adjacencies[2] && !adjacencies[3])
    {
      return ACS_SSBB;
    }
    else if ( adjacencies[0] && !adjacencies[1] &&  adjacencies[2] && !adjacencies[3])
    {
      return ACS_SBSB;
    }
    else if ( adjacencies[0] && !adjacencies[1] && !adjacencies[2] &&  adjacencies[3])
    {
      return ACS_SBBS;
    }
    else if (!adjacencies[0] &&  adjacencies[1] &&  adjacencies[2] && !adjacencies[3])
    {
      return ACS_BSSB;
    }
    else if (!adjacencies[0] &&  adjacencies[1] && !adjacencies[2] &&  adjacencies[3])
    {
      return ACS_BSBS;
    }
    else if (!adjacencies[0] && !adjacencies[1] &&  adjacencies[2] &&  adjacencies[3])
    {
      return ACS_BBSS;
    }

    else if ( adjacencies[0] && !adjacencies[1] && !adjacencies[2] && !adjacencies[3])
    {
      return ACS_SBSB;
    }
    else if (!adjacencies[0] &&  adjacencies[1] && !adjacencies[2] && !adjacencies[3])
    {
      return ACS_BSBS;
    }
    else if (!adjacencies[0] && !adjacencies[1] &&  adjacencies[2] && !adjacencies[3])
    {
      return ACS_SBSB;
    }
    else if (!adjacencies[0] && !adjacencies[1] && !adjacencies[2] && !adjacencies[3])
    {
      return ACS_BSBS;
    }
    else
    {
      return ACS_BSBS;
    }
  }

  return symbol;
}
