#include "cube.h"

Cube::Cube()
{
    //Triangle A
    vertices.push_back(glm::vec3(1.0f,1.0f,1.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,1.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,0.0f));
    normals.push_back(glm::vec3(0.0f,1.0f,0.0f));
    //Triangle B
    vertices.push_back(glm::vec3(1.0f,1.0f,1.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,0.0f));
    vertices.push_back(glm::vec3(1.0f,1.0f,0.0f));
    normals.push_back(glm::vec3(0.0f,1.0f,0.0f));
    //Triagle C
    vertices.push_back(glm::vec3(1.0f,1.0f,1.0f));
    vertices.push_back(glm::vec3(1.0f,0.0f,1.0f));
    vertices.push_back(glm::vec3(0.0f,0.0f,1.0f));
    normals.push_back(glm::vec3(0.0f,0.0f,1.0f));
    //Triangle D
    vertices.push_back(glm::vec3(1.0f,1.0f,1.0f));
    vertices.push_back(glm::vec3(0.0f,0.0f,1.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,1.0f));
    normals.push_back(glm::vec3(0.0f,0.0f,1.0f));
    //Triangle E
    vertices.push_back(glm::vec3(0.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(0.0f,0.0f,1.0f));
    vertices.push_back(glm::vec3(1.0f,0.0f,0.0f));
    normals.push_back(glm::vec3(0.0f,-1.0f,0.0f));
    //Triangle F
    vertices.push_back(glm::vec3(1.0f,0.0f,1.0f));
    vertices.push_back(glm::vec3(1.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(0.0f,0.0f,1.0f));
    normals.push_back(glm::vec3(0.0f,-1.0f,0.0f));
    //Triangle G
    vertices.push_back(glm::vec3(0.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(1.0f,1.0f,0.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,0.0f));
    normals.push_back(glm::vec3(0.0f,0.0f,-1.0f));
    //Triagle H
    vertices.push_back(glm::vec3(0.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(1.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(1.0f,1.0f,0.0f));
    normals.push_back(glm::vec3(0.0f,0.0f,-1.0f));
    //Triangle I
    vertices.push_back(glm::vec3(0.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,0.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,1.0f));
    normals.push_back(glm::vec3(-1.0f,0.0f,0.0f));
    //Triangle J
    vertices.push_back(glm::vec3(0.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(0.0f,1.0f,1.0f));
    vertices.push_back(glm::vec3(0.0f,0.0f,1.0f));
    normals.push_back(glm::vec3(-1.0f,0.0f,0.0f));
    //Triangle K
    vertices.push_back(glm::vec3(1.0f,1.0f,1.0f));
    vertices.push_back(glm::vec3(1.0f,1.0f,0.0f));
    vertices.push_back(glm::vec3(1.0f,0.0f,1.0f));
    normals.push_back(glm::vec3(1.0f,0.0f,0.0f));
    //Triagle L
    vertices.push_back(glm::vec3(1.0f,0.0f,0.0f));
    vertices.push_back(glm::vec3(1.0f,0.0f,1.0f));
    vertices.push_back(glm::vec3(1.0f,1.0f,0.0f));
    normals.push_back(glm::vec3(1.0f,0.0f,0.0f));

    Geometry::populateAttributes();

}