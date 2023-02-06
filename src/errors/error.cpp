#include "error.h"

void clearError()
{
  while ((glGetError()) != GL_NO_ERROR)
    ;
}

unsigned int checkError(const char *function, const char *file, unsigned int line)
{
  unsigned int errorCode;

  while ((errorCode = glGetError()) != GL_NO_ERROR)
  {
    std::string error;

    switch (errorCode)
    {
    case GL_INVALID_ENUM:
      error = "Invalid Enumeration";
      break;
    case GL_INVALID_VALUE:
      error = "Invalid Value";
      break;
    case GL_INVALID_OPERATION:
      error = "Invalid Operation";
      break;
    case GL_STACK_OVERFLOW:
      error = "StackOverflow";
      break;
    case GL_STACK_UNDERFLOW:
      error = "StackUnderflow";
      break;
    case GL_OUT_OF_MEMORY:
      error = "Out of Memory";
      break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
      error = "Invalid Framebuffer Operation";
      break;
    default:
      break;
    }

    std::string stacktrace = std::string(function) + " " + std::string(file) + " " + std::to_string(line);
    logger::error("OpenGL", error, stacktrace);
  }

  return errorCode;
}
