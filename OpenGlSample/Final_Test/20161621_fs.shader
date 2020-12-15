#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;

in vec3 fragmentColor;

out vec3 color;

uniform sampler2D myTextureSampler;

void main()
{
	color = texture(myTextureSampler, UV).rgb;
}