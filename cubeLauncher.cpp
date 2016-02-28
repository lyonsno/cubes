#include "cubeLauncher.h"

CubeLauncher::CubeLauncher()
{
	
}

void CubeLauncher::addTarget(const vec3& target)
{
	targets.push_back(target);
}

void CubeLauncher::launchCubes()
{
	for (auto& target : targets)
	{
		lauchCube(target);
	}
}

void CubeLauncher::launchCube(const vec3& target)
{
	Object cube = Object(cubeData);
	
}