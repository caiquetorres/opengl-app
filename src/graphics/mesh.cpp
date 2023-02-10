#include "mesh.h"

graphics::mesh::mesh(std::vector<vertex> &vertices, std::vector<unsigned int> &indices, texture &texture)
    : m_Va(vertex_array()),
      m_Vb(vertex_buffer(vertices, GL_STATIC_DRAW)),
      m_Eb(element_buffer(indices, GL_STATIC_DRAW)),
      m_Layout(vertex_buffer_layout()),
      m_Vertices(vertices),
      m_Indices(indices),
      m_Texture(texture)
{
  m_Va.bind();
  m_Vb.bind();
  m_Eb.bind();

  m_Layout.push<float>(3); // position
  m_Layout.push<float>(3); // color
  m_Layout.push<float>(2); // texture coordinates

  m_Va.add_buffer(m_Vb, m_Layout);

  m_Va.bind();
  m_Vb.bind();
  m_Eb.bind();
}

void graphics::mesh::draw(shader &shader)
{
  shader.use();

  m_Va.bind();
  m_Eb.bind();

  m_Texture.bind();
  shader.set_int("uTexture", 0);

  glCheckError(glDrawElements(GL_TRIANGLES, m_Layout.get_total_count() * m_Vertices.size(), GL_UNSIGNED_INT, 0));

  m_Va.unbind();
  m_Eb.unbind();
}
