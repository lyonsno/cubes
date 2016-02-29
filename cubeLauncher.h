#ifndef CubeLauncher_H
#define CubeLauncher_H

#include "glm/glm/glm.hpp"
#include "projectile.h"
#include <iostream>
#include <algorithm>

class CubeLauncher
{
private:
	std::vector<Projectile> cubes;
	glm::vec3 position;
	double timestep;
	bool launching;

public:
	CubeLauncher(double timestep);
	//get it? we're queing it.
	void quebe(Projectile cube);
	void launchCubes();
	void step();
	std::vector<Projectile>& getCubes();
	bool isLaunching();
};

#endif