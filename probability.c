#include <stdio.h>
#include <stdlib.h>

int binSorter(float randomNumber);

#define N_EVENT 10000
#define MBIN 10

int main(int argc, char** argv[]){

    float binWidth = 1/(double)MBIN; //BIN_WIDTH
    float randomNumberArray[N_EVENT - 1] = {0};
    int binArray[MBIN-1] = {0};
    FILE *filePointer;


//Generating random numbers
    for (int i=0; i<N_EVENT;i++){
        randomNumberArray[i] = rand()/(float)RAND_MAX;
        printf("%f", randomNumberArray[i]);
        binArray[binSorter(randomNumberArray[i])] += 1;
        filePointer = fopen("random", "a+");
        fwrite(&randomNumberArray[i], sizeof(float), 1, filePointer);
        fprintf(filePointer,"\n");
        fclose(filePointer);
    }

    printf("%ld\n", sizeof(randomNumberArray));
    for(int i =0; i<MBIN; i++){
      printf("Bin # %d has %d \n", i, binArray[i]);
    }

return 0;
}



int binSorter(float randomNumber){
  int bin = 0;

  if ((randomNumber > 0) && (randomNumber <= 0.1)){
      bin = 0;
  }
  else if ((randomNumber > 0.1) && (randomNumber <= 0.2)){
      bin = 1;
  }
  else if ((randomNumber > 0.2) && (randomNumber <= 0.3)){
      bin = 2;
  }
  else if ((randomNumber > 0.3) && (randomNumber <= 0.4)){
      bin = 3;
  }
  else if ((randomNumber > 0.4) && (randomNumber <= 0.5)){
      bin = 4;
  }
  else if ((randomNumber > 0.5) && (randomNumber <= 0.6)){
      bin = 5;
  }
  else if ((randomNumber > 0.6) && (randomNumber <= 0.7)){
      bin = 6;
  }
  else if ((randomNumber > 0.7) && (randomNumber <= 0.8)){
      bin = 7;
  }
  else if ((randomNumber > 0.8) && (randomNumber <= 0.9)){
      bin = 8;
  }
  else if ((randomNumber > 0.9) && (randomNumber <= 1.0)){
      bin = 9;
  }

  return bin;
}
