# box3cpp

A small C++20 wrapper for [Box3D](https://github.com/erincatto/box3d) with RAII, move-only handles, examples, tests, and CMake integration.

The project starts as a careful layer over the Box3D C API. Its main goal is to make worlds, bodies, and shapes easier to use from C++ code while keeping the simple model of Box3D.

## Library scope

`box3cpp` will grow around a small set of C++ abstractions that cover the most common actions when working with Box3D.

- RAII for objects with explicit lifetimes
- move-only handles for world, body, shape, and joint
- ergonomic methods over the C API
- small examples for simple physics scenes
- a CMake target for use in other projects
- tests for basic behavior and resource ownership

## Status

The project is in an early stage. The minimal library foundation, documentation, and first examples are being built now.

The API is not considered stable yet. The first versions will change as the best C++ abstractions for Box3D become clearer.

## First milestone

The first working version should cover the most basic Box3D workflow from C++.

It will include world creation, simple bodies and shapes, simulation stepping, safe resource cleanup, and one or two small examples. After that, joints, callbacks, queries, and more convenient helpers can be added gradually.

## Relationship with Box3D

`box3cpp` will follow the Box3D model and stay as a thin layer for C++ code. The wrapper should help with object lifetimes, types, CMake integration, and readability of user code.

Simulation behavior remains on the Box3D side. The main focus of this library is a convenient and safe C++ interface around the existing API.

## Principles

The library should stay small and predictable. If a part of Box3D is already expressed clearly through the original API, the wrapper should not make it more complex without a good reason.

The main priority is clear resource ownership. User code should make it easy to see who creates an object, how long it lives, and when it is released.

## Near-term tasks

The project first needs a small but working foundation.

- prepare a CMake target for a header-only library
- add minimal types for world, body, and shape
- document the resource ownership rules
- build the first example with a simple scene
- add smoke tests and GitHub Actions
- check where the wrapper actually makes Box3D easier to use

## License

MIT
