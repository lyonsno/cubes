#ifndef Cubestacular_H
#define Cubestacular_H

#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
// #include "massIncludes.h"
#include "camera.h"
#include "cube.h"
#include "shaderCreator.h"
#include "light.h"
#include "object.h"

class Cubestacular
{
private:
	ShaderCreator shaderCreator;
public:
	Cubestacular();
	Cube cubeData;
	std::vector<Object> cubes;
	Camera camera;
	Light light;
	GLuint shaderProgram;
	GLuint cubeBufferId;
	GLuint cubeVAOId;

	void draw();
	void initGL();
	void initBuffers();
	void initShaders();
};
#endif