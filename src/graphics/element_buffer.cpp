#include "element_buffer.h"

graphics::element_buffer::element_buffer(std::vector<unsigned int> &indices, unsigned int draw_type)
    : m_Id(0),
      m_Indices(indices)
{
  glCheckError(glGenBuffers(1, &m_Id));
  bind();

  // The array size in bytes.
  unsigned long int size = sizeof(float) * indices.size();
  glCheckError(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), &indices[0], draw_type));
}

graphics::element_buffer::~element_buffer()
{
  glCheckError(glDeleteBuffers(1, &m_Id));
}

unsigned int graphics::element_buffer::getId() const
{
  return m_Id;
}

unsigned long graphics::element_buffer::size() const
{
  return m_Indices.size();
}

void graphics::element_buffer::bind() const
{
  glCheckError(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id));
}

void graphics::element_buffer::unbind() const
{
  glCheckError(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
