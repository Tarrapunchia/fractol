# fractol
Project made for 42CommonCore project "fract'ol" @42Firenze.

The aim is to display on screen, using a xlib wrapper library called minlibx, different types of fractals based on the set used to calculate them.
The choice (and other optional parameters) are passed via terminal when the program is launched.

While in the program is possible to:
	- Zoom in/out with mouse wheel, with the zoom centered on mouse position;
	- Move around and zoom in/out with keyboard;
	- Change the iterations of the set, to deepen the drawing;
	- Change the base color set;
	- Change base parameters whit random (for Julia Set);
	- Change the zoom "speed"
	- And, of course, exit the program =).

The purpose of the project is to become familiar with comunication between client and X-Window and to understand how to draw and then display an image.

Logical steps involved in writing such program are:
	- (understanding what a fractal is and how can be displayed =)
	- (eventually, you will reach to the conclusion that the most simple and probably best
	   way is to take the imaginary part as the y and the real part as the x)
	- opening a comunication with X-Window, creating a window and an image
	- calculating the chosen set for each point in the screen:
		- print the pixel in black if the set oscillates between tho finite values
		- print the pixel in color varied by the number of repetitions if the set goes to infinity
	- program the mouse and keyboard hooks.
	- loop
	- VALGRIND.


