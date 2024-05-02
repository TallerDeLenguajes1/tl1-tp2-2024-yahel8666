#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 5

struct 
{
    int velocidad; //entre 1 y 3 GHz
    int anio; //entre 2015 y 2023
    int cantidad; //entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos. 
} typedef Compu;

// prototipo de funciones 
Compu cargarDatos(); 
void mostrarPC(Compu array[5]); 
void pcMasVieja(Compu computadoras[5]); 
void pcMayorVelocidad(Compu computadoras[5]);

int main()
{
    srand(time(NULL)); 

    //carga de arreglo de estructura.
    Compu computadoras[5]; 
    for (int i = 0; i < 5; i++)
    {
        computadoras[i] = cargarDatos(); 
    }

    //funcion que presente la lista de PC y sus caracteristicas
    mostrarPC(computadoras); 

    //funcion que presente la pc mas vieja: 
    pcMasVieja(computadoras); 

    //fncn que presente a la pc con mayor velocidad: 
    pcMayorVelocidad(computadoras); 
    
    return 0; 
}

Compu cargarDatos()
{
    /* Aqui, 6 es la cantidad de palabras, y 10 es la cantidad max de letras de c/u */
    char tipos[6][10]={"Intel", "AMD", "Celeron", "athlon", "Core","Pentium"};
    Compu aux; 
    aux.velocidad = rand()%3+1;
    aux.anio = rand()%(2023-2015+1)+2015;
    aux.cantidad = rand()%9; 
    aux.tipo_cpu = tipos[rand() % 6]; // así elijo uno de los componentes del arreglo. 
    return aux;
}

void mostrarPC(Compu array[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n ---PC: %d---", i+1);
        printf("\n Velocidad: %d", array[i].velocidad);
        printf("\n Anio:  %d", array[i].anio);
        printf("\nTipo de CPU: %s", array[i].tipo_cpu);
        printf("\n Cantidad:  %d", array[i].cantidad);
        printf("\n");
    }
}

void pcMasVieja(Compu computadoras[5])
{
    //comparo directamente con la primer compu del arreglo
    //inicializo mi variable para comparar con el valor de la primera componente
    int anioMasViejo=computadoras[0].anio;
    int indicePcMasVieja = 0;

    for (int i = 1; i < 5; i++)
    {
        if (computadoras[i].anio < anioMasViejo)
        {
            anioMasViejo=computadoras[i].anio;
            indicePcMasVieja = i;
        }
    }

    printf("La PC mas vieja es la PC %d", indicePcMasVieja+1); 
}

void pcMayorVelocidad(Compu computadoras[5])
{
    //supongo que mi primera compu tiene la mayor velocidad.
    int mayorVelocidad = computadoras[0].velocidad; 
    int indicePcMayorVel = 0; 

    for (int i = 1; i < 5; i++)
    {
        if (computadoras[i].velocidad > mayorVelocidad)
        {
            mayorVelocidad = computadoras[i].velocidad; 
            indicePcMayorVel = i; 
        }
    }
    printf("\n La PC con mayor velocidad es la PC:%d", indicePcMayorVel+1); 
}