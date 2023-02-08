#ifndef OPENGL_ELEMENT_BUFFER_H
#define OPENGL_ELEMENT_BUFFER_H

#pragma once

#include <glad/glad.h>
#include <vector>

#include "../errors/error.h"

namespace graphics
{
  /**
   * @brief The information uses to decide what vertices to draw.
   */
  class element_buffer
  {
  private:
    unsigned int m_Id;

    std::vector<unsigned int> m_Indices;

  public:
    /**
     * @param indices the index set.
     * @param index_size the vertex element size.
     * @param draw_type the frequency which the array will be accessed.
     */
    element_buffer(std::vector<unsigned int> &indices, int index_size, unsigned int draw_type);

    ~element_buffer();

    /**
     * @brief Gets the element buffer object identifier.
     * @return the identifier.
     */
    unsigned int getId() const;

    /**
     * @brief Gets the element buffer length.
     * @return the identifier.
     */
    unsigned long size() const;

    /**
     * @brief Binds the element buffer.
     */
    void bind() const;
  };
}

#endif
