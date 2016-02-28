#ifndef ShaderCreator_H
#define ShaderCreator_H

#include <OpenGL/gl3.h>
#include <stdio.h>
#include <iostream>

class ShaderCreator
{
private:
	static char* filetobuf(char *file);
public:
	ShaderCreator();
	GLuint loadShader(char* vert, char* frag);
};	

#endif