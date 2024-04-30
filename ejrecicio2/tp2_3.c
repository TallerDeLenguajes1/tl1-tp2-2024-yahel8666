/*Queremos imprimir una matriz de orden N*M usando punteros */

#include <stdio.h>
#define N 5
#define M 7

int main(int argc, char const *argv[])
{ 
    int i,j;
    int mt[N][M]; //matriz 
    int *punt = mt; // puntero a  matriz
    

    for(i = 0; i<N; i++)
    {
        for(j = 0; j<M; j++) 
        {
           printf("%d", *(punt + i*M + j)); 
        }
    }
    
}