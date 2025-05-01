# LibMath

## Subject

To ensure we fully understand the mathematics applied to two- and three-dimensional video games, we need to reprogram some fundamental mathematical tools and organize them into a reusable software library.

## Implemented

- Angle :
    - Degree
    - Radian
- Intersection :
    - Point
    - 2D :
        - Circle
        - Collision 2D
        - Line
        - Rectangle
    - 3D :
        - Box
        - Collision 3D
        - Ray
        - Sphere
- Matrix :
    - Matrix 2x2
    - Matrix 3x3
    - Matrix 4x4
- Vector :
    - Vector 2
    - Vector 3
    - Vector 4
- Arithmetic
- Interpolation
- Intersection
- Quaternion
- Trigonometry

## Constraints

### Organization:
- This project is individual.
- We must code in C++ on Windows.
- Copying, cheating, or relying too much on the Internet = immediate 0.
(They want to test our logic and organization, not the Internet's)
    - We must use the Catch test solution provided.
    - All basic tests must pass. We were free to add more.
    - GLM is included in the project for verification purposes. It is forbidden to use it
in our own code!
    - However, our code must achieve approximately the same
results as GLM.
    - We can use functions from the standard <cmath> library.
    - All our classes, utility functions, etc., will be located in an lm namespace.