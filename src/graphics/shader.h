#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#pragma once

#include <fstream>
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../errors/error.h"
#include "../logger/logger.h"

namespace graphics
{
  class shader
  {
  private:
    unsigned int m_Id;

    std::string m_Vertex;

    std::string m_Fragment;

    unsigned int compile(unsigned int type, const std::string &source);

  public:
    explicit shader(const std::string &filePath);

    /**
     * @brief Binds the shader.
     */
    void use() const;

    /**
     * @brief Gets the shader identifier.
     * @return the identifier.
     */
    unsigned int get_id() const;

    /**
     * @brief Sets an uniform bool value.
     * @param name the uniform name.
     * @param value the uniform value.
     */
    void set_bool(const std::string &name, bool value) const;

    /**
     * @brief Sets an uniform int value.
     * @param name the uniform name.
     * @param value the uniform value.
     */
    void set_int(const std::string &name, int value) const;

    /**
     * @brief Sets an uniform float value.
     * @param name the uniform name.
     * @param value the uniform value.
     */
    void set_float(const std::string &name, float value) const;

    /**
     * @brief Sets an uniform mat4 value.
     * @param name the uniform name.
     * @param value the uniform value.
     */
    void set_mat4(const std::string &name, const glm::mat4 &value) const;
  };
}

#endif
