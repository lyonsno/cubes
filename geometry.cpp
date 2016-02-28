#include "geometry.h"

Geometry::Geometry()
{

}

void Geometry::populateAttributes()
{
	int triangleIndex = 0;
	for (auto &vert : vertices)
	{
		VertexAttribute attrib = VertexAttribute();
		attrib.vertex = vert;
		attrib.normal = normals[triangleIndex/3];
		attributes.push_back(attrib);
		triangleIndex++;
	}
}

const std::vector<glm::vec3>& Geometry::getVertices() const
{
	return vertices;
}

const std::vector<glm::vec3>& Geometry::getNormals() const
{
	return normals;
}

const std::vector<VertexAttribute>& Geometry::getAttributes() const
{
	return attributes;
}

