#ifndef ZONE_H
#define ZONE_H

#include "Logger.h"
#include "Cell.h" 

class Status_grid;

class Zone : public Cell
{
  public:
    Zone(int y, int x, std::string type, int price, int monthly_cost, char symbol, char color, bool bold, std::vector<std::pair<std::string, int> > attributes) : 
      Cell(y, x, INACTIVE, type, price, 0, symbol, color, bold, attributes), low_density_symbol('x'), medium_density_symbol('X'), high_density_symbol('#') 
      {Logger::get_instance().write("Zone constructed");}
    virtual ~Zone() {Logger::get_instance().write("Zone destructed");}

    void collect_taxes(Status& status);
    void pay_for_services(Status& status) {}
    void update_state();

    char draw(Grid& grid, int& color_pair, bool& acs, bool& bold);

  protected:

  private:
    char low_density_symbol;
    char medium_density_symbol;
    char high_density_symbol;
};

#endif
