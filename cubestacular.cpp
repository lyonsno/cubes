#include "cubestacular.h"

Cubestacular::Cubestacular()
{	
    std::cout<<"made it to cubestacular constructor"<<std::endl;
	cubeData = Cube();
    Object cube = Object(cubeData, glm::vec3(0,0,0));
	cubes.push_back(cube);
	camera = Camera(glm::vec3(0.0, 0.0, -8.0), glm::vec3(0.0,0.0,1.0),glm::vec3(0.0,1.0,0.0),
                                  							  45.0f, 0.1f, 20.0f);
    collisionPlane = CollisionPlane(1.0, &camera);
	shaderCreator = ShaderCreator();
	Light myLight = Light();
    std::cout<<"made it through cubestacular constructor"<<std::endl;
}

void Cubestacular::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(cubeVAOId);
    for (auto& cube : cubes)
    {   
        cube.tumble(0.002);
        glUniformMatrix4fv(camera.VPloc, 1, GL_FALSE, &(camera.getVPMatrix() * cube.getModelMatrix())[0][0]);
        // glUniform3fv(lightPosLoc, 1, &myLight->getPosition()[0]);
        glDrawArraysInstanced(GL_TRIANGLES, 0, 36, 1);    
    }
}

void Cubestacular::initGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    initBuffers();
    initShaders();
}

void Cubestacular::initBuffers()
{
	const std::vector<glm::vec3>& vertices = cubes[0].getGeometry().getVertices();
    const std::vector<VertexAttribute>& vertexAttributes = cubes[0].getGeometry().getAttributes();

    glGenBuffers(1, &cubeBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, cubeBufferId);
    glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(VertexAttribute), &vertexAttributes[0], GL_STATIC_DRAW);

    glGenVertexArrays(1, &cubeVAOId);
    glBindVertexArray(cubeVAOId);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, cubeBufferId);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (void*)12);    
}

void Cubestacular::initShaders()
{
    shaderProgram = shaderCreator.loadShader("cubeShader.vert", "cubePhong.frag");
    camera.VPloc = glGetUniformLocation(shaderProgram, "mvp");
    // GLuint lightPosLoc = glGetUniformLocation(shaderprogram, "lightPosition");
    // GLuint eyePosLoc = glGetUniformLocation(shaderprogram, "eyePosition");
    glUseProgram(shaderProgram);
}

void Cubestacular::handleMouseDown(double xpos, double ypos)
{
    glm::vec4 worldPoint = collisionPlane.worldFromScreenCoords(xpos, ypos);
    cubes.push_back(Object(cubeData, glm::vec3(worldPoint)));
}

void Cubestacular::handleWindowResize(int width, int height)
{
    camera.updateWindowSize(width, height);
}