
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "other.hpp"

int main()
{
    print("Hello World!\n");

    if (glfwInit() == GLFW_FALSE)
    {
        print("Uhh");
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow * window{nullptr};
    window = glfwCreateWindow(800, 800, "Test Project", nullptr, nullptr);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
