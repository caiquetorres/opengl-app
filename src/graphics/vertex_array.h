#ifndef OPENGL_VERTEX_ARRAY_H
#define OPENGL_VERTEX_ARRAY_H

#pragma once

#include <glad/glad.h>

#include "../errors/error.h"

namespace graphics
{
  /**
   * @brief The information for a complete rendered object.
   */
  class vertex_array
  {
  private:
    unsigned int m_Id;

  public:
    vertex_array();

    /**
     * @brief Gets the vertex buffer object identifier.
     * @return the identifier.
     */
    unsigned int get_id() const;

    /**
     * @brief Binds the vertex buffer.
     */
    void bind() const;
  };
}

#endif
