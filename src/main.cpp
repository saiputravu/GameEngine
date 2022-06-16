#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>
#include <math.h>

const char* vertexShaderSource = "#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"       gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 460 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"       FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main (int argc, char *argv[])
{

  // Initialise GLFW (OpenGL and Window contexts)
  glfwInit();

  // Set OpenGL version hints and profile version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLfloat vertices[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f,
  };

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

  /********* CREATE SHADERS **********/
  // Create the vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // Set shader source 
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  // Compile source
  glCompileShader(vertexShader);

  // Create the fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  // Set shader source 
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  // Compile source
  glCompileShader(fragmentShader);

  // Create and attach compiled programs and then link the program
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // Delete the shader sources
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  /*********** CREATE Vertex Array Objects and Vertex Buffer Objects ***********/
  GLuint VAO, VBO;


  // Generate 1 vertex array object name, store as VAO
  glGenVertexArrays(1, &VAO);
  // Generate 1 vertex buffer object name, store as VBO
  glGenBuffers(1, &VBO);

  // Binds vertex array with name
  glBindVertexArray(VAO);
  // Binds buffer object to specified buffer binding point
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  // Put data into buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Configure vertex attribute so that OpenGL knows how to read the VBO
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  // Enable the Vertex Attribute so that OpenGL knows to use it
  glEnableVertexAttribArray(0);

  // Bind VAO and VBO to 0 so we don't accidentally modify VAO and VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  /********* WINDOW Configuration **************/
  // Set buffer colour
  glClearColor(0.17f, 0.13f, 0.17f, 0.3f);
  // Clean back buffer and assign new colour to it
  glClear(GL_COLOR_BUFFER_BIT);

  // Swap back buffer to front
  glfwSwapBuffers(window);

  // Loop forever until window closed
  while (!glfwWindowShouldClose(window)) {

    // Clear BG
    glClearColor(0.17f, 0.13f, 0.17f, 0.3f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Use shader program
    glUseProgram(shaderProgram);
    // Re-bind vertex array ?
    glBindVertexArray(VAO);
    // Draw array
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Swap back and front buffer 
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  // Delete all the objects we made
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);
  
  // Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
