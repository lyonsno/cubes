#ifndef CubeLauncher_H
#define CubeLauncher_H

class CubeLauncher
{
private:
	std::vector<glm::vec3 &> targets;
public:
	CubeLauncher();
	void addTarget(const vec3& target);
	void lauchCubes();
	void lauchCube(const vec3& target);
};

#endif