# C++ AP Project

## Overview

This repository contains a C++ Advanced Programming project focusing on custom data structures and object-oriented design. The project is divided into two parts:

## Part 1: Custom Vector Implementation and Performance Analysis

### Description

- **Custom Vector Class (`CustomVector`)**: Implements a vector with functionalities for inserting, removing, and resizing elements.
- **Alternative Vector Class (`pvector`)**: Another vector implementation using `T**` instead of `T*`.

### Performance Testing

- Measures the performance of `insert` and `remove` operations using `std::clock()` for both vector implementations and compares the results.

**Performance Results**:  
![Performance Results](Part%201/Results.png)

### Executable

- **`part1.exe`**: The executable for Part 1 is located in the `Part1` directory.

### Files

- `CustomVector.h`: `CustomVector` class implementation.
- `pvector.h`: `pvector` class implementation.
- `main.cpp`: Performance tests for `CustomVector` and `pvector`.

## Part 2: Device Class Implementation

### Description

- **Shape Classes**: Base class `Shape` with derived classes `Cube` and `Sphere`.
- **Device Class**: Models complex devices composed of `Shape` objects and other `Device` instances.

### Executable

- **`part2.exe`**: The executable for Part 2 is located in the `Part2` directory.

### Files

- `Shape.h`: Definitions for `Shape`, `Cube`, and `Sphere`.
- `Device.h`: Definition for `Device`.
- `main.cpp`: Demonstrates the use of `Shape` and `Device` classes.


