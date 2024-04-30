#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
    int i;
    double vt[N];
    double * pvector = vt; 
    srand(time(NULL)); 
    for(i=0; i<N; i++)
    {
        *(pvector+i)=rand()%101;
        printf("%f \n", *(pvector+i));
    }
    return 0;
}
