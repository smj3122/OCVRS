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
#  **Morphology**

As far as image processing is concerned morphology is about regions and
shapes. It is used as a tool for extracting image components that are useful in
representing regions and shapes.

* Morphological operations require two inputs, one is input image and the other is a structuring element or kernel (square matrix of odd size 3,5,7..).

* Morphological operations rely only on the relative ordering of pixel values, not on their numerical values, and therefore are especially suited to the processing of binary images.

## Table of content 

>**1.Erosion** 

>**2.Dilation**

## Erosion 

The structuring elements shrinks an image by stripping away a layer of pixels from both the inner and outer boundaries of regions.

HOW IT WORKS ?

1. A kernel (a matrix of odd size (3,5,7)) is convolved with the image.
2. A pixel in the original image white will be considered white only if all the pixels under the kernel is
white, otherwise it is eroded (made to black).
3. Thus all the pixels near boundary will be discarded depending upon the size of kernel.
4. So the thickness or size of the foreground object decreases or simply white region decreases in the
image.

## Dilation 

Dilation has the opposite effect to erosion. It adds a layer of pixels to both the inner and outer boundaries of regions.

HOW IT WORKS ?

1. A kernel (a matrix of odd size (3,5,7)) is convolved with the image
2. A pixel element in the original image is ‘white’ if at least one pixel under the kernel is ‘white’.
3. It increases the white region in the image or size of foreground object increases.

## **HOW WE REDUCED NOISE USING THIS ?** 

When we combine These two steps a compound morphological operation is performed called “OPENING” .

In this operation we first do  erosion  by this boundaries of foreground pixels erode away  and then by dilation the boundary of the image now get enlarged by this noise from our image is now removed. 

#  **Morphology**

As far as image processing is concerned morphology is about regions and
shapes. It is used as a tool for extracting image components that are useful in
representing regions and shapes.

* Morphological operations require two inputs, one is input image and the other is a structuring element or kernel (square matrix of odd size 3,5,7..).

* Morphological operations rely only on the relative ordering of pixel values, not on their numerical values, and therefore are especially suited to the processing of binary images.

## Table of content 

>**1.Erosion** 

>**2.Dilation**

## Erosion 

The structuring elements shrinks an image by stripping away a layer of pixels from both the inner and outer boundaries of regions.

HOW IT WORKS ?

1. A kernel (a matrix of odd size (3,5,7)) is convolved with the image.
2. A pixel in the original image white will be considered white only if all the pixels under the kernel is
white, otherwise it is eroded (made to black).
3. Thus all the pixels near boundary will be discarded depending upon the size of kernel.
4. So the thickness or size of the foreground object decreases or simply white region decreases in the
image.

## Dilation 

Dilation has the opposite effect to erosion. It adds a layer of pixels to both the inner and outer boundaries of regions.

HOW IT WORKS ?

1. A kernel (a matrix of odd size (3,5,7)) is convolved with the image
2. A pixel element in the original image is ‘white’ if at least one pixel under the kernel is ‘white’.
3. It increases the white region in the image or size of foreground object increases.

## **HOW WE REDUCED NOISE USING THIS ?** 

When we combine These two steps a compound morphological operation is performed called “OPENING” .

In this operation we first do  erosion  by this boundaries of foreground pixels erode away  and then by dilation the boundary of the image now get enlarged by this noise from our image is now removed. 