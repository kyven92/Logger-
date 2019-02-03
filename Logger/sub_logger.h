#ifndef _sub_loggerH
#define _sub_loggerH

#include "log4cpp/Appender.hh"
#include "log4cpp/Category.hh"
#include "log4cpp/CategoryStream.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/PropertyConfigurator.hh"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

using namespace log4cpp;
using namespace std;

class Logger {
public:
  std::string appender_name;
  void initialize(std::string pathToLoggerFile, std::string name,
                  std::string properties_path);
  log4cpp::Category *logger;
  void debug(std::string msg);
  void info(std::string msg);
  void warn(std::string msg);
  void error(std::string msg);
  void fatal(std::string msg);
  std::string currentDate();
  std::string currentTime();
};

#endif /*_loggerH*/
