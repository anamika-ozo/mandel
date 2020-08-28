#include <iostream>
#include <vector>
#include <string>

#include "index.cpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;

#define WM_DOWORK (WM_APP + 100)
#define WM_ENDTHREAD (WM_APP + 101)

float fetch_distance(Complex c, int max_iter)
{
  float distance = 1e50;
  Complex z = new Complex(0, 0);
  for (int i = 0; i < max_iter; i++)
  {
    main();
  }
}

glewExperimental = true;
if (!glfwInit())
{
  fprintf(stderr, "Failed to initialize GLFW\n");
  return -1;
}

glfwWindowHint(GLFW_SAMPLES, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


GLFWwindow* window;
window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
if( window == NULL ){
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

GLuint link_program(const std::vector<GLuint> &shaders)
{
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
  if (program_error(program, error))
  {
    glDeleteProgram(program);
    throw std::runtime_error(error.str());
  }

  return program;
