#define STB_IMAGE_IMPLEMENTATION

#include "texture.h"

graphics::texture::texture(const std::string &file_path)
    : m_Id(0),
      m_File_path(file_path),
      m_Height(0),
      m_Width(0),
      m_LocalBuffer(nullptr),
      m_BPP(0)
{

  auto path = std::__fs::filesystem::current_path().string() + "/build/res/" + file_path.c_str();
  std::ifstream test(path);

  if (!test)
  {
    logger::error("STD IMAGE", "Error when reading \"" + path);
    // TODO: create a custom exception.
    throw std::exception();
  }

  stbi_set_flip_vertically_on_load(0);
  m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 3);

  glCheckError(glGenTextures(1, &m_Id));
  glCheckError(glBindTexture(GL_TEXTURE_2D, m_Id));

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glCheckError(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_LocalBuffer));

  if (m_LocalBuffer)
  {
    stbi_image_free(m_LocalBuffer);
  }
}

graphics::texture::~texture()
{
  glCheckError(glDeleteTextures(1, &m_Id));
}

void graphics::texture::bind(unsigned int slot) const
{
  glCheckError(glActiveTexture(GL_TEXTURE0 + slot));
  glCheckError(glBindTexture(GL_TEXTURE_2D, m_Id));
}
