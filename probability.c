#include <stdio.h>
#include <math.h>

#define N_EVENT 10000

int main(int argc, char** argv[]){

    int randomNumberArray[N_EVENT - 1];

    for (int i=0; i<N_EVENT;i++){
        randomNumberArray[i] = rand()/RAND_MAX;
    }

}