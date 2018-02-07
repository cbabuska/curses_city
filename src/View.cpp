#include "View.h"

using std::vector;
using std::map;
using std::string;

#include "Constants.h"
#include "Cell.h"
#include "Status_grid.h"

View::View()
{
  initscr();
  background = newwin(DISPLAY_Y_SIZE, DISPLAY_X_SIZE, 0, 0);
  grid_window = newwin(Y_SIZE, X_SIZE, 1, 1);
  status_window = newwin(STATUS_Y_SIZE, STATUS_X_SIZE, 1, X_SIZE+2);
  noecho();

  start_color();
  init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
  init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
  init_pair(RED, COLOR_RED, COLOR_BLACK);
  init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);

  refresh();
}

View::~View()
{
  delwin(grid_window);
  delwin(status_window);
  delwin(background);
  endwin();
}

void View::draw_background(Status& status, string status_message)
{
  box(background, ACS_VLINE, ACS_HLINE);
  for (int y=1; y<DISPLAY_Y_SIZE-1; ++y)
  {
    mvwaddch(background, y, X_SIZE+1, ACS_VLINE);
  }
  mvwaddch(background, 0, X_SIZE+1, ACS_BSSS);
  mvwaddch(background, DISPLAY_Y_SIZE-1, X_SIZE+1, ACS_SSBS);
  mvwprintw(background, 0, 35, "Curses City");

  wattrset(background, COLOR_PAIR(CYAN) | A_STANDOUT);
  mvwprintw(background, 0, 2, status_message.c_str());
  wattrset(background, COLOR_PAIR(WHITE));

  wattrset(background, COLOR_PAIR(YELLOW) | A_STANDOUT);
  mvwprintw(background, 0, X_SIZE+3, " $%9d ", status.get_money());
  wattrset(background, COLOR_PAIR(WHITE));

  wattrset(background, COLOR_PAIR(GREEN) | A_STANDOUT);
  mvwprintw(background, 0, DISPLAY_X_SIZE-12, " %s ", status.get_date());
  wattrset(background, COLOR_PAIR(WHITE));

  wrefresh(background);
}

void View::draw_grid_window(Cursor& cursor, Grid& grid)
{  
  int color_pair;
  bool acs;
  bool bold;
  char to_draw; 

  wmove(grid_window, 0, 0);
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      to_draw = grid.get_cell(y, x)->draw(grid, color_pair, acs, bold);

      wattrset(grid_window, COLOR_PAIR(color_pair));
      if (acs) wattron(grid_window, A_ALTCHARSET);
      if (bold) wattron(grid_window, A_BOLD);

      waddch(grid_window, to_draw);

      wattroff(grid_window, A_ALTCHARSET | A_BOLD);
      wattrset(grid_window, COLOR_PAIR(WHITE));
    }
    move(y+1,0);
  }

  to_draw = grid.get_cell(cursor.get_y(), cursor.get_x())->draw(grid, color_pair, acs, bold);

  wattrset(grid_window, COLOR_PAIR(color_pair) | A_STANDOUT);
  if (acs) wattron(grid_window, A_ALTCHARSET);
  if (bold) wattron(grid_window, A_BOLD);

  mvwaddch(grid_window, cursor.get_y(), cursor.get_x(), to_draw);
  wmove(grid_window, cursor.get_y(), cursor.get_x());

  wattroff(grid_window, A_STANDOUT | A_ALTCHARSET | A_BOLD);
  wattrset(grid_window, COLOR_PAIR(WHITE));

  wrefresh(grid_window);
}
   
void View::draw_status_window(Cursor& cursor, Status& status, map<string, int> land_values, map<string, Status_grid*> status_grids)
{
  for (int i=0; i<NUMBER_OF_ZONE_TYPES; ++i)
  {
    mvwprintw(status_window, 1+i, 1, "%s Value: $%d", ZONE_TYPES[i].c_str(), land_values[ZONE_TYPES[i]]);
    wrefresh(status_window);
  }

  for (int i=0; i<NUMBER_OF_ATTRIBUTES; ++i)
  {
    mvwprintw(status_window, 5+i, 1, "%s: %d", ATTRIBUTES[i].c_str(), status_grids[ATTRIBUTES[i]]->get_grid()[cursor.get_y()][cursor.get_x()]);
    wrefresh(status_window);
  }
}


