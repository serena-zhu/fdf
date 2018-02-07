# fdf
A 3D graphic representation of a relief landscape

This is a program that creates a simplified graphic wireframe represenatation of a relief landscape by linking points via segments. The program takes a file as a parameter.

Usage : ./fdf <filename>

Example of a valid map file:

![Screenshot] (valid_map_sample.png)

0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20,0xFF0000 15,0xFF0000 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0
0 10 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 15,0xFF0000 10  0
0  5 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0

Each number above corresponds to a point in space, where...
The horizontal position corresponds to its axis. 
The vertical position corresponds to its ordinate.
The value corresponds to its altitude with an optional color value in hexadecimal separated by a comma
