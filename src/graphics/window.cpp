#include "./window.h"
#include "window.h"

graphics::window::window(unsigned int width, unsigned int height, const std::string &title)
    : m_Title(title),
      m_Width(width),
      m_Height(height) {}

graphics::window::~window() {}

void graphics::window::open()
{
  if (!glfwInit())
  {
    // TODO: create a custom exception for that.
    logger::error("GLFW", "Error when initializing GLFW");
    throw std::exception();
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  m_Window = glfwCreateWindow((int)m_Width, (int)m_Height, m_Title.c_str(), nullptr, nullptr);

  if (!m_Window)
  {
    // TODO: create a custom exception for that.
    logger::error("GLFW", "Error when initializing GLFW");
    throw std::exception();
  }

  glfwMakeContextCurrent(m_Window);
  glfwSwapInterval(1);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    // TODO: create a custom exception for that.
    logger::error("GLAD", "Error when initializing GLAD");
    throw std::exception();
  }

  glCheckError(glEnable(GL_DEPTH_TEST));

  logger::debug("OpenGL", get_version());
  logger::info("Application", "Application started");
}

bool graphics::window::is_open() const
{
  return !glfwWindowShouldClose(m_Window);
}

unsigned int graphics::window::get_width() const
{
  int width;
  glfwGetWindowSize(m_Window, &width, nullptr);
  return width;
}

unsigned int graphics::window::get_height() const
{
  int height;
  glfwGetWindowSize(m_Window, nullptr, &height);
  return height;
}

const std::string graphics::window::get_version() const
{
  glCheckError(const std::string version((char *)glGetString(GL_VERSION)));
  return version;
}

void graphics::window::close() const
{
  logger::info("Application", "Application finished");
  glfwTerminate();
}

void graphics::window::update() const
{
  glfwPollEvents();
  glfwSwapBuffers(m_Window);
}

void graphics::window::clear() const
{
  glCheckError(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
