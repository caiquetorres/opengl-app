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

  glm::vec3 positions[] = {
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(2.0f, 5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f),
      glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3(2.4f, -0.4f, -3.5f),
      glm::vec3(-1.7f, 3.0f, -7.5f),
      glm::vec3(1.3f, -2.0f, -2.5f),
      glm::vec3(1.5f, 2.0f, -2.5f),
      glm::vec3(1.5f, 0.2f, -1.5f),
      glm::vec3(-1.3f, 1.0f, -1.5f)};

  while (window.is_open())
  {
    window.clear();

    va.bind();
    basicShader.use();

    const float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;

    glm::mat4 view;
    view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, -3.0), glm::vec3(0.0, 1.0, 0.0));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float)window.get_width() / window.get_height(), 0.1f, 100.0f);

    basicShader.set_mat4("view", view);
    basicShader.set_mat4("projection", projection);

    for (unsigned int i = 0; i < 10; i++)
    {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, positions[i]);
      model = glm::rotate(model, glm::radians(20.0f * i), glm::vec3(1.0f, 0.3f, 0.5f));
      basicShader.set_mat4("model", model);

      glDrawElements(GL_TRIANGLES, (int)vertices.size(), GL_UNSIGNED_INT, nullptr);
    }

    window.update();
  }

  window.close();

  return 0;
}
