#include "vertex_array.h"

graphics::vertex_array::vertex_array()
    : m_Id(0)
{
  glCheckError(glGenVertexArrays(1, &m_Id));
  bind();
}

graphics::vertex_array::~vertex_array()
{
  glCheckError(glDeleteVertexArrays(1, &m_Id));
}

unsigned int graphics::vertex_array::get_id() const
{
  return m_Id;
}

void graphics::vertex_array::bind() const
{
  glCheckError(glBindVertexArray(m_Id));
}

void graphics::vertex_array::unbind() const
{
  glCheckError(glBindVertexArray(0));
}

void graphics::vertex_array::add_buffer(vertex_buffer &vb, vertex_buffer_layout &layout)
{
  bind();
  vb.bind();

  unsigned int offset = 0;
  const auto &elements = layout.get_elements();

  for (unsigned int i = 0; i < elements.size(); i++)
  {
    const auto &element = elements[i];
    glCheckError(glEnableVertexAttribArray(i));
    glCheckError(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.get_stride(), (const void *)(size_t)offset));
    offset += element.count * vertex_buffer_layout::get_size_of_type(element.type);
  }
}
