#include <vector>
#include <memory>

#include "src/graphics/window.h"
#include "src/graphics/vertex.h"
#include "src/graphics/shader.h"
#include "src/graphics/texture.h"
#include "src/graphics/mesh.h"

int main()
{
  graphics::window window(1080, 720, "OpenGL");
  window.open();

  std::vector<graphics::vertex> vertices = {
      {{-0.5f, -0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
      {{0.5f, -0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
      {{0.5f, 0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
      {{-0.5f, 0.5f, 0.5f}, {1.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},

      {{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
      {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
      {{0.5f, 0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
      {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
  };

  std::vector<unsigned int> indices = {
      0, 1, 2,
      2, 3, 0,
      1, 5, 6,
      6, 2, 1,
      7, 6, 5,
      5, 4, 7,
      4, 0, 3,
      3, 7, 4,
      4, 5, 1,
      1, 0, 4,
      3, 2, 6,
      6, 7, 3};

  graphics::shader basicShader("shaders/basic.glsl");
  graphics::texture basicTexture("textures/basic.jpg");

  graphics::mesh mesh(vertices, indices, basicTexture);

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

    const float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;

    glm::mat4 view;
    view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, -3.0), glm::vec3(0.0, 1.0, 0.0));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float)window.get_width() / window.get_height(), 0.1f, 100.0f);

    basicShader.set_mat4("view", view);
    basicShader.set_mat4("projection", projection);

    for (int i = 0; i < 10; i++)
    {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, positions[i]);
      model = glm::rotate(model, glm::radians(20.0f * i), glm::vec3(1.0f, 0.3f, 0.5f));

      basicShader.set_mat4("model", model);

      mesh.draw(basicShader);
    }

    window.update();
  }

  window.close();

  return 0;
}
