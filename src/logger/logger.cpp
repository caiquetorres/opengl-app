#include "logger.h"

void logger::info(const std::string &context, const std::string &message)
{
  std::cout << "\033[0;37m[" << logger::get_time() << "]\033[0m "
            << "\033[1;32mINFO\033[0m"
            << " \033[0;33m[" << context << "]\033[0m "
            << "\033[0;32m" << message << "\033[0m" << std::endl;
}

void logger::debug(const std::string &context, const std::string &message)
{
  std::cout << "\033[0;37m[" << logger::get_time() << "]\033[0m "
            << "\033[1;35mDEBUG\033[0m"
            << " \033[0;33m[" << context << "]\033[0m "
            << "\033[0;35m" << message << "\033[0m" << std::endl;
}

void logger::warn(const std::string &context, const std::string &message)
{
  std::cout << "\033[0;37m[" << logger::get_time() << "]\033[0m "
            << "\033[1;33mWARN\033[0m"
            << " \033[0;33m[" << context << "]\033[0m "
            << "\033[0;33m" << message << "\033[0m" << std::endl;
}

void logger::warn(const std::string &context, const std::string &message, const std::string &stacktrace)
{
  std::cout << "\033[0;37m[" << logger::get_time() << "]\033[0m "
            << "\033[1;33mWARN\033[0m"
            << " \033[0;33m[" << context << "]\033[0m "
            << "\033[0;33m" << message << "\033[0m" << std::endl;

  std::cout << "\033[0;39m" << stacktrace << "\u001B[0m" << std::endl;
}

void logger::error(const std::string &context, const std::string &message)
{
  std::cout << "\033[0;37m[" << logger::get_time() << "]\033[0m "
            << "\033[1;31mERROR\033[0m"
            << " \033[0;33m[" << context << "]\033[0m "
            << "\033[0;31m" << message << "\033[0m" << std::endl;
}

void logger::error(const std::string &context, const std::string &message, const std::string &stacktrace)
{
  std::cout << "\033[0;37m[" << logger::get_time() << "]\033[0m "
            << "\033[1;31mERROR\033[0m"
            << " \033[0;33m[" << context << "]\033[0m "
            << "\033[0;31m" << message << "\033[0m" << std::endl;

  std::cout << "\033[0;39m" << stacktrace << "\u001B[0m" << std::endl;
}

std::string logger::get_time()
{
  time_t rawTime;
  struct tm *timeInfo;
  char buffer[80];

  time(&rawTime);
  timeInfo = localtime(&rawTime);

  strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeInfo);
  std::string str(buffer);
  return str;
}
