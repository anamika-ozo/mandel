# Mandel

## a mandelbrot image viewer written in C++ & Qt5

#### Installation

First, you'll want to clone this repo.

`git clone https://gitlab.com/anamika_ozo/mandel.git`

Enter the working directory with the `cd` command

`cd mandel/`

The meson build system is already set up for Windows 7+ & Debian, so these commands should be universal;

`meson builddir`

`ninja -C builddir`

`sudo ninja -C builddir install`

#### WIP

- Zoom-in feature
- Qt interface
- Bookmarks on co-ordinates on the map
- GPU acceleration & caching
