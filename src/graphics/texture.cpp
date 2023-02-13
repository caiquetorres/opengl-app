#define STB_IMAGE_IMPLEMENTATION

#include "texture.h"

graphics::texture::texture(const std::string &file_path)
    : m_Id(0),
      m_File_path(file_path),
      m_Height(0),
      m_Width(0),
      m_LocalBuffer(),
      m_BPP(0)
{

  std::string path = "res/" + file_path;
  std::ifstream test(path);

  if (!test)
  {
    logger::error("STD IMAGE", "Error when reading \"" + file_path);
    // TODO: create a custom exception.
    throw std::exception();
  }

  stbi_set_flip_vertically_on_load(0);
  m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 3);

  glCheckError(glGenTextures(1, &m_Id));
  glCheckError(glBindTexture(GL_TEXTURE_2D, m_Id));

  glCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
  glCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
  glCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
  glCheckError(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

  // Mirror image x axis
  for (unsigned int i = 0, j = (m_Width * m_Height * 3) - 1; i <= j; i++, j--)
  {
    m_LocalBuffer[i] ^= m_LocalBuffer[j];
    m_LocalBuffer[j] = m_LocalBuffer[i] ^ m_LocalBuffer[j];
    m_LocalBuffer[i] ^= m_LocalBuffer[j];
  }

  glCheckError(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_LocalBuffer));
  glCheckError(glGenerateMipmap(GL_TEXTURE_2D));

  if (m_LocalBuffer)
  {
    stbi_image_free(m_LocalBuffer);
  }
}

graphics::texture::~texture()
{
  glCheckError(glDeleteTextures(1, &m_Id));
}

unsigned int graphics::texture::get_id() const
{
  return m_Id;
}

void graphics::texture::bind(unsigned int slot) const
{
  glCheckError(glActiveTexture(GL_TEXTURE0 + slot));
  glCheckError(glBindTexture(GL_TEXTURE_2D, m_Id));
}
