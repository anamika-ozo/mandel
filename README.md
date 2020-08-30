# Mandel

## a mandelbrot image viewer written in C++ & Qt5

-----



#### Building, Testing & Installation

The following dependencies are required:

- freeglut3-dev
- libxmu-dev 
- libxi-dev
- mesa-utils
- meson
- ninja ( >=1.7 )

`sudo apt install freeglut3-dev libxmu-dev libxi-dev mesa-utils build-essential meson`

Then clone this repo:

`git clone https://gitlab.com/anamika_ozo/mandel.git`

Enter the working directory with the `cd` command

`cd mandel/`

The meson build system is already set up for Windows 7+ & Debian, so these commands should be universal;

`meson builddir`

`ninja -C builddir`

`sudo ninja -C builddir install`

