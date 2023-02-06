#define GLFW_INCLUDE_NONE

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#pragma once

#include <exception>
#include <string>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../errors/error.h"
#include "../logger/logger.h"

namespace graphics
{
  /**
   * @brief The application window.
   */
  class window
  {
  private:
    unsigned int m_Width;

    unsigned int m_Height;

    const std::string &m_Title;

    GLFWwindow *m_Window = nullptr;

  public:
    /**
     * @param width the initial window width.
     * @param width the initial window height.
     * @param width the window title.
     */
    window(unsigned int width, unsigned int height, const std::string &title);

    ~window();

    /**
     * @brief Opens the window.
     */
    void open();

    /**
     * @brief Closes the window.
     */
    void close() const;

    /**
     * @brief Whether the window is opened or not.
     */
    bool is_open() const;

    /**
     * @brief Gets the current application width.
     * @return the application width.
     */
    unsigned int get_width() const;

    /**
     * @brief Gets the current application height.
     * @return the application height.
     */
    unsigned int get_height() const;

    /**
     * @brief Updates the window.
     */
    void update() const;

    /**
     * @brief Clears the window.
     */
    void clear() const;
  };
}

#endif
