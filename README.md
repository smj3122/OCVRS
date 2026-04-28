# OCIRO
OpenCV Input ROS2 Output Project

This is a project based on original SRA project MARIO and Pixels.

*ROS2 is yet to be implemented in the project and will be done soon !!!

## Installation Guide (OpenCV & SDL)



1. **Clone the repository**
```bash
git clone https://github.com/pinkCastle2204/OCIRO.git
cd OCIRO
```
2. **Make the script executable**
```bash
chmod +x install.sh
```
3. **Run the installation script**
```bash
./install.sh
```

You can verify installation using:

```bash
pkg-config --modversion opencv4
pkg-config --modversion sdl2
```

Building the binaries (run the following command in respective directory)

```bash
make
```


Cleaning the build

```bash
make clean
```