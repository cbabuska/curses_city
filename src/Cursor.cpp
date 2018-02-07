#include "Cursor.h"

#include "Constants.h"

void Cursor::move_cursor(char direction)
{
  switch(direction)
  {
    case 'n':
      if (y>0)
      {
        y--;
      }
      break;

    case 'e':
      if (x<X_SIZE-1)
      {
        x++;
      }
      break;

    case 's':
      if (y<Y_SIZE-1)
      {
        y++;
      }
      break;

    case 'w':
      if (x>0)
      {
        x--;
      }
      break;
  }
}
