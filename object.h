#ifndef Object_H
#define Object_H

#include "glm/glm/glm.hpp"
#include "geometry.h"

class Object
{
	private:
		glm::mat4 modelMatrix;
		const Geometry& geometry;

	public:
		Object(const Geometry& geometry);	
		const glm::mat4& getModelMatrix() const;
		const Geometry& getGeometry() const;
		void rotate(float degrees, glm::vec3 axis);
};

#endif