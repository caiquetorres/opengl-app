#include "vertex_buffer.h"

graphics::vertex_buffer::vertex_buffer(std::vector<float> &vertices, int vertex_size, unsigned int draw_type)
    : m_Id(0),
      m_Vertices(vertices)
{
  glCheckError(glGenBuffers(1, &m_Id));
  bind();

  auto size = sizeof(float) * vertices.size();
  glCheckError(glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], draw_type));

  auto stride = (int)(vertex_size * sizeof(float));
  glCheckError(glVertexAttribPointer(0, vertex_size, GL_FLOAT, GL_FALSE, stride, nullptr));
  glCheckError(glEnableVertexAttribArray(0));
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
