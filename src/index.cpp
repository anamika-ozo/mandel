#include <iostream>
#include <math.h>
using namespace std;

class Complex {
	public:
		double real_part;
		double complex_part;
		void squared(double *x, double *i) {
			*x = (real_part * real_part) - (complex_part * complex_part);
			*i = 2 * real_part * complex_part;
		}
		double magnitude() {
			return sqrt(real_part*real_part + complex_part*complex_part);
		}
};

bool stays_bounded() {

	Complex c;
	cout << "Enter Real Part, dummy" << endl;
	cin >> c.real_part;
	cout << "Enter Complex Part, dummy" << endl;
	cin >> c.complex_part;

	Complex z;
	z.real_part = 0;
	z.complex_part = 0;

	double i, x;

	double count = 0;
	while (count < 100) {
		z.squared(&x,&i);
		z.real_part = x + c.real_part;
		z.complex_part = i + c.complex_part;
		count++;
		if (z.magnitude() > 2) {
			cout << z.magnitude() << endl;
			return 0;
		}
	}
	cout << z.magnitude() << endl;
	return 1;
}

int main() {
	cout << stays_bounded() << endl;
}
