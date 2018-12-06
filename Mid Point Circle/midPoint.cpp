// University: Universidade Federal do Vale do São Francisco - UNIVASF 
// Subject: Computer Graphics
// Professor: Jorge Cavalcanti
// Author: Paulo Bruny Araújo Lima
// Title: Mid point draw circle algorithm

#include <stdio.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
using namespace std;


// Auxiliary function to draw the pixels and set the origin to the middle of the window
void putpixels(float x, float y, int color) {
	// Get maximum width and height of the actual window
    float h = (float)getmaxy();
    float w = (float)getmaxx();
    putpixel(x+ (w/2), (h/2)-y, color);
}

// Function that implements Mid-Point Circle Drawing Algorithm
void CircleMidPoint(float x_center, float y_center, float r, int color) {
    // put x = radius and y = 0
    float x = r, y = 0;



    // Printing the initial point on the axes after translation
    putpixels(x + x_center, y + y_center, color);

    // When radius is zero only a single point will be printed
    if (r > 0) {
        putpixels(x + x_center, -y + y_center, color);
        putpixels(y + y_center, x + x_center, color);
        putpixels(-y + y_center, x + x_center, color);
    }

    /************
        Combinations
        x and y
        x and -y
        y and x
        -y and x
    *************/

    // Initialising the value of P
    int P = 1 - r;

    while (x > y) {
        y++;

        // Mid-point is inside or on the perimeter
        if (P <= 0) {
        	P = P + 2*y + 1;	
		}

        // Mid-point is outside the perimeter
        else {
            x--;
            P = P + 2*y - 2*x + 1;
        }

        // All the perimeter points have already been printed
        if (x < y) {
        	break;
		}
            

        // Printing the generated point and its reflection
        // in the other octants after translation
        putpixels(x + x_center, y + y_center, color);
        putpixels(-x + x_center, y + y_center, color);
        putpixels(x + x_center, -y + y_center, color);
        putpixels(-x + x_center, -y + y_center, color);

        // If the generated point is on the line x = y then
        // the perimeter points have already been printed
        if (x != y) {
            putpixels(y + y_center, x + x_center, color);
            putpixels(-y + y_center, x + x_center, color);
            putpixels(y + y_center, -x + x_center, color);
            putpixels(-y + y_center, -x + x_center, color);

        }
    }
}


int main()
{
    int gdriver = DETECT, gmode;

	// Variables to get user input
	int color;
	float x_center, y_center, r;
	
	// Input values
	printf("Please, insert the center point (x, y), radius and a color (1-15): ");
	scanf("%f %f %f %d", &x_center, &y_center, &r, &color);
    
	// Initialize graphics function
    initgraph (&gdriver, &gmode, "");
    
    // Get maximum width and height of the actual window
	float h = (float)getmaxy();
    float w = (float)getmaxx();
    
    // Draw x and y axis to give a reference
    line(0,h/2, w, h/2);
    line(w/2,0,w/2,h);
    
	// Call the CircleMidPoint function to draw the circle
    CircleMidPoint(x_center, y_center, r, color);
    
    getch();
    return 0;
}



