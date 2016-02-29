#ifndef CubeLauncher_H
#define CubeLauncher_H

#include "glm/glm/glm.hpp"
#include "projectile.h"
#include <iostream>
#include <algorithm>
#include "shard.h"

class CubeLauncher
{
private:
	std::vector<Projectile> cubes;
	std::vector<Shard> explosions;
	glm::vec3 position;
	double timestep;
	bool launching;

public:
	CubeLauncher(double timestep);
	//get it? we're queing it..h
	void quebe(Projectile cube);
	void launchCubes();
	void step();
	std::vector<Projectile>& getCubes();
	bool isLaunching();
};

#endif