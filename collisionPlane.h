#ifndef CollisionPlane_H
#define CollisionPlane_H

#include "glm/glm/glm.hpp"
#include "camera.h"
#include <iostream>
#include <math.h>

class CollisionPlane
{
private:
	float depth;
	Camera* camera;
public:
	CollisionPlane();
	CollisionPlane(float depth, Camera* camera);
	glm::vec4 worldFromScreenCoords(float winX, float winY);
	glm::vec4 cameraRayIntersection(glm::vec3 ray, glm::vec3 p0);
};
#endif