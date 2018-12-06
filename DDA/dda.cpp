// This program is made mainly in english with the purpose of share in repositories for other students to get learning reference
// University: Universidade Federal do Vale do São Francisco - UNIVASF 
// Subject: Computer Graphics
// Professor: Jorge Cavalcanti
// Author: Paulo Bruny Araújo Lima
// Title: DDA draw line algorithm

#include <stdio.h>
#include <graphics.h>
#include <math.h>

// DDA Function to draw the line
void drawLineWithDDA(float X0, float Y0, float X1, float Y1)
{
    // Get maximum width and height of the actual window
	float w = (float)getmaxx();
    float h = (float)getmaxy();

    // calculate dx & dy
    float dx = X1 - X0;
    float dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment for x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    float X = X0;
    float Y = Y0;
    
    // Draw the pixels and set the origin to the middle of the window
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X+(w/2), (h/2)-Y, GREEN);   			// put pixel at (X,Y)
        X += Xinc;                          			// increment x at each step
        Y += Yinc;                          			// increment y at each step
    }
}

// Main program
int main()
{
    int gdriver = DETECT, gmode, errorcode;
    
    // Variables to get user input
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
	
	// Call the draw line function
	drawLineWithDDA(X0, Y0, X1, Y1);   

    getch();
    return 0;
}
