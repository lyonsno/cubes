#ifndef Shard_H
#define Shard_H

#include "glm/glm/glm.hpp"
#include "object.h"

class Shard : public Object
{
private:
	glm::vec3 acceleration;
	glm::vec3 velocity;
	bool detonated;
public:
	Shard(const Geometry& geometry);
	void step(float timestep);
	void detonate();
	bool hasDetonated();
};
#endif