#include "camera.h"

Camera::Camera()
{
	clipNear = 1.0;
	clipFar = 20.0;
	clientWidth = 640;
	clientHeight = 480;
	center = glm::vec3();
	position = glm::vec3(0,0,-1);
	up = glm::vec3(0,1,0);
	fov = 45.0f;
	viewMatrix = glm::lookAt(position,center,up);
	projectionMatrix = glm::perspective(45.0f, float(640)/float(480), 1.0f, 50.0f);
	VPmatrix = projectionMatrix * viewMatrix;
	VPloc = 0;
}
Camera::Camera(glm::vec3 eye, glm::vec3 center, glm::vec3 up, float fov, float clipNear, float clipFar): fov(fov), clipNear(clipNear), clipFar(clipFar)
{
	clientWidth = 640;
	clientHeight = 480;
	position = eye;
	center = center;
	up = up;
	direction = glm::normalize(center - eye);
	right = glm::cross(direction, up);
	// up = glm::cross(right, direction);
	fov = fov;
	viewMatrix = glm::lookAt(eye, center, up);
	projectionMatrix = glm::perspective(fov, float(clientWidth)/float(clientHeight), clipNear, clipFar);
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

glm::vec3 Camera::getPosition()
{
	return position;
}

glm::vec3 Camera::getDirection()
{
	return direction;
}

glm::vec3 Camera::getRight()
{
	return right;
}

glm::vec3 Camera::getUp()
{
	return up;
}

float Camera::getNear()
{
	return clipNear;
}

float Camera::getFar()
{
	return clipFar;
}

float Camera::getFov()
{
	return fov;
}
const int Camera::getClientWidth()
{
	return clientWidth;
}

const int Camera::getClientHeight()
{
	return clientHeight;
}

void Camera::updateWindowSize(int width, int height)
{
	clientWidth = width;
	clientHeight = height;
	projectionMatrix = glm::perspective(fov, float(clientWidth)/(float(clientHeight)), clipNear, clipFar);
	VPmatrix = projectionMatrix * viewMatrix;
}
