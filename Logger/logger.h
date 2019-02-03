  // logger.h

#ifndef _loggerH
#define _loggerH

#include "log4cpp/Appender.hh"
#include "log4cpp/Category.hh"
#include "log4cpp/CategoryStream.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/PropertyConfigurator.hh"

#include <iostream>
#include <string.h>

using namespace log4cpp;

#define AppenderName "rootAppender"

extern log4cpp::Category *logger;

#define LOG_DEBUG(msg)                                                         \
  LOG4CPP_DEBUG_S((*logger)) << msg ;
#define LOG_INFO(msg)                                                          \
  LOG4CPP_INFO_S((*logger)) << msg ;
#define LOG_WARN(msg)                                                          \
  LOG4CPP_WARN_S((*logger)) << msg ;
#define LOG_ERROR(msg)                                                         \
  LOG4CPP_ERROR_S((*logger)) << msg ;
#define LOG_FATAL(msg)                                                         \
  LOG4CPP_FATAL_S((*logger)) << msg ;

using namespace std;

void InitLog(std::string pathToLoggerFile);

#endif /*_loggerH*/
