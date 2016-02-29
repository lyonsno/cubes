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
#include "cubeLauncher.h"
#include "projectile.h"

class Cubestacular
{
private:
	ShaderCreator shaderCreator;
	CubeLauncher launcher;
	int children;
	double lastTime;
	double elapsedTime;
	double timeStep;
public:
	Cubestacular();
	Cube cubeGeometry;
	std::vector<Object> targets;
	CollisionPlane collisionPlane;
	Camera camera;
	Light light;



	GLuint shaderProgram;
	GLuint cubeBufferId;
	GLuint cubeVAOId;

	void draw();
	void stepSim();
	
	//init
	void initGL();
	void initBuffers();
	void initShaders();

	//get/set
	void setLastTime(double now);
	double getLastTime();
	void increaseElapsed(double step);
	double getElapsed();
	void resetElapsed();
	double getTimeStep();

	//UI
	void handleMouseDown(double xpos, double ypos);
	void handleWindowResize(int width, int height);
	void handleKeyPress();
};
#endif