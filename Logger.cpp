#include "Logger/logger.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

static int frontCamFrameCount = 0, bottomCamFrameCount = 0;
static double heading = 0, pitch = 0, roll = 0, magX = 0, magY = 0, magZ = 0,
              aclX = 0, aclY = 0, aclZ = 0, angX = 0, angY = 0, angZ = 0;
static double depth = 0, altitude = 0, thickness = 0;

int main(int argc, char *argv[]) {

  std::string logvalues;

//Give complete path
  InitLog("Data2.log");

  frontCamFrameCount = 1222;
  bottomCamFrameCount = 122;

  heading = 1222;
  pitch = 1222;
  roll = 1222;
  magX = 1222;
  magZ = 1222;
  magY = 1222;
  aclY = 1222;
  aclX = 1222;
  aclZ = 1222;
  angX = 1222;
  angY = 1222;
  angZ = 1222;

  depth = 1222;
  altitude = 1222;
  // thickness = s_memory.fetch("Cygnus", 1);

  logvalues = std::to_string(frontCamFrameCount) + "," +
              std::to_string(bottomCamFrameCount) + "," +
              std::to_string(heading) + "," + std::to_string(pitch) + "," +
              std::to_string(roll) + "," + std::to_string(magX) + "," +
              std::to_string(magY) + "," + std::to_string(magZ) + "," +
              std::to_string(aclX) + "," + std::to_string(aclY) + "," +
              std::to_string(aclZ) + "," + std::to_string(angX) + "," +
              std::to_string(angY) + "," + std::to_string(angZ) + "," +
              std::to_string(depth) + "," + std::to_string(altitude) + "," +
              std::to_string(thickness);

  LOG_INFO(logvalues);

  usleep(100000);

  return 0;
}
