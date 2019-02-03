// logger.cpp

#include "logger.h"
log4cpp::Category *logger;
void InitLog(std::string pathTologgerFile) {

  log4cpp::PropertyConfigurator::configure("Logger/log4cpp.properties");
  log4cpp::Category &log = log4cpp::Category::getInstance(string(AppenderName));
  logger = &log;

  log4cpp::Appender *appender2 =
      new log4cpp::FileAppender("default", pathTologgerFile);

  log4cpp::PatternLayout *testLayout = new log4cpp::PatternLayout();
  testLayout->setConversionPattern("%m%n");

  appender2->setLayout(testLayout);
  log.removeAllAppenders();
  log.addAppender(appender2);
}
