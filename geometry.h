#ifndef Geometry_H
#define Geometry_H

#include <vector>
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "vertexAttribute.h"

class Geometry
{
protected:
	std::vector <glm::vec3> vertices;
	std::vector <glm::vec3> normals;
	std::vector<VertexAttribute> attributes;
	void populateAttributes();

public:
	Geometry();
	const std::vector<glm::vec3>& getVertices()const;
	const std::vector<glm::vec3>& getNormals()const;
	const std::vector<VertexAttribute>& getAttributes()const;
};

#endif