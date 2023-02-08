#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#pragma once

#include <string>
#include <stb_image.h>
#include <fstream>

#include "../errors/error.h"

namespace graphics
{
  /**
   * @brief The image data.
   */
  class texture
  {
  private:
    unsigned int m_Id;

    const std::string &m_File_path;

    unsigned char *m_LocalBuffer;

    int m_Width;

    int m_Height;

    int m_BPP;

  public:
    texture(const std::string &file_path);

    ~texture();

    /**
     * @brief Binds the texture.
     * @param slot the texture layer.
     */
    void bind(unsigned int slot = 0) const;

    /**
     * @brief Gets the texture width.
     * @return the width.
     */
    inline unsigned int get_width()
    {
      return (unsigned int)m_Width;
    }

    /**
     * @brief Gets the texture height.
     * @return the height.
     */
    inline unsigned int get_height()
    {
      return (unsigned int)m_Height;
    }
  };
}

#endif
