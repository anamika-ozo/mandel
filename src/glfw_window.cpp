#include <iostream>
#include <vector>
#include <string>

#include "index.cpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>

glewExperimental = true;
if (!glfwInit()) {
  fprintf(stderr, "Failed to initialize GLFW\n");
  return -1;
}

glfwWindowHint(GLFW_SAMPLES, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


GLFWwindow* window;
window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
if( window == NULL ) {
    fprintf( stderr, "couldn't open window.\n" );
    glfwTerminate();
    return -1;
}
glfwMakeContextCurrent(window);
glewExperimental=true;
if (glewInit() != GLEW_OK) {
    fprintf(stderr, "couldnt start glfew\n");
    return -1;
}

GLuint link_program(const std::vector<GLuint> &shaders) {
  typedef std::vector<GLuint>::const_iterator shaders_it;

  GLuint program = 0;
  std::stringstream error;

  program = glCreateProgram();
  for (shaders_it it = shaders.begin(); it != shaders.end(); ++it)
    glAttachShader(program, *it);

  //set_feedback(program,feedback_varyings,interlaced);
  glLinkProgram(program);

  for (shaders_it it = shaders.begin(); it != shaders.end(); ++it)
    glDetachShader(program, *it);

  error << "Error linking program: " << std::endl;
  if (program_error(program, error)) {
    glDeleteProgram(program);
    throw std::runtime_error(error.str());
  }

  return program;

}
