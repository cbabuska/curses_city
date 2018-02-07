#ifndef MUNICIPAL_H
#define MUNICIPAL_H

#include "Logger.h"
#include "Status.h"
#include "Cell.h"

class Status_grid;

class Municipal : public Cell
{
  public:
    Municipal(int y, int x, std::string type, int price, int monthly_cost, char symbol, char color, bool bold, std::vector<std::pair<std::string, int> > attributes = std::vector<std::pair<std::string, int> >()) : 
      Cell(y, x, LOW_DENSITY, type, price, monthly_cost, symbol, color, bold, attributes) 
      {Logger::get_instance().write("Municipal constructed");}
    virtual ~Municipal() {Logger::get_instance().write("Municipal destructed");}

    void collect_taxes(Status& status) {}
    void pay_for_services(Status& status);
    void update_state() {}

    char draw(Grid& grid, int& color_pair, bool& acs, bool& bold);

  protected:

  private:
};

#endif
