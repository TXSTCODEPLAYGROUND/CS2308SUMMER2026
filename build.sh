#!/bin/bash
set -e

# Build the project from the root of LMSPrototype.
# Use the include directory and compile all required source files.

g++ -std=c++20 -I include main.cpp src/models/*.cpp src/services/*.cpp -o main

echo "Build complete: ./main" 
