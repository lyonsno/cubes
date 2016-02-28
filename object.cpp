#include "object.h"

Object::Object(const Geometry& geometry) : geometry(geometry)
{
	modelMatrix = glm::mat4();
}

const glm::mat4& Object::getModelMatrix() const
{
	return modelMatrix;
}

const Geometry& Object::getGeometry() const
{
	return geometry;
}

void Object::rotate(float degrees, glm::vec3 axis)
{
	modelMatrix = glm::rotate(modelMatrix, degrees, axis);
}
