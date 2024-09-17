#!/bin/bash

# Ensure proper usage
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <x-coordinate> <y-coordinate>"
  exit 1
fi

# Compile the C++ program
echo "Compiling C++ program..."
make re

# Check if compilation was successful
if [ ! -f Fixed ]; then
  echo "Compilation failed or executable not found."
  exit 1
fi

# Run the C++ program to generate coordinates.txt with arguments
echo "Running C++ program..."
./Fixed "$1" "$2"

# Check if coordinates.txt was created
if [ ! -f coordinates.txt ]; then
  echo "coordinates.txt not found. Ensure the C++ program ran successfully."
  exit 1
fi

# Install matplotlib if not already installed
pip3 install matplotlib

# Run the Python script to plot the results
echo "Running Python script..."
python3 plot_triangle.py

# Check for Python errors
if [ $? -ne 0 ]; then
  echo "Python script failed. Ensure matplotlib is installed and coordinates.txt is correctly formatted."
  exit 1
fi

rm -rf coordinates.txt

echo "Script completed successfully."
