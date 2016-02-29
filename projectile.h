#ifndef Projectile_H
#define Projectile_H

#include "glm/glm/glm.hpp"
#include <math.h>
#include <iostream>
#include "object.h"
class Projectile : public Object
{
private:
	Object target;
	glm::vec3 acceleration;
	glm::vec3 velocity;
	float timestep;
	float V;
	int children;
	bool detonated;
	bool launched;
	float G;
	float PI;
	float delta;

public:
	Projectile(const Geometry& geometry, int children, Object target);
	void step(float _timestep);
	float calculateLaunchAngle();
	Object& getTarget();
	int getNumChildren();
	void launch(glm::vec3 start);
	void setVelocityVector(float degrees);
	void detonate();
	bool hasDetonated();
	bool hasLaunched();

};
#endif