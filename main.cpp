#include <iostream>

#include "./src/logger/logger.h"
#include "src/errors/error.h"

int main()
{
  logger::info("Application", "Application started");
  return 0;
}
