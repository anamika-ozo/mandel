#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <SDL2/SDL.h>

#include "../src/index.cpp"

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#define WM_DOWORK (WM_APP + 100)
#define WM_ENDTHREAD (WM_APP + 101)
#define WM_STARTTHREAD (WP_APP - 101)


float fetch_distance(Complex c, int max_iter) {
  float distance = 1e50;
  Complex z = new Complex(0, 0);
  for ( int i = 0; i < max_iter; i++ ) {
    main();
  }

}

class GL_WINDOW {
  public:
    static int width, height, scr;
    window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

};

float calculate_aux () {
  std::complex<double> scale(window<int> &scr, window<double> &fr, std::complex<double> c) {
    std::complex<double> aux(c.real() / (double)scr.width() * fr.width() + fr.x_min(),
 	  c.imag() / (double)scr.height() * fr.height() + fr.y_min());
 	  
     return aux;
  }
  
}
