// logger.cpp

#include "sub_logger.h"

void Logger::initialize(std::string pathTologgerFile, std::string name,
                        std::string properties_path) {

  this->appender_name = name + "appender";
  log4cpp::PropertyConfigurator::configure(properties_path);
  log4cpp::Category &log =
      log4cpp::Category::getInstance(string(appender_name));
  logger = &log;

  log4cpp::Appender *appender =
      new log4cpp::FileAppender("default", pathTologgerFile);

  log4cpp::PatternLayout *Layout = new log4cpp::PatternLayout();
  Layout->setConversionPattern("%d [%p] %m%n");
  appender->setLayout(Layout);
  log.addAppender(appender);
}

void Logger::debug(std::string msg) { LOG4CPP_DEBUG_S((*logger)) << msg; }
void Logger::info(std::string msg) { LOG4CPP_INFO_S((*logger)) << msg; }
void Logger::warn(std::string msg) { LOG4CPP_WARN_S((*logger)) << msg; }
void Logger::error(std::string msg) { LOG4CPP_ERROR_S((*logger)) << msg; }
void Logger::fatal(std::string msg) { LOG4CPP_FATAL_S((*logger)) << msg; }

/*  get current date, format is DD_MM_YYYY */
std::string Logger::currentDate() {
  time_t now = time(0);
  char curr_date[80];
  struct tm tstruct;
  tstruct = *localtime(&now);
  strftime(curr_date, sizeof(curr_date), "%d_%m_%Y", &tstruct);
  return std::string(curr_date);
}

/* return system current time hh:mm:ss */
std::string Logger::currentTime() {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  std::string _time;
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%X", &tstruct);
  _time = std::string(buf);
  std::replace(_time.begin(), _time.end(), ':', '_');

  return _time;
}
