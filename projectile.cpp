#include "projectile.h"

Projectile::Projectile(const Geometry& geometry, int children)
: Object(geometry), acceleration(glm::vec3(0.0,-1.0,0.0)), velocity(glm::vec4(0.0)), 
  children(children)
{

}

void Projectile::step(double timeStep)
{
	timeStep += timeStep;
	position += timeStep * (velocity + timestep * acceleration / 2.0);
	velocity += timeStep * acceleration;
}
