#ifndef OPENGL_VERTEX_BUFFER_LAYOUT_H
#define OPENGL_VERTEX_BUFFER_LAYOUT_H

#pragma once

#include <glad/glad.h>
#include <vector>

namespace graphics
{
  struct vertex_buffer_layout_element
  {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
  };

  /**
   * @brief Structure that represents a vertex layout.
   */
  class vertex_buffer_layout
  {
  private:
    unsigned int m_Stride;

    std::vector<vertex_buffer_layout_element> m_Elements;

  public:
    vertex_buffer_layout();

    vertex_buffer_layout(unsigned int stride);

    /**
     * @brief Adds a new vertex buffer configuration.
     * @tparam T the vertex element data type.
     * @param count the vertex element count.
     */
    template <typename T>
    void push(unsigned int count);

    /**
     * @brief Gets the current stride.
     * @return the stride.
     */
    unsigned int get_stride() const;

    /**
     * @brief Gets the vertex buffer layout elements.
     * @return the vertex buffer layout elements.
     */
    std::vector<vertex_buffer_layout_element> &get_elements();

    /**
     * @brief Gets a type size.
     * @param type the GL type.
     * @return the size.
     */
    static unsigned int get_size_of_type(unsigned int type);
  };
}

#endif
