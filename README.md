# ft_fractal
The 2nd project of the 42us graphics branch

### --Project Description--

ft_fractal is a program that renders colorful fractal images that can be zoomed in and out of in real time. Supported fractals are "Mandelbrot", "Julia", "Burning Ship", and "Buddhabrot".

#### --Coding Style--

At 42, we follow a strict norm in order to teach us to follow style guides. This norm also prevents us from using many built-in functions. In this project, we are limited to using a barebones graphic library called minilibx. This library limits the functionality to creating windows, handling input hooks, and coloring specific pixels.

The allowed functions are : ```exit, malloc, free, and the functions of minilibx and math.h```.

The Project is written in C and in accordance with "The Norm".

#### --The Norm--

    • Functions must not exceed 25 lines
    • No more than 5 function-definitions in a .c file
    • One instruction per line
    • One single variable declaration per line; cannot stick declaration and initialisation on the same line
    • No more than 5 variables per bloc
    • No more than 4 parameters per function
    • Forbidden functions are: [for] [do ... while] [switch] [case] [goto]
    
### --Demo Instructions (Mac OSX El Capitan)--

    • Open Terminal and run the following commands:
    • git clone https://github.com/thedigglemister/ft_fractal ft_fractal
    • cd ft_fractal
    • make && ./fractal "mandelbrot" (ignore warnings related to minilibx)
    • Additionally, you might try "burning_ship", "julia", or "buddhabrot" in place of "mandelbrot"
       
#### --User Controls--

    • Arrows keys will translate the image
    • Z and X can be used to zoom in and out with zoom following the mouse
    • Left Shift can toggle automatic zoom
    • Space will rotate the color palette
    • Right Shift will automatically rotate color palette
    • esc to exit
    
 <img src="/images/mandel1.png" width="200">
 <img src="/images/mandel2.png" width="200">
 <img src="/images/burning_ship.png" width="200">
