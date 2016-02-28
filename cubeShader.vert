#version 410
precision highp float;

in vec3 in_Position;
in vec3 in_Normal;

out vec3 interpPosition;
out vec3 interpNormal;

uniform mat4 mvp;
// uniform vec3 lightPosition;
// uniform vec3 eyePosition;

void main() 
{ 
	interpPosition = in_Position;
	mat4 normalMatrix = transpose(inverse(mvp));
	vec4 projectedNormal = (normalMatrix * vec4(in_Normal,0.0));
	interpNormal = projectedNormal.xyz;
	vec4 projectedPosition =  mvp * vec4(in_Position, 1.0);
	interpPosition = projectedPosition.xyz;
	gl_Position = projectedPosition;
}