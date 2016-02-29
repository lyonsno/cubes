#include "cubeLauncher.h"

CubeLauncher::CubeLauncher(double timestep) 
: position(glm::vec3(0.0,0.0,0.0)), timestep(timestep) 
{
	
}

void CubeLauncher::quebe(Projectile cube)
{
	cubes.push_back(cube);
}

void CubeLauncher::launchCubes()
{
	// if (launching) return;
	std::cout<<cubes.size()<<std::endl;
	launching = true;
	for (auto& cube : cubes)
	{
		if ( !cube.hasLaunched() ) cube.launch(position);

	}
}

bool CubeLauncher::isLaunching()
{
	return launching;
}

 std::vector<Projectile>& CubeLauncher::getCubes()
{
	return cubes;
}

void CubeLauncher::step()
{
	for (auto& cube : cubes)
	{
		if (cube.hasLaunched())
		{
			cube.step(timestep);
		}
		if (cube.hasDetonated())
		{
			for (int i = 0; i < cube.getNumChildren(); i++)
			{
				explosions.push_back(Shard(cube.getGeometry()));
				
			}
		}
	}

	cubes.erase(
		std::remove_if(
			cubes.begin(), cubes.end(),
			 [](Projectile cube){ return cube.hasDetonated(); }),
		 cubes.end());

	if ( cubes.empty() )
	{
		launching = false;
	}
}