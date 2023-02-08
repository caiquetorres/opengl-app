#include "vertex_buffer.h"

graphics::vertex_buffer::vertex_buffer(std::vector<float> &vertices, int vertex_size, unsigned int draw_type)
    : m_Id(0),
      m_Vertices(vertices)
{
  glCheckError(glGenBuffers(1, &m_Id));
  bind();

  // The array size in bytes.
  unsigned long int size = sizeof(float) * vertices.size();
  glCheckError(glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], draw_type));

  // The vertex size in bytes.
  int stride = (int)(8 * sizeof(float));

  // TODO: Move this statements into vertex_array
  glCheckError(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, nullptr));
  glCheckError(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, nullptr));
  glCheckError(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, nullptr));

  glCheckError(glEnableVertexAttribArray(0));
  glCheckError(glEnableVertexAttribArray(1));
  glCheckError(glEnableVertexAttribArray(2));
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
