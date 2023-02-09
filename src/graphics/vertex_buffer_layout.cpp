#include "vertex_buffer_layout.h"

graphics::vertex_buffer_layout::vertex_buffer_layout()
    : m_Stride(0)
{
}

graphics::vertex_buffer_layout::vertex_buffer_layout(unsigned int stride)
    : m_Stride(stride)
{
}

template <>
void graphics::vertex_buffer_layout::push<float>(unsigned int count)
{
  vertex_buffer_layout_element element{GL_FLOAT, count, GL_FALSE};
  m_Elements.push_back(element);
  m_Stride += count * vertex_buffer_layout::get_size_of_type(GL_FLOAT);
}

template <>
void graphics::vertex_buffer_layout::push<unsigned int>(unsigned int count)
{
  vertex_buffer_layout_element element{GL_UNSIGNED_INT, count, GL_FALSE};
  m_Elements.push_back(element);
  m_Stride += count * vertex_buffer_layout::get_size_of_type(GL_UNSIGNED_INT);
}

template <>
void graphics::vertex_buffer_layout::push<unsigned char>(unsigned int count)
{
  vertex_buffer_layout_element element{GL_UNSIGNED_BYTE, count, GL_FALSE};
  m_Elements.push_back(element);
  m_Stride += count * vertex_buffer_layout::get_size_of_type(GL_UNSIGNED_BYTE);
}

unsigned int graphics::vertex_buffer_layout::get_stride() const
{
  return m_Stride;
}

std::vector<graphics::vertex_buffer_layout_element> &graphics::vertex_buffer_layout::get_elements()
{
  return m_Elements;
}

unsigned int graphics::vertex_buffer_layout::get_size_of_type(unsigned int type)
{
  switch (type)
  {
  case GL_FLOAT:
    return sizeof(float);
  case GL_UNSIGNED_INT:
    return sizeof(unsigned int);
  case GL_UNSIGNED_BYTE:
    return sizeof(char);
  }

  return 0;
}
