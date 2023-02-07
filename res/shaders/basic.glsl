#version 330 core

#ifdef COMPILING_VERTEX_SHADER

layout (location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1.0);
}

#endif

#ifdef COMPILING_FRAGMENT_SHADER

layout (location = 0) out vec4 color;

void main()
{
    color = vec4(1.0f, 0.5f, 0.3f, 1.0f);
}

#endif
