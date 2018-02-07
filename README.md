# fdf
A 3D graphic representation of a relief landscape

This is a program that creates a simplified graphic wireframe represenatation of a relief landscape by linking points via segments. The landscape will be shown in isometric projection. This program uses a minilibx library developed internally by 42. The program takes a file as a parameter.

Usage : ./fdf \<filename>

Example of a valid map file:

![alt_tag](valid_map_sample.png | width=100)

Each number above corresponds to a point in space, where...
The horizontal position corresponds to its axis. 
The vertical position corresponds to its ordinate.
The value corresponds to its altitude with an optional color value in hexadecimal separated by a comma

The number of values in the first line sets the range for horizontal position, therefore any extras will be ignored. The program will display an error message if subsequent lines contain fewer number of values.

Program output of the example map above:

![alt_tag](sample_map_output.png)
<img src="sample_map_output.png" height="50%">
