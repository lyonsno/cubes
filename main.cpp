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
    Cubestacular * game = reinterpret_cast<Cubestacular *>(glfwGetWindowUserPointer(window));
    game->handleKeyPress();
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout<<"mouse: "<<xpos<<", "<<ypos<<std::endl;
        Cubestacular * game = reinterpret_cast<Cubestacular *>(glfwGetWindowUserPointer(window));
        game->handleMouseDown(xpos, ypos);
    }
}

static void window_size_callback(GLFWwindow* window, int width, int height)
{
	std::cout<<width<<"::"<<height<<std::endl;
    Cubestacular * game = reinterpret_cast<Cubestacular *>(glfwGetWindowUserPointer(window));
    game->handleWindowResize(width, height);
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
    glfwSetWindowSizeCallback(window, window_size_callback);
    
    Cubestacular game = Cubestacular();

    // initialize objects buffers and shaders 
    game.initGL();
    std::cout<<"GL initiated"<<std::endl;
    // set pointer for UI callbacks
   	glfwSetWindowUserPointer(window, &game);

    bool running = true;
    while (!glfwWindowShouldClose(window))
    {
    	double now = glfwGetTime();
        double delta = now - game.getLastTime();
        game.setLastTime(now);

        game.increaseElapsed(delta);

        while(game.getElapsed() >= game.getTimeStep()) // OPTIMAL_TIME = 1 / 60
        {
                 //tick
        		game.stepSim();
                game.resetElapsed();
        }
    	game.draw();
        // end the current frame (internally swaps the front and back buffers)
        glfwSwapBuffers(window);
        glfwPollEvents();
        if (glfwGetKey (window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose (window, 1);
        }
    }
    // release resources...
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}