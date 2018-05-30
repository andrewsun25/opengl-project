#shader vertex
#version 330 core

// Called once for each vertex in the VBO.
// aPos is an input vec3 variable initialized with the data from the 0th attribute of a given vertex (position)
layout(location = 0) in vec3 in_pos;
layout(location = 1) in vec2 in_texCoords;
out vec2 v_texCoords;
// Projection matrix
uniform mat4 u_proj;
uniform mat4 u_model;

void main()
{
	gl_Position = u_proj * u_model * vec4(in_pos, 1.0);
	v_texCoords = in_texCoords;
};

// FRAGMENT SHADER --------------

#shader fragment
#version 330 core

in vec2 v_texCoords;
out vec4 o_color;
uniform sampler2D u_texID;
uniform vec4 u_spriteRGBA;
// texture looks up the texture mapped to image and returns its normalized color vec4
// operator* performs component wise multiplication
void main()
{
	o_color = u_spriteRGBA * texture(u_texID, v_texCoords);
};