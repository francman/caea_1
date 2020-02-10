#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_EVENT 10000
#define MBIN 10

int main(int argc, char ** argv){

    //float binWidth = 1/(double)MBIN; //BIN_WIDTH
    float randomNumberArray[N_EVENT - 1] = {0};
    int binArray[MBIN-1] = {0};
    FILE *filePointer;

    //Opening file for storing random numbers
    filePointer = fopen("randomNumbers.dat", "w");
    //Seeding random randomNumbers
    srand(time(0));
    //Generating random numbers
    for (int i=0; i<N_EVENT;i++){
        randomNumberArray[i] = rand()/(float)RAND_MAX;
        fprintf(filePointer, "%f\n", randomNumberArray[i]);
    }

    //Closing file for storing random numbers
    fclose(filePointer);

return 0;
}
