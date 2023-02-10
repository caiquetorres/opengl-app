#include "vertex_buffer.h"

graphics::vertex_buffer::vertex_buffer(std::vector<vertex> &vertices, unsigned int draw_type)
    : m_Id(0),
      m_Vertices(vertices)
{
  glCheckError(glGenBuffers(1, &m_Id));
  bind();

  // The array size in bytes.
  unsigned long int size = sizeof(vertex) * vertices.size();
  glCheckError(glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], draw_type));
}

unsigned int graphics::vertex_buffer::get_id() const
{
  return m_Id;
}

unsigned long graphics::vertex_buffer::size() const
{
  return m_Vertices.size();
}

void graphics::vertex_buffer::bind() const
{
  glCheckError(glBindBuffer(GL_ARRAY_BUFFER, m_Id));
}

void graphics::vertex_buffer::unbind() const
{
  glCheckError(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
