#include "object.h"

Object::Object(const Geometry& geometry) : geometry(geometry), position(glm::vec3()), modelMatrix(glm::mat4()), axis(glm::vec3(0,1,0))
{

}

Object::Object(const Geometry& geometry, glm::vec3 position) : geometry(geometry), position(position), modelMatrix(glm::mat4()), axis(glm::vec3(0,1,0))
{

}

const glm::mat4& Object::getModelMatrix()
{
	updateModelMatrix();
	return modelMatrix;
}

void Object::updateModelMatrix()
{
	modelMatrix = glm::translate(glm::mat4(), position) * rotationMatrix;
}

const Geometry& Object::getGeometry() const
{
	return geometry;
}

const glm::vec3& Object::getPosition()
{
	return position;
}

void Object::tumble(float degrees)
{
	glm::mat4 rotationMat = glm::rotate(glm::mat4(), degrees, glm::vec3(1.0, 0.2, 0.5));
	axis = glm::vec3(rotationMat * glm::vec4(axis, 1.0));
	rotate(degrees*20);
}
void Object::rotate(float degrees)
{
	rotationMatrix = glm::rotate(rotationMatrix, degrees, axis);
}
