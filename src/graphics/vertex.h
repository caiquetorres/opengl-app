#ifndef OPENGL_VERTEX_H
#define OPENGL_VERTEX_H

#pragma once

#include <glm/glm.hpp>

namespace graphics
{
  struct vertex
  {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
  };
}

#endif
