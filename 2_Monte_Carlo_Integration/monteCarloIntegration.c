#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double gaussian(double x) {
  return x;
}

int main(void) {
    srand(0);
    double valIntegral, yReal = 0, xRand, yRand, yBound;
    int xMin=0;
    int xMax=1;
    int numTrials = 10000;
    int countY = 0;

    //check real y upper bound
    if (gaussian((double)xMax) > gaussian((double)xMin))
        yBound = gaussian((double)xMax);
    else
        yBound = gaussian((double)xMin);

    for (int i = 0; i < numTrials; i++) {
        xRand = (rand()% ((xMax-xMin)*1000 + 1))/1000.00 + xMin; //generate random x value between xMin and xMax to 3 decimal places
        yRand = (rand()% (int)(yBound*1000 + 1))/1000.00; //generate random y value between 0 and yBound to 3 decimal places
        yReal = xRand;
        if (yRand < yReal)
            countY++;
    }

    valIntegral = (xMax-xMin)*((double)countY/numTrials);

    printf("********************************************************************\n\n");
    printf("Integral of f(x) =x on [%.3lf, %.3lf] with n = %d trials is: %.3lf\n", (double)xMin, (double)xMax, numTrials, valIntegral);
    printf("********************************************************************\n");
    return 0;
}
