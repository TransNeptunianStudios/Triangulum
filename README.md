A top down scrolling space action game! Asteroids, lasers, bosses, cool music and explosions. A classic space shooter that wants to be the next R-type!  

<img src="https://raw.githubusercontent.com/TransNeptunianStudios/Triangulum/133f56ebe55d6b3ef16aae516f3b3b06db9552df/images/Screenshot2.png" alt="Screenshot" style="width:160;height:120">


## Dependencies
* SFML 2.1
* EntityX (latest)
* yaml-cpp (0.3.0)

## Prepare to build
* Follow [EntityX](https://github.com/alecthomas/entityx.git) instructions for installation
* Install [yaml-cpp 0.3.0](https://code.google.com/p/yaml-cpp/)
* Install [SFML 2.1](http://www.sfml-dev.org/)

## Building 
* git clone
* cd Triangulum
* mkdir build
* cd build
* cmake .. && make

## Building for Windows with MinGW
* Download latest MinGW from http://www.mingw.org/
* Install mingw32-base, mingw32-gcc-g++
* Download EntityX
* cd EntityX
* mkdir build
* cmake .. -G "MinGW Makefiles"
* mingw32-make
* Download yaml-cpp
* cd yaml-cpp
* mkdir build
* cmake .. -G "MinGW Makefiles"
* mingw32-make
* Download SFML (GCC 4.7 MinGW (DW2) - 32 bits)
* Download external library dependencies for SFML https://github.com/LaurentGomila/SFML/tree/master/extlibs/libs-mingw/x86 (put in SFML/lib)
* clone Triangulum
* mkdir build
* cd build
* cmake .. -G "MinGW Makefiles" -DENTITYX_ROOT="<path to EntityX>" -DYAMLCPP_DIR="<path to yaml-cpp>" -DSFML_ROOT="<path to SFML>"

## Other esources, current, future and potential

* CMake 3.0.1     	- http://www.cmake.org/
* sfxr         		- http://www.drpetter.se/project_sfxr.html
* aseprite        	- http://www.aseprite.org/
* Music 			- http://incompetech.com/music/royalty-free/

