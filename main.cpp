#include <vector>
#include <memory>
#include <cmath>

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

  float rotation[] = {0.0, 0.0, 0.0};
  float position[] = {0.0, 0.0, 0.0};

  while (window.is_open())
  {
    window.clear();

    glm::mat4 view;
    view = glm::lookAt(glm::vec3(3, 0.0, 3), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 10.0, 0.0));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float)window.get_width() / window.get_height(), 0.1f, 100.0f);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position[0], position[1], position[2]));

    model = glm::rotate(model, glm::radians(rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));

    basicShader.set_mat4("view", view);
    basicShader.set_mat4("projection", projection);
    basicShader.set_mat4("model", model);

    mesh.draw(basicShader);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

    ImGui::Begin("Tool");

    ImGui::SliderFloat3("rotation", rotation, 0, 360);
    ImGui::DragFloat3("position", position, 0);

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    window.update();
  }

  window.close();

  return 0;
}
