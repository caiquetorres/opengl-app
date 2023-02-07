#include "shader.h"

graphics::shader::shader(const std::string &filePath)
{
  std::fstream stream;

  try
  {
    stream.open(std::__fs::filesystem::current_path().string() + "/res/" + filePath);

    std::string version;
    std::getline(stream, version);

    m_Vertex = version + "\n#define COMPILING_VERTEX_SHADER";
    m_Fragment = version + "\n#define COMPILING_FRAGMENT_SHADER";

    std::string line;
    while (std::getline(stream, line))
    {
      m_Vertex += line + "\n";
      m_Fragment += line + "\n";
    }

    glCheckError(m_Id = glCreateProgram());

    unsigned int vs = compile(GL_VERTEX_SHADER, m_Vertex);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, m_Fragment);

    glCheckError(glAttachShader(m_Id, vs));
    glCheckError(glAttachShader(m_Id, fs));
    glCheckError(glLinkProgram(m_Id));
    glCheckError(glValidateProgram(m_Id));

    glCheckError(glDeleteShader(vs));
    glCheckError(glDeleteShader(fs));

    use();
  }
  catch (std::ifstream::failure &e)
  {
    std::string m = std::string(e.what());
    logger::error("GLSL", "Error when reading \"" + filePath, m);

    // TODO: create a custom exception.
    throw std::exception();
  }
}

unsigned int graphics::shader::compile(unsigned int type, const std::string &source)
{
  glCheckError(const unsigned int id = glCreateShader(type));
  const char *src = source.c_str();

  glCheckError(glShaderSource(id, 1, &src, nullptr));
  glCheckError(glCompileShader(id));

  int result;
  glCheckError(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

  if (!result)
  {
    int length;
    glCheckError(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

    char *message = (char *)alloca(length * sizeof(char));
    glCheckError(glGetShaderInfoLog(id, length, &length, message));

    glCheckError(glDeleteShader(id));

    std::string m(message);
    logger::error("GLSL", "Failed to compile Shader", m);

    // TODO: create a custom exception.
    throw std::exception();
  }

  return id;
}

unsigned int graphics::shader::get_id() const
{
  return m_Id;
}

void graphics::shader::use() const
{
  glCheckError(glUseProgram(m_Id));
}

void graphics::shader::set_bool(const std::string &name, const bool value) const
{
  glCheckError(glUniform1i(glGetUniformLocation(m_Id, name.c_str()), (int)value));
}

void graphics::shader::set_int(const std::string &name, const int value) const
{
  glCheckError(glUniform1i(glGetUniformLocation(m_Id, name.c_str()), value));
}

void graphics::shader::set_float(const std::string &name, const float value) const
{
  glCheckError(glUniform1f(glGetUniformLocation(m_Id, name.c_str()), (int)value));
}