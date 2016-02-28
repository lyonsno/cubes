#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "cubestacular.h"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout<<"mouse: "<<xpos<<", "<<ypos<<std::endl;

    }
}

int main()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    
    Cubestacular* game = new Cubestacular();

    game->initGL();
   

    bool running = true;
    float xAxis = 0;
    bool grow = true;
    while (!glfwWindowShouldClose(window))
    {
        // rotation code
        if (grow) xAxis++;
        else xAxis--;
        game->cubes[0].rotate(0.05, glm::vec3(fmod(xAxis/100.0,1.0),1,0));
        if (xAxis >= 100.0) grow = false;
        if (xAxis <= 1.0) grow = true;
    	
    	game->draw();
        // end the current frame (internally swaps the front and back buffers)
        glfwSwapBuffers(window);
        glfwPollEvents();
        if (glfwGetKey (window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose (window, 1);
        }
    }
    // glDeleteBuffers(1, &cubeBufferId);

    // release resources...
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}