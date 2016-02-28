#ifndef Projectile_H
#define Projectile_H

class Projectile : public Object
{
private:
	glm::vec3 acceleration;
	glm::vec3 velocity;
	glm::vec3 target;
	int children;
	float timeStep;

public:
	Projectile(const Geometry& geometry);
	step(double timeStep);
	const glm::vec3& getTarget();
};
#endif