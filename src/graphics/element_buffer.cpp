#include "element_buffer.h"

graphics::element_buffer::element_buffer(std::vector<unsigned int> &indices, int vertexSize, unsigned int drawType)
    : m_Id(0),
      m_Indices(indices)
{
  glGenBuffers(1, &m_Id);
  bind();

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &indices[0], drawType);
  glVertexAttribPointer(0, vertexSize, GL_FLOAT, GL_FALSE, (int)(vertexSize * sizeof(float)), (void *)0);
  glEnableVertexAttribArray(0);
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
