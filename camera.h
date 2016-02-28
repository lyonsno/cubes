#ifndef Camera_H
#define Camera_H

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

class  Camera
{
private:

	float fov;
	glm::mat4 VPmatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	float clipNear;
	float clipFar;

public:
	Camera();
	Camera(glm::vec3 eye, glm::vec3 center, glm::vec3 up, float fov=45.0f, float clipNear=0.2f, float clipFar=1.0f);
	glm::mat4 getVPMatrix();
	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix();
	GLuint VPloc;
};
#endif