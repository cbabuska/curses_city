#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>

#include <string>

class Logger
{
  public:
    static Logger& get_instance();
    void write(std::string message);

  protected:

  private:
    Logger(std::string filename_in);
    ~Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&);

    static Logger instance;

    FILE* fp;
};

#endif
