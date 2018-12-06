// University: Universidade Federal do Vale do São Francisco - UNIVASF 
// Subject: Computer Graphics
// Professor: Jorge Cavalcanti
// Author: Paulo Bruny Araújo Lima
// Title: Draw circle algorithm using octants

#include <stdio.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
using namespace std;

// Auxiliary function to draw the pixels and set the origin to the middle of the window
void putPixels(float x, float y, int color) {
	// Get maximum width and height of the actual window
    float h = (float)getmaxy();
    float w = (float)getmaxx();
    putpixel(x+ (w/2), (h/2)-y, color);
}

// Function that implements Mid-Point Circle Drawing Algorithm
void CircleSimple(float x_center, float y_center, float r, int color) {
    float x, y, theta, deltaTheta, pi;
    
    theta = 0;
    deltaTheta = 0.01;
    pi = 3.141592;
    
    while(theta < pi/4){
    	// Calculate polar coordinates x and y
    	x = x_center + r * cos(theta);
    	y = y_center + r * sin(theta);
    	
    	// Increments theta
    	theta += deltaTheta;
    	
    	// Calculate the 8 octants and call putPixels to draw it
    	
    	putPixels(x, y, color);
        putPixels(y, x, color);
        putPixels(y, 2 * x_center - x, color);
        putPixels(2 * x_center - x, y, color);
        putPixels(2 * x_center - x, 2 * y_center - y, color);
        putPixels(2 * y_center - y, 2 * x_center - x, color);
        putPixels(2 * y_center - y, x, color);
        putPixels(x, 2 * y_center - y, color);
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
    CircleSimple(x_center, y_center, r, color);
    
    getch();
    return 0;
}
