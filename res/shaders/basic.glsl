#version 330 core

#ifdef COMPILING_VERTEX_SHADER

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vColor;
out vec2 vTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPosition, 1.0);
    vColor = aColor;
    vTexCoord = aTexCoord;
}

#endif

#ifdef COMPILING_FRAGMENT_SHADER

out vec4 color;

in vec3 vColor;
in vec2 vTexCoord;

uniform sampler2D uTexture;

void main()
{
    vec2 uv = vec2(vTexCoord.x + 0.5, vTexCoord.y + 0.5);
    color = texture(uTexture, uv);
}

#endif
