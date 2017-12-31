#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

int main()
{
	// initialize constants 
	double R=5.0/100; 
	double r=1.0/100; 
	double a=4.0/100;
	int nRev = 10;

	// initialize SGM coordiantes
	double sgmX = 34.0212409;
	double sgmY = -118.28915489999997;

	// initialize result variables
	double x = 0;
	double y = 0;

	// open file where coordinates will be stored
	FILE *fp = NULL;
	fp = fopen("spiro.txt", "w");

	// find spirograph points
	double t = 0;
	for(t = 0; t < (M_PI*nRev); t = t + .01) {
		x = (R + r)*cos((r/R)*t) - (r + a)*cos((1+R/r)*t);
		y = (R + r)*sin((r/R)*t) - (r + a)*sin((1+R/r)*t);
		double resultX = sgmX + 0.01*x;
		double resultY = sgmY + 0.01*y;
   		fprintf(fp, "%f,%f,%d\n", resultY, resultX, 0);
	}

	// close file
	fclose(fp);

    return 0;
 
}