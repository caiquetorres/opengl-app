#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H

#pragma once

#include <vector>
#include <glad/glad.h>

#include "vertex.h"
#include "texture.h"
#include "shader.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "element_buffer.h"
#include "vertex_buffer_layout.h"

namespace graphics
{
  class mesh
  {
  private:
    vertex_buffer_layout m_Layout;

    vertex_array m_Va;

    vertex_buffer m_Vb;

    element_buffer m_Eb;

    std::vector<vertex> &m_Vertices;

    std::vector<unsigned int> &m_Indices;

    texture &m_Texture;

  public:
    mesh(std::vector<vertex> &vertices, std::vector<unsigned int> &indices, texture &texture);

    void draw(shader &shader);
  };
}

#endif
