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
#include "collisionPlane.h"

class Cubestacular
{
private:
	ShaderCreator shaderCreator;
	double lastTime;
	double elapsedTime;
	double timeStep;
public:
	Cubestacular();
	Cube cubeData;
	std::vector<Object> cubes;
	CollisionPlane collisionPlane;
	Camera camera;
	Light light;


	GLuint shaderProgram;
	GLuint cubeBufferId;
	GLuint cubeVAOId;

	void draw();

	//init
	void initGL();
	void initBuffers();
	void initShaders();

	//get/set
	double setLastTime(double now);
	void increaseElapsed(double step);
	double getElapsed();
	void resetElapsed();

	//UI
	void handleMouseDown(double xpos, double ypos);
	void handleWindowResize(int width, int height);
};
#endif