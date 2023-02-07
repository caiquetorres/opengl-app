#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#pragma once

#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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
  };
}

#endif