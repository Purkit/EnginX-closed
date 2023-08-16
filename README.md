# EnginX
C++ Multi API 3D Game Engine Exclusively for Linux and BSD.

---
## License
GPLv3


<h1> Public API Documentation</h1>

# Vector:
## Decleration:
## Initialization:
## Operations:

# Matrix:
## Decleration:

```c++
    ex_math::Matrix2x2 mat_1;
    ex_math::Matrix3x3 mat_2;
    ex_math::Matrix4x4 mat_3;    
```
## Initialization:
```c++
    ex_math::Matrix2x2 mat_2(37); // Initializes all elements to 37
```
There is two way two use a matrix.
First, via treditional constructor:
```c++
    ex_math::Matrix2x2 mat_3
    (
        1, 2,
        3, 4
    );
```
Second, via assining an array (looks better):
```c++
    ex_math::Matrix4x4 mat_4 = 
    {
        99, 74, 32, 86,
        68, 47, 98, 12,
        77, 53, 42, 82,
        21, 48, 72, 88
    };
```
## Access elements of a Matrix:
Accessing elements is similar to that of vector. Just do this:
```c++
    mat_4.a11; // = 99
    mat_4.a12; // = 74
    mat_4.a43; // = 72
```

## Operations:
Matrix addition:
```c++

```
Scalar-Matrix multiplication:
```c++

```
Matrix-Vector multiplication:
```c++

```
Matrix-Matrix multiplication:
```c++

```

## Special optimized operations:
Fast Inverse Square Root: This is taken from Quake 3 Game Engine (released under GPLv2). Full credit 
goes to the person who invented this algorithm.
Complexity Order = O(2)
```c++
    float input = 79.43; 
    result = ex_math::ex_inv_sqrt(input);
```
Fast Square Root: I made this algorithm to compute massive square root rapidely. This is similar to
the Fast Inverse Square Root Algorithm shown above.
Complexity Order = O(2)
```c++
    float input = 945.68; 
    result = ex_math::ex_sqrt(input);
```

<h1>TODO List</h1>


## Build system:
    1.  Use Cmake instead of Make (DONE on 17/June/2022)

## Core/platform specific:
    1.  add function to catch SIGTERM signal when the user runs "kill -15 <pid>" or "kill <pid>" or
        "killall enginx" if any SIGTERM signal received then generate a "application_close" event 
        and fire OnAppClose function immediately which will safely close all subsystems, save all 
        progress  free all acquired resources and finally safely close the program.
    2.  add Wayland support soon.

## Input system:
    1.  add callback function support on input event
    2.  get keyboard and mouse input from evdev (directly from kernel) without sudo previledges

## Math library (ex_math):
    1.  implement quarternian
    2.  ** Use SIMD for every heavy operations
    3.  implement the rest of linear algebra, trigonometry, calculus, basic algebra,
        equalion solving(all kind), eucledian geometry.