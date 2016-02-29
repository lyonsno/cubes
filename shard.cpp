#include "shard.h"

Shard::Shard(const Geometry& geometry)
: Object(geometry), acceleration(glm::vec3(0.0, -9.8, 0.0)), velocity(glm::vec3(0.0)),
  detonated(false)
{
	
}

void Shard::step(float timestep)
{

	if ( position.y < 6.0f )
	{
		detonate();
		return;
	}

	glm::vec3 temp = position;
	glm::vec3 tempV = velocity;
	velocity += acceleration * timestep;
	position += velocity * timestep;
}

void Shard::detonate()
{
	detonated = true;
}

bool Shard::hasDetonated()
{
	return detonated;
}
