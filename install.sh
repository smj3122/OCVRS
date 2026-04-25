#!/bin/bash

echo "Checking if OpenCV is installed..."

# Check if OpenCV and SDL2 exist via pkg-config
if pkg-config --exists opencv4 sdl2; then
    echo "OpenCV is installed"
    exit 0
else
    echo "OpenCV is not installed"
    echo "Installing OpenCV..."
fi

# Detect OS
if grep -qi "debian" /etc/os-release; then
    echo "Debian-based system detected"
    sudo apt-get update -y
    sudo apt-get install -y libopencv-dev libsdl2-2.0-0 libsdl2-image-dev libsdl2-dev build-essential cmake

elif [[ "$OSTYPE" == "darwin"* ]]; then
    echo "Mac detected"
    brew install opencv sdl2 cmake

elif grep -qi "arch" /etc/os-release; then
    echo "Arch Linux detected"
    sudo pacman -Sy --noconfirm opencv hdf5 glew vtk fmt sdl2 cmake base-devel

else
    echo "Unknown OS"
    exit 1
fi
