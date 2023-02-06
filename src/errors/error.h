#ifndef OPENGL_ERROR_H
#define OPENGL_ERROR_H

#pragma once

#include <string>
#include <glad/glad.h>

#include "../logger/logger.h"

/**
 * @brief Clears all the current errors.
 */
void clearError();

/**
 * @brief Checks whether some statement has or not errors.
 * @param function the function name.
 * @param file the file path.
 * @param line the line which the error is happening.
 * @return a value that identifies the OpenGL error code.
 */
unsigned int checkError(const char *function, const char *file, unsigned int line);

/**
 * @brief Checks if some statement has or not errors.
 * @note This function only works with statements related with OpenGL related
 * functions.
 */
#define glCheckError(fun) \
  clearError();           \
  fun;                    \
  checkError(#fun, __FILE__, __LINE__)

#endif
