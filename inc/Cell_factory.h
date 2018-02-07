#ifndef CELL_FACTORY_H
#define CELL_FACTORY_H

class Cell;

class Cell_factory
{
  public:
    static Cell* create_cell(char command, int y, int x);

  protected:

  private:

};

#endif
