#include "vertex_array.h"

graphics::vertex_array::vertex_array()
    : m_Id(0)
{
  glCheckError(glGenVertexArrays(1, &m_Id));
  bind();
}

unsigned int graphics::vertex_array::get_id() const
{
  return m_Id;
}

void graphics::vertex_array::bind() const
{
  glCheckError(glBindVertexArray(m_Id));
}
