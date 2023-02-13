## Introduction

This repository contains a simple project used for studying OpenGL concepts. Such as vertex buffers, vertex arrays, shaders, etc.

## Getting started

Before running the application you needed to install it dependencies. At this moment the project uses [vcpkg](https://vcpkg.io/en/index.html) for managing them, so start cloning the repository executing:

```sh
git clone https://github.com/caiquetorres/opengl-app
cd opengl-app
```

### Running for Linux and Mac

```sh
./run.sh
```

### Running for Windows

```sh
cmake -B "build"
make -C "build"
```

```sh
./build/opengl
```
