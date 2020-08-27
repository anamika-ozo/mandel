#include <iostream>
#include <math.h>

class Complex
{
public:
	int real, complex;

private:

};


template <unsigned N>
struct Factorial {
  static const unsigned value = N * Factorial<N - 1>::value;
};


template <>
struct Factorial<0> {
  static const unsigned value = 1;
};

auto main(void) -> int {
	int 
		z = 0, 
		c = 1;

	while(z < 1000) {
	    z++;

	    if (z * z + c == 2) {
	    	return 2;
	    }

	    std::cout << z << std::endl;
	}
}
