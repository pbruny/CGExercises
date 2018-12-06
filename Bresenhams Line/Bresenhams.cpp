// University: Universidade Federal do Vale do São Francisco - UNIVASF 
// Subject: Computer Graphics
// Professor: Jorge Cavalcanti
// Author: Paulo Bruny Araújo Lima
// Title: Bresenham's draw line algorithm

#include <stdio.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;


// Draw the pixels and set the origin to the middle of the window
void putpixels(float x, float y)
{
    // Get maximum width and height of the actual window
	float h = (float)getmaxy();
    float w = (float)getmaxx();
    putpixel(x+w/2, (h/2)-y, GREEN);
}


// Function that implements Bresenham's line generation algorithm
void bresenham(float x1, float y1, float x2, float y2)
{
    // Find delta
    float dx = x2-x1;
    float dy = y2-y1;

    // Find signs
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    // Get initial points
    float x = x1;
    float y = y1;

    // Flag to check if swapping happens
    int isSwaped = 0;

    // Swap if needed
    if(abs(dy) > abs(dx))
    {
        float tdx = dx;
        dx =dy;
        dy = tdx;

        isSwaped = 1;
    }

    // Decision parameter
    float p = 2*(abs(dy)) - abs(dx);

    //Print Initial Point
    putpixels(x,y);

    // Loop for dx times
    for(int i = 0; i<= abs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(isSwaped == 0){
                x += sx;
                putpixels(x,y);
            }
            else{
                y += sy;
                putpixels(x,y);
            }
            p += 2*abs(dy);
        }
        else
        {
            x += sx;
            y += sy;
            putpixels(x,y);
            p += 2*abs(dy) - 2*abs(dx);
        }
    }
}


int main()
{
    int gdriver = DETECT, gmode;

    float X0, Y0, X1, Y1;
	
	//Input values
	printf("Please, insert Xi, Yi; Xf , Yf: ");
	scanf("%f %f %f %f", &X0, &Y0, &X1, &Y1);
	
	// Initialize graphics function
	initgraph (&gdriver, &gmode, "");
	
	// Get maximum width and height of the actual window
	float w = (float)getmaxx();
	float h = (float)getmaxy();
	
	// Draw x and y axis to give a reference
	line(0,h/2, w, h/2);
    line(w/2,0,w/2,h);
	
	// Call bresenham draw line function
	bresenham(X0, Y0, X1, Y1);

    getch();
    return 0;
}



