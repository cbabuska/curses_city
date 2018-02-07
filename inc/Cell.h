#ifndef CELL_H
#define CELL_H

#include <vector>      
#include <map>
#include <string>
#include <utility>

#include "Constants.h"
#include "Logger.h"
#include "Status.h"
#include "Grid.h"

enum Cell_state
{
  INACTIVE,
  ACTIVE,
  LOW_DENSITY,
  MEDIUM_DENSITY,
  HIGH_DENSITY
};

class Status_grid;

class Cell
{
  public:
    Cell(int y, int x, int state, std::string type, int price, int monthly_cost, char symbol, int color, bool bold, std::vector<std::pair<std::string, int> > attributes); 
    virtual ~Cell() {Logger::get_instance().write("Cell destructed");}

    virtual void collect_taxes(Status& status) = 0;
    virtual void pay_for_services(Status& status) = 0;
    void calculate_land_values(std::map<std::string, Status_grid*>& status_grids);
    virtual void update_state() = 0;

    virtual char draw(Grid& grid, int& color_pair, bool& acs, bool& bold) = 0;

    int get_state() {return state;}
    std::string get_type() {return type;}
    int get_price() {return price;}
    std::vector<std::pair<std::string, int> > get_attributes() {return attributes;}
    std::map<std::string, int> get_land_values() {return land_values;}

  protected:
    int y;
    int x;
    int state;
    std::string type;
    int price;
    int monthly_cost;
    char symbol;
    int color;
    bool bold;
    std::vector<std::pair<std::string, int> > attributes;

    std::map<std::string, int> land_values;

  private:
};

#endif
