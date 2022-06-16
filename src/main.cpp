#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

int main (int argc, char *argv[])
{

  // Initialise GLFW (OpenGL and Window contexts)
  glfwInit();

  // Set OpenGL version hints and profile version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create a winow of dimensions 800x800, title OpenGL
  GLFWwindow *window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);
  if (window == NULL) {
    // Kill itself if failed to create window
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Introduce window to current context
  glfwMakeContextCurrent(window);

  // Load GLAD to configure OpenGL
  gladLoadGL();
  // Transform from pixels to x y coords or something
  // Viewport goes from x=0,y=0 to x=800,y=800
  glViewport(0, 0, 800, 800);

  // Set buffer colour
  glClearColor(0.17f, 0.13f, 0.17f, 0.3f);
  // Clean back buffer and assign new colour to it
  glClear(GL_COLOR_BUFFER_BIT);

  // Swap back buffer to front
  glfwSwapBuffers(window);

  // Loop forever until window closed
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
  
  // Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
