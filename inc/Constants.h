#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>
#include <utility>

enum Colors
{
  BLACK = 1,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
};



const int DISPLAY_Y_SIZE = 24;
const int DISPLAY_X_SIZE = 80;

const int Y_SIZE = DISPLAY_Y_SIZE - 2;
const int X_SIZE = 50;

const int STATUS_Y_SIZE = DISPLAY_Y_SIZE - 2; 
const int STATUS_X_SIZE = DISPLAY_X_SIZE - X_SIZE - 3;



const int STARTING_MONEY = 10000;



const int NUMBER_OF_ATTRIBUTES = 11;

const std::string ROAD_ACCESS            = "Road Access";
const std::string SAFETY                 = "Safety";
const std::string FIRE_SAFETY            = "Fire Safety";
const std::string EDUCATION              = "Education";
const std::string HEALTH                 = "Health";
const std::string RECREATION             = "Recreation";
const std::string POWER                  = "Power";
const std::string POLLUTION              = "Pollution";
const std::string RESIDENTIAL_POPULATION = "Residential Population";
const std::string COMMERCIAL_POPULATION  = "Commerical Population";
const std::string INDUSTRIAL_POPULATION  = "Industrial Population";

const std::string ATTRIBUTES[] = {ROAD_ACCESS, SAFETY, FIRE_SAFETY, EDUCATION, HEALTH, RECREATION, POWER, POLLUTION, RESIDENTIAL_POPULATION, COMMERCIAL_POPULATION, INDUSTRIAL_POPULATION};



const int NUMBER_OF_CELL_TYPES= 13;
const int NUMBER_OF_ZONE_TYPES= 3;
const int NUMBER_OF_MUNI_TYPES= NUMBER_OF_CELL_TYPES - NUMBER_OF_ZONE_TYPES;

const std::string RESIDENTIAL         = "Residential";
const std::string COMMERCIAL          = "Commercial";
const std::string INDUSTRIAL          = "Industrial";
const std::string ROAD                = "Road";
const std::string RAIL                = "Rail";
const std::string POLICE_STATION      = "Police Station";
const std::string FIRE_STATION        = "Fire Station";
const std::string SCHOOL              = "School";
const std::string HOSPITAL            = "Hospital";
const std::string PARK                = "Park";
const std::string COAL_POWER_PLANT    = "Coal Power Plant";
const std::string NUCLEAR_POWER_PLANT = "Nuclear Power Plant";
const std::string LAND                = "Land";

const std::string CELL_TYPES[] = {RESIDENTIAL, COMMERCIAL, INDUSTRIAL, ROAD, RAIL, POLICE_STATION, FIRE_STATION, SCHOOL, HOSPITAL, PARK, COAL_POWER_PLANT, NUCLEAR_POWER_PLANT, LAND};
const std::string ZONE_TYPES[] = {RESIDENTIAL, COMMERCIAL, INDUSTRIAL}; 
const std::string MUNI_TYPES[] = {ROAD, RAIL, POLICE_STATION, FIRE_STATION, SCHOOL, HOSPITAL, PARK, COAL_POWER_PLANT, NUCLEAR_POWER_PLANT, LAND}; 



const int NUMBER_OF_ZONE_REQUIREMENTS = 2;
const std::string ZONE_REQUIREMENTS[] = {ROAD_ACCESS, POWER};

const int LAND_VALUE_PARAMS[NUMBER_OF_ZONE_TYPES][NUMBER_OF_ATTRIBUTES] = 
  {{10, 10,  0, 20, 10, 10, 10,-30, 10, 10,  0},  // Residential params                                                                         
   {10, 20, 10,  0,  0, 10, 10,-10, 20, 10, 10},  // Commercial params                                                                         
   {10, 10, 20,  0,  0,  0, 20,  0, 10, 10, 10}}; // Industrial params
  
#endif
