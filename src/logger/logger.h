#ifndef OPENGL_LOGGER_H
#define OPENGL_LOGGER_H

#pragma once

#include "iostream"
#include "string"

namespace logger
{
  /**
   * @brief Prints the message in a success context.
   * @param context the logger context.
   * @param message the message that will be printed.
   */
  void info(const std::string &context, const std::string &message);

  /**
   * @brief Prints the message in a neutral context.
   * @param context the logger context.
   * @param message the message that will be printed.
   * @note A neutral context does not have any logging level.
   */
  void debug(const std::string &context, const std::string &message);

  /**
   * @brief Prints the message in a warn context.
   * @param context the logger context.
   * @param message the message that will be printed.
   */
  void warn(const std::string &context, const std::string &message);

  /**
   * @brief Prints the message in a warn context.
   * @param context the logger context.
   * @param message the message that will be printed.
   * @param stacktrace the message stacktrace.
   */
  void warn(const std::string &context, const std::string &message, const std::string &stacktrace);

  /**
   * @brief Prints the message in an error context.
   * @param context the logger context.
   * @param message the message that will be printed.
   */
  void error(const std::string &context, const std::string &message);

  /**
   * @brief Prints the message in an error context.
   * @param context the logger context.
   * @param message the message that will be printed.
   * @param stacktrace the message stacktrace.
   */
  void error(const std::string &context, const std::string &message, const std::string &stacktrace);

  /**
   * @brief Returns the current time in format MM-DD-YYY HH:mm:ss.
   * @return the time sentence.
   */
  std::string get_time();
};

#endif
