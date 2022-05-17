# mes_equipes
[![Build](https://github.com/Cavonstavant/mes_equipes/actions/workflows/cmake.yml/badge.svg)](https://github.com/Cavonstavant/mes_equipes/actions/workflows/cmake.yml) [![GH Pages deployment](https://github.com/Cavonstavant/mes_equipes/actions/workflows/doc_build.yml/badge.svg)](https://github.com/Cavonstavant/mes_equipes/actions/workflows/doc_build.yml) [![Mirroring](https://github.com/Cavonstavant/mes_equipes/actions/workflows/mirroring.yml/badge.svg)](https://github.com/Cavonstavant/mes_equipes/actions/workflows/mirroring.yml) [![forthebadge](https://forthebadge.com/images/badges/works-on-my-machine.svg)](https://forthebadge.com)
> MicroDoux Equipes clone

## Documentation

The documentation is currently hosted [here](https://cavonstavant.github.io/mes_equipes/index.html).

> Local documentation cna be generated using doxygen with running `doxygen` at the root of the repository. Use `xdg-open doc/build/html/index.html` to open it.

## Build

### Tools

    - CMake >= 3.17.0
    - C11

### Building

On Linux:

```bash
    git clone https://github.com/Cavonstavant/mes_equipes.git
    cd mes_equipes/
    cmake -B ./build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    cmake --build ./build
```

Building the tests:

```bash
    cmake -B ./build-with-coverage -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DENABLE_CODE_COVERAGE=ON
    cmake --build ./build-with-coverage
```

Running the tests and get the coverage report:

```bash
    ./launch_tests.sh
```