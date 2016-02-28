#ifndef Light_H
#define Light_H
#endif

#include "glm/glm/glm.hpp"
class Light
{
private:
	glm::vec3 position;
public:
	Light();
	Light(glm::vec3 position);
	const glm::vec3& getPosition() const;
};