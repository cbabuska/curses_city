#include "Cell_factory.h"

#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::pair;
using std::make_pair;
using std::string;

#include "Zone.h"
#include "Municipal.h"

Cell* Cell_factory::create_cell(char command, int y, int x)
{
  vector<pair<string, int> > attributes;

  switch (command)
  {
    case 'r':
      attributes.push_back(make_pair(RESIDENTIAL_POPULATION, 5));
      return new Zone(y, x, RESIDENTIAL, 100, 0, '.', GREEN, true, attributes);

    case 'c':
      attributes.push_back(make_pair(COMMERCIAL_POPULATION, 5));
      return new Zone(y, x, COMMERCIAL, 200, 0, '.', BLUE, true, attributes);

    case 'i':
      attributes.push_back(make_pair(POLLUTION, 5));
      attributes.push_back(make_pair(INDUSTRIAL_POPULATION, 5));
      return new Zone(y, x, INDUSTRIAL, 150, 0, '.', YELLOW, true, attributes);

    case 'o':
      attributes.push_back(make_pair(ROAD_ACCESS, 1));
      return new Municipal(y, x, ROAD, 50, 5, '-' , WHITE, false, attributes);

    case 'd':
      return new Municipal(y, x, RAIL, 25, 2, '-', WHITE, false);

    case 'p':
      attributes.push_back(make_pair(SAFETY, 10));
      return new Municipal(y, x, POLICE_STATION, 500, 50, 'P', BLUE, true, attributes);

    case 'f':
      attributes.push_back(make_pair(FIRE_SAFETY, 10));
      return new Municipal(y, x, FIRE_STATION, 500, 50, 'F', RED, true, attributes);

    case 's':
      attributes.push_back(make_pair(EDUCATION, 10));
      return new Municipal(y, x, SCHOOL, 300, 30, 'S', WHITE, true, attributes);

    case 'm':
      attributes.push_back(make_pair(HEALTH, 10));
      return new Municipal(y, x, HOSPITAL, 1000, 100, 'H', RED, true, attributes);

    case 'a':
      attributes.push_back(make_pair(RECREATION, 10));
      return new Municipal(y, x, PARK, 200, 10, '-', GREEN, true, attributes);

    case 'w':
      attributes.push_back(make_pair(POWER, 25));
      attributes.push_back(make_pair(POLLUTION, 10));
      return new Municipal(y, x, COAL_POWER_PLANT, 750, 75, 'W', YELLOW, false, attributes);

    case 'n':
      attributes.push_back(make_pair(POWER, 35));
      return new Municipal(y, x, NUCLEAR_POWER_PLANT, 1250, 1250, 'N', WHITE, false, attributes);

    case 'x':
      return new Municipal(y, x, LAND, 0, 0, ' ', WHITE, false);

    default:
      return NULL;
  }
}
