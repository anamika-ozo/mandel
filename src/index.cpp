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
		return sqrt(real_part * real_part + complex_part * complex_part);
	}
};

bool stays_bounded(double x, double i) {
	Complex c;

	c.real_part = 1;
	c.complex_part = 0;

	c.real_part = x;
	c.complex_part = i;

	Complex z;
	z.real_part = 0;
	z.complex_part = 0;

	int count = 0;

	while (count < 100) {
		z.squared(&x, &i);
		//cout << "x = " << x << " i = " << i << endl;
		z.real_part = x + c.real_part;
		z.complex_part = i + c.complex_part;
		count++;
		if (z.magnitude() >= 2 || z.magnitude() <= -2)
		{

			return 0;
		}
	}
	return 1;
}

class equation_vars {
public:
	unsigned char pix[2000000];
	int res_x = 1000;
	int res_y = 1000;
	double zoom = 0.5;
	double pos_x = -0.5;
	double pos_y = 0;
};


void output () {
	equation_vars a;

	FILE *output;
	int x, y, pixel, height = a.res_x, width = a.res_y;

	output = fopen("../assets/image.pgm", "wb");
	if (output == NULL) {
		perror("ERROR: Cannot open output file");
		exit(EXIT_FAILURE);
	}

	fprintf(output, "P5\n");
	fprintf(output, "%d %d\n", width, height);
	fprintf(output, "255\n");

	fwrite(a.pix, 1, 16000000, output);

	fclose(output);

}


auto main() -> int {
	equation_vars a;

	for (int x = -a.res_x / 2; x <= a.res_x / 2; x++)
	{
		for (int i = -a.res_y / 2; i <= a.res_y / 2; i++)
		{
			double d = x;
			double dx = d / (a.res_x * a.zoom) + a.pos_x;
			d = i;
			double di = d / (a.res_x * a.zoom) + a.pos_y;
			if (stays_bounded(dx, di)) {
				cout << "x = " << dx << ", i = " << di << " Position = " << x + a.res_x / 2 + (i + a.res_y / 2) * a.res_x << endl;
				a.pix[x + a.res_x / 2 + (i + a.res_y / 2) * a.res_x] = (255);
			}
			else {
				cout << "x = " << dx << ", i = " << di << " Position = " << x + a.res_x / 2 + (i + a.res_y / 2) * a.res_x << endl;

				a.pix[x + a.res_x / 2 + (i + a.res_y / 2) * a.res_x] = (0);
				//pix[x+res_x/2 + (i+res_y/2)*res_x +1]	= (0);
				//pix[x+res_x/2 + (i+res_y/2)*res_x +2]	= (0);
			}
		}
	}

	output();

	return 0;
}