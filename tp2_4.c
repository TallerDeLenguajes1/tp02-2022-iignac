#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMA 5 //constante: cantidad de compus del arreglo de estructuras

struct compu
{
    int velocidad; //entre 1 y 3 Gherz
    int anio; //entre 2000 y 2017
    int cantidad; //entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
}typedef compu;

void mostrarTodas(compu *pc);
void masVieja(compu pc[TAMA]);
void masVeloz(compu pc[TAMA]);
void mostrarEspecifica(compu a);

int main(){
    srand(time(NULL));
    compu pc[5];
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    //cargo el arreglo de estructuras con las caracteristicas de las 5 computadoras
    for (int i = 0; i < TAMA; i++)
    {
        pc[i].velocidad = 1+rand()%3;
        pc[i].anio = 2015+rand()%8;
        pc[i].cantidad = 1+rand()%8; 
        pc[i].tipo_cpu = &tipos[rand()%6][0];
        //asigno aleatoriamente al puntero "tipo_cpu" la direccion de memoria de un elemento del arreglo "tipos" 
    }
    /////////////
    
    mostrarTodas(pc);
    masVieja(pc);
    masVeloz(pc);

    return 0;
}

void mostrarTodas(compu pc[TAMA]){ //parametro igual a: compu *pc
    for (int i = 0; i < TAMA; i++)
    {   
        printf("-----------------------------\n");
        printf("CARACTERISTICAS DE LA PC %d:\n",i+1);
        printf("-----------------------------\n");
        printf("Velocidad de procesamiento: %d GHz\n",pc[i].velocidad);
        printf("Anio de fabricacion: %d\n",pc[i].anio);
        printf("Cantidad de nucleos: %d\n",pc[i].cantidad);
        printf("Tipo de procesador: %s\n",pc[i].tipo_cpu);
        printf("\n");
    }            
}

void masVieja(compu pc[TAMA]){
    compu vieja; //en struct vieja guardare la compu mas vieja
    vieja = pc[0]; 
    int aux=0;

    for (int i = 1; i < TAMA; i++)
    {
        if (pc[i].anio < vieja.anio)
        {
            vieja = pc[i];
            aux = i;
        }
    }
    printf("<====== LA PC MAS VIEJA ES LA NUMERO: %d ======>\n",aux+1);
    mostrarEspecifica(vieja);
}

void masVeloz(compu pc[TAMA]){
    compu veloz; //en struct veloz guardare la compu mas veloz
    veloz = pc[0];
    int aux=0;

    for (int i = 1; i < TAMA; i++)
    {
        if (pc[i].velocidad > veloz.velocidad)
        {
            veloz = pc[i];
            aux = i;
        }
    }
    printf("<====== LA PC MAS VELOZ ES LA NUMERO: %d ======>\n",aux+1);
    mostrarEspecifica(veloz);
}

void mostrarEspecifica(compu a){
    printf("CARACTERISTICAS:\n");
    printf("Velocidad de procesamiento: %d GHz\n",a.velocidad);
    printf("Anio de fabricacion: %d\n",a.anio);
    printf("Cantidad de nucleos: %d\n",a.cantidad);
    printf("Tipo de procesador: %s\n",a.tipo_cpu);
    printf("\n");
}



