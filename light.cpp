#include "light.h"

Light::Light() : position(glm::vec3(0,0,0)) {}

Light::Light(glm::vec3 position) : position(position) {}

const glm::vec3& Light::getPosition() const
{
	return position;
}