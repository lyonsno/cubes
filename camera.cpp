#include "camera.h"

Camera::Camera()
{
	viewMatrix = glm::lookAt(glm::vec3(0,0,-1),glm::vec3(),glm::vec3(0,1,0));
	projectionMatrix = glm::perspective(45.0f, (float)640/480, 0.1f, 50.0f);
	VPmatrix = projectionMatrix * viewMatrix;
	VPloc = 0;
}
Camera::Camera(glm::vec3 eye, glm::vec3 center, glm::vec3 up, float fov, float clipNear, float clipFar): fov(fov), clipNear(clipNear), clipFar(clipFar)
{
	viewMatrix = glm::lookAt(eye, center, up);
	projectionMatrix = glm::perspective(fov, (float)640/480, clipNear, clipFar);
	VPmatrix = projectionMatrix * viewMatrix;
	VPloc = 0;
}

glm::mat4 Camera::getVPMatrix()
{
	return VPmatrix;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return projectionMatrix;
}


glm::mat4 Camera::getViewMatrix()
{
	return viewMatrix;
}
