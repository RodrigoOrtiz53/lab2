//program: lab2.cpp 
//author: Gordon Griesel
//modified by: Rodrigo Ortiz
//date: 9/3/2019
//
//3350 Spring 2019 Lab-2
//
// I have changed the ASCII set, speed, rotation, color, variable names
// and added a function

#include <stdio.h>
#include <math.h>
#include <string.h>

int k;
double sin(), cos();

void changeColor();

int main()
{
    float speed = 0,
          rotation = 0,
          j,
          i,
          z[1760];

    char b[1760];

    changeColor();

    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);

        for (j = 0; 6.28 > j; j += 0.07)
            for (i = 0; 6.28 > i; i += 0.02) {
                float c = sin(i),
                      d = cos(j),
                      e = sin(speed),
                      f = sin(j),
                      g = cos(speed),
                      h = d+2,
                      D = 1/(c*h*e+f*g+5),
                      l = cos(i),
                      m = cos(rotation),
                      n = sin(rotation),
                      t = c*h*g-f*e;

                int x = 40+30*D*(l*h*m-t*n),
                    y = 12+15*D*(l*h*n+t*m),
                    o = x+80*y,
                    N = 8*((f*e-c*d*g)*m-c*d*e-f*g-l*d*n);

                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;;;

                    // Change the ASCII character set
                    b[o] = "1234567890ab"[N > 0 ? N : 0];
                }
            }

        printf("\x1b[2J");

        for (k = 0; 1761 > k; k++)
            putchar(k % 80 ? b[k] : 10);

        // Change speed and rotation 
        speed += 0.01;
        rotation += 0.08;
    }
}

void changeColor()
{
    // Change the color of the donut to magenta 
    printf("\x1b[35m");
}
