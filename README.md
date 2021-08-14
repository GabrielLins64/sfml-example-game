<h1>SFML Example Game</h1>

This repo contains a small game example in C++, using the [SFML library](https://www.sfml-dev.org/).

---

<h2>Index</h2>

- [Dependencies](#dependencies)
- [Build](#build)
- [Execute](#execute)
- [Notes](#notes)
- [References](#references)

---

## Dependencies

- [SFML](https://www.sfml-dev.org/)

- [g++](https://gcc.gnu.org/)

## Build

In order to compile the game, simply run the shell script `build.sh` by doing:

```
$ chmod +x build.sh
$ ./build.sh
```

<small>\*For manual compilation in g++, follow the commands in the shell script.</small>

## Execute

The same process for running the game:

```
$ chmod +x run.sh
$ ./run.sh
```

Or, simply:

`$ ./bin/game`

## Notes

The third-party libs (.h/.hpp and .so/.a/.dll) aren't uploaded along with the code for size purposes. They're included in the "lib" directory with the other project directories (bin, build, src, etc.) and should be installed individually in the cloner system. The shell or cmake scripts in all tutorials shows the full paths for the libs.

The assets used by all tutorials (\*-Learning directories) aren't owned by the author of this repository and, if used from here, need to be referenced. References for the tutorials and the assets are given below.

## References

[1] Shekar, Siddharth. C++ Game Development By Example: Learn to build games and graphics with SFML, OpenGL, and Vulkan using C++ programming. Packt Publishing, 2019.

[2] https://github.com/PacktPublishing/CPP-Game-Development-By-Example

[3] http://www.widgetworx.com/widgetworx/portfolio/spritelib.html
