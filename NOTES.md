# OCIRO Pipeline

## Pipeline Overview

```text
Camera Input
    ↓
Frame Flip
    ↓
Gaussian Blur
    ↓
HSV Conversion
    ↓
Color Thresholding
    ↓
Morphology
    ↓
Contour Detection
    ↓
Area Filtering
    ↓
Centroid Extraction
    ↓
EMA Smoothing
```

---

## 1. Camera Input

Frames are captured from the webcam using OpenCV `VideoCapture`.

```cpp
video.read(frame);
```

---

## 2. Frame Flip

```cpp
cv::flip(frame, frame, 1);
```

Mirrors the frame horizontally for natural interaction.

---

## 3. Gaussian Blur

```cpp
cv::GaussianBlur(frame, frame, cv::Size(5,5), 0);
```

Reduces image noise and stabilizes the mask.

---

## 4. HSV Conversion

```cpp
cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);
```

Converts the image from BGR to HSV color space for easier color detection.

---

## 5. Color Thresholding

```cpp
cv::inRange(hsvFrame, lower, upper, mask);
```

Creates a binary mask for the selected color range.

---

## 6. Morphology

Opening and closing operations are applied to:

* remove noise
* fill holes
* stabilize the detected object

---

## 7. Contour Detection

```cpp
cv::findContours(...)
```

Contours are extracted from the binary mask.

---

## 8. Area Filtering

```cpp
if(area > threshArea)
```

Small noisy contours are ignored.

---

## 9. Centroid Extraction

```cpp
cv::Moments M = cv::moments(contour);
```

The centroid is computed using image moments.

---

## 10. EMA Smoothing

```text
Smoothed = α(Current) + (1-α)(Previous)
```

Exponential Moving Average (EMA) reduces centroid jitter and stabilizes tracking.

---

## Output

The final system tracks a colored object in real time and produces a stabilized centroid.