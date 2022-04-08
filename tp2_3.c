#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main(){
    int i,j;
    int mt[N][M];
    int *punt;

    punt = &mt[0][0]; // si asigno: punt=mt se genera un warning   

    srand(time(NULL));

    for(i = 0;i<N; i++)
    {
        for(j = 0;j<M; j++) //i=3 M=7 j=1
        {
            *(punt+(i*M+j))=1+rand()%100;
            printf("%2d   ", *(punt+(i*M+j)));
        }
        printf("\n");
    }

    return 0;
}

