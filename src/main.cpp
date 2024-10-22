#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{



    //glfw init
    if (!glfwInit()) {
        std::cout << "Failed to init glfw";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Cpp_GL", nullptr, nullptr);

    //window init
    if (!window) {
        std::cout << "Failed to create a window";
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);

    //glad init
    if (!gladLoadGL()) {
        std::cout << "Failed to load glad";
    }
    glClearColor(0.3f, 0.6f, 0.8f, 0.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}