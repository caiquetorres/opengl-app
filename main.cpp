#include <vector>

#include "src/graphics/window.h"
#include "src/graphics/vertex_array.h"
#include "src/graphics/vertex_buffer.h"
#include "src/graphics/element_buffer.h"
#include "src/graphics/shader.h"

int main()
{
  graphics::window window(1080, 720, "OpenGL");
  window.open();

  std::vector<float> vertices = {
      0.5f, 0.5f, 0.0f,
      0.5f, -0.5f, 0.0f,
      -0.5f, -0.5f, 0.0f,
      -0.5f, 0.5f, 0.0f};

  std::vector<unsigned int> indices = {
      0, 1, 3,
      1, 2, 3};

  graphics::vertex_array va;
  graphics::vertex_buffer vb(vertices, 3, GL_STATIC_DRAW);
  graphics::element_buffer eb(indices, 3, GL_STATIC_DRAW);

  graphics::shader basicShader("shaders/basic.glsl");

  while (window.is_open())
  {
    window.clear();

    basicShader.use();
    va.bind();

    glDrawElements(GL_TRIANGLES, (int)vertices.size(), GL_UNSIGNED_INT, nullptr);

    window.update();
  }

  window.close();

  return 0;
}
