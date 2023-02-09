#ifndef OPENGL_VERTEX_BUFFER_H
#define OPENGL_VERTEX_BUFFER_H

#pragma once

#include <glad/glad.h>
#include <vector>

#include "../errors/error.h"

namespace graphics
{
  /**
   * @brief The source for vertex array data
   */
  class vertex_buffer
  {
  private:
    unsigned int m_Id;

    std::vector<float> m_Vertices;

  public:
    /**
     * @param vertices the vertices set.
     * @param vertex_size the vertex element size.
     * @param draw_type the frequency which the array will be accessed.
     */
    vertex_buffer(std::vector<float> &vertices, int vertex_size, unsigned int draw_type);

    /**
     * @brief Gets the vertex buffer object identifier.
     * @return the identifier.
     */
    unsigned int get_id() const;

    /**
     * @brief Gets the vertex buffer length.
     * @return the vertex buffer length.
     */
    unsigned long size() const;

    /**
     * @brief Binds the vertex buffer.
     */
    void bind() const;

    /**
     * @brief Unbinds the vertex buffer.
     */
    void unbind() const;
  };
}

#endif
