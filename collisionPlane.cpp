#include "collisionPlane.h"

CollisionPlane::CollisionPlane() : depth(10), camera(new Camera()){}

CollisionPlane::CollisionPlane(float depth, Camera* camera) : depth(depth), camera(camera)
{

}

glm::vec4 CollisionPlane::worldFromScreenCoords(float winX, float winY)
{
	std::cout<<"getWorld"<<std::endl;
	float aspect = float(camera->getClientWidth()) / float(camera->getClientHeight());
	std::cout<<"aspect: "<<aspect<<std::endl;
	// float normX = (winX / camera->getClientWidth()) -0.5f;
	// float normY = -1.0 * ((winY / camera->getClientHeight()) -0.5f);

	// glm::vec3 imagePoint = normX * camera->getRight() + normY * camera->getUp() + camera->getPosition() + camera->getDirection();
	// std::cout<<imagePoint.x<<","<<imagePoint.y<<","<<imagePoint.z<<std::endl;
	// glm::vec3 rayDirection = imagePoint - camera->getPosition();
	// std::cout<<rayDirection.x<<","<<rayDirection.y<<","<<rayDirection.z<<std::endl;


	float halfWidth = camera->getClientWidth() / 2.0;
	float halfHeight = camera->getClientHeight() / 2.0;
	double x = tanf(camera->getFov() * 0.5f) * (-(winX / halfWidth) + 1.0f ) * aspect;
	double y = tanf(camera->getFov() * 0.5f) * (-1.0f + (winY / halfHeight));

	// float x = (2.0 * winX / camera->getClientWidth()) -1.0;
	// float y = (-2.0 * winY / camera->getClientHeight()) + 1.0;
	// glm::vec4 worldPosition = glm::vec4(x, y, 0.01, 1.0);
	// std::cout<<worldPosition.x<<","<<worldPosition.y<<","<<worldPosition.z<<std::endl;

	// glm::mat4 invVPMat = glm::inverse(camera->getProjectionMatrix() * camera->getViewMatrix());
	// worldPosition = worldPosition * invVPMat;
	// worldPosition /= worldPosition.w;
	// // glm::vec4 finalPosition = glm::vec4(worldPosition.x / worldPosition.w, worldPosition.y / worldPosition.w, depth, 1.0);
	// std::cout<<worldPosition.x<<","<<worldPosition.y<<","<<worldPosition.z<<std::endl;
	// return worldPosition;



	float near = camera->getNear();
	float far = camera->getFar();

	glm::vec3 pNear = glm::vec3(x * near, y * near, near);
	glm::vec3 pFar = glm::vec3(x * far, y * far, far);

	glm::mat4 viewProjectionInverse =  glm::inverse(camera->getViewMatrix());
	
	pNear = glm::vec3(glm::vec4(pNear, 1.0) * viewProjectionInverse);
	pFar = glm::vec3(glm::vec4(pFar, 1.0) * viewProjectionInverse);

	// pNear = glm::vec3(glm::vec4(camera->getPosition(), 1.0) * viewProjectionInverse);
	glm::vec3 ray = pFar - pNear;
	return cameraRayIntersection(ray, camera->getPosition());

	// glm::vec4 dir = glm::transpose(viewProjectionInverse) * glm::vec4(x, y, 1, 1);
	// // dir /= viewProjectionInverse[3] + viewProjectionInverse[7] + viewProjectionInverse[11] + viewProjectionInverse[15];
	// dir -= glm::vec4(camera->getPosition(), 1.0);
	// float factor = depth / dir.z;
	// glm::vec3 point = glm::vec3(dir.x * factor, dir.y * factor, dir.z * factor);
	// // glm::vec4 point = glm::vec4(winX,winY,0.5,1);
	// // glm::vec4 temp = viewProjectionInverse * point;
	// std::cout<<point.x<<","<<point.y<<","<<point.z<<std::endl;
	// return glm::vec4(point, 1);
}

glm::vec4 CollisionPlane::cameraRayIntersection(glm::vec3 ray, glm::vec3 p0)
{
	ray = glm::normalize(ray);
	float t = ( -1 * (glm::dot(p0, glm::vec3(0,0,-1)) + depth) ) / (glm::dot(ray, glm::vec3(0.0,0.0,-1.0)));
	glm::vec3 temp = p0 + t * ray;
	std::cout<<temp.x<<","<<temp.y<<","<<temp.z<<std::endl;
	return glm::vec4(p0 + (t * ray), 1.0);
}
