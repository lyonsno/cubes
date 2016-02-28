#ifndef Object_H
#define Object_H

#include "glm/glm/glm.hpp"
#include "geometry.h"

class Object
{
	private:
		glm::mat4 modelMatrix;
		glm::vec3 axis;
		glm::vec3 position;
		glm::mat4 rotationMatrix;
		const Geometry& geometry;

	public:
		Object(const Geometry& geometry);
		Object(const Geometry& geometry, glm::vec3 position);
		const glm::mat4& getModelMatrix();
		const Geometry& getGeometry() const;
		const glm::vec3& getPosition();
		void updateModelMatrix();
		void tumble(float degrees);
		void rotate(float degrees);
};

#endif