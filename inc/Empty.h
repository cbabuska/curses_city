#ifndef EMPTY_H
#define EMPTY_H

#include "Logger.h"
#include "Cell.h"

class Status_grid;

class Empty : public Cell
{
  public:
    Empty(int y, int x, int type, char symbol, int color) : Cell(y, x, type, color), symbol(symbol) 
      {Logger::get_instance().write("Empty constructed");}
    ~Empty() {Logger::get_instance().write("Empty destructed");}

    void update_state(const std::vector<std::vector<Cell*> >& grid, std::map<int, Status_grid*>& status_grids);
    unsigned char draw(const std::vector<std::vector<Cell*> >& grid, int& color_pair);

  protected:

  private:
    char symbol;
};

#endif
