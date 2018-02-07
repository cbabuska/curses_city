#include "Logger.h"

using std::string;

Logger Logger::instance("log.txt");

Logger& Logger::get_instance()
{
  return instance;
}

Logger::Logger(string filename)
{
  fp = fopen(filename.c_str(), "a");
  fprintf(fp, "\n\n\n---------------------------\nLogger constructed\n");
}

Logger::~Logger()
{
  fprintf(fp, "Logger destructed\n");
  fclose(fp);
}

void Logger::write(string message)
{
  fprintf(fp, "%s\n", message.c_str());
}
