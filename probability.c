#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_EVENT 10000
#define MBIN 10

int binContent(float randomNumber);

int main(int argc, char ** argv){

    //float binWidth = 1/(double)MBIN; //BIN_WIDTH
    float randomNumberArray[N_EVENT - 1] = {0};
    float binArray[MBIN-1] = {0};
    float pdf=0;
    FILE *filePointer;

    //Opening file for storing random numbers
    filePointer = fopen("randomNumbers.dat", "w");
    //Seeding random randomNumbers
    srand(time(0));
    //Generating random numbers
    for (int i=0; i<N_EVENT;i++){
        randomNumberArray[i] = rand()/(float)RAND_MAX;
        fprintf(filePointer, "%f\n", randomNumberArray[i]);
        binArray[binContent(randomNumberArray[i])] +=1;
    }
    //Closing file for storing random numbers
    fclose(filePointer);

    //PMF
    filePointer = fopen("pmf.dat", "w");

    for (int i=0; i < MBIN; i++){
      binArray[i] = binArray[i]/N_EVENT;
      fprintf(filePointer, "%2d\t%f\n", i+1, binArray[i]);
    }
    fclose(filePointer);

    //PDF
    for (int i=0; i < MBIN; i++){
      pdf += (binArray[i]);
    }
    printf("\n\n*************************\n");
    printf("The PDF is %.2f\n", pdf);
    printf("*************************\n\n");
return 0;
}


int binContent(float randomNumber){
  int bin = 0;

  if ((randomNumber > 0) && (randomNumber <=0.1)){
    bin=0;
  }
  else if ((randomNumber > 0.1) && (randomNumber <=0.2)){
    bin=1;
  }
  else if ((randomNumber > 0.2) && (randomNumber <=0.3)){
    bin=2;
  }
  else if ((randomNumber > 0.3) && (randomNumber <=0.4)){
    bin=3;
  }
  else if ((randomNumber > 0.4) && (randomNumber <=0.5)){
    bin=4;
  }
  else if ((randomNumber > 0.5) && (randomNumber <=0.6)){
    bin=5;
  }
  else if ((randomNumber > 0.6) && (randomNumber <=0.7)){
    bin=6;
  }
  else if ((randomNumber > 0.7) && (randomNumber <=0.8)){
    bin=7;
  }
  else if ((randomNumber > 0.8) && (randomNumber <=0.9)){
    bin=8;
  }
  else if ((randomNumber > 0.9) && (randomNumber <=1.0)){
    bin=9;
  }
  return bin;
}

//PDF 1/(B-A) where B=MAX A=MIN
