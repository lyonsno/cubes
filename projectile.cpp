#include "projectile.h"

Projectile::Projectile(const Geometry& geometry, int children, Object target)
: Object(geometry), acceleration(glm::vec3(0.0, -9.8,0.0)), velocity(glm::vec3(0.0)), 
  children(children), target(target), launched(false), detonated(false), V(20.0f),
  G(-9.81), timestep(0.0), PI(3.1415926535f), delta(0.5f)
{

}

void Projectile::detonate()
{
	detonated = true;

}

void Projectile::step(float _timestep)
{
	if ( position.z > 50.0f ) {
		detonated = true;
	}
	glm::vec3 distanceToTarget = position - target.getPosition();
	if (glm::length(distanceToTarget) < delta)
	{
		detonate();
		return;
	}

	glm::vec3 temp = position;
	glm::vec3 tempV = velocity;
	velocity += acceleration * _timestep;
	position += velocity * _timestep;
}

Object& Projectile::getTarget()
{
	return target;
}

int Projectile::getNumChildren()
{
	return children;
}

float Projectile::calculateLaunchAngle()
{
	glm::vec3 targetPos = target.getPosition();
	float x = targetPos.z;
	float y = targetPos.y;
	float z = targetPos.x;
	double preRoot = (pow(V, 4.0) - (G * (pow(G*x, 2.0) + pow(2.0 * y * V, 2.0))));
	double root = std::sqrt(preRoot);

	double point1 = ( V*V + std::abs(root) ) / ( G * x );
	double theta1 = atan(point1);
	// double theta2 = atan(point2);

	// if (theta1 <= 0.0 ) return theta2;

	return theta1;
}

bool Projectile::hasDetonated()
{
	return detonated;
}

void Projectile::launch( glm::vec3 start)
{
	position = start;
	float angle = calculateLaunchAngle();
	setVelocityVector(angle);
	launched = true;
}

void Projectile::setVelocityVector(float degrees)
{
	float rads = degrees * float(PI) / 180.0f;
	glm::vec3 vector = glm::vec3(0.0f, sin(rads), cos(rads));
	vector = glm::normalize(vector);
	vector = V * vector;
	velocity = vector;
	glm::vec3 fakeTarget = target.getPosition();
	fakeTarget.y += 5.0f;
	velocity = fakeTarget - position;
}

bool Projectile::hasLaunched()
{
	return launched;
}