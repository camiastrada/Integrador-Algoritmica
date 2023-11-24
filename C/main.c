#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

int opcion;
Tfuerza fuerza; 
Logico salir;
Tveteranos veteranos;
char apellido[20];
int dni, mes;

void main()
{
    cargarArreglo(&veteranos);

    do {
        menu(&opcion);
        switch (opcion){
            case INSERTAR:
                insertar(veteranos);
                break;
            case ELIMINAR:
                printf("Ingrese DNI: ");
                scanf("%d", &dni);
                fgetc(stdin);
                suprimir(veteranos, dni);
                break;
            case MODIFICAR:
                printf("Ingrese DNI: ");
                scanf("%d", &dni);
                fgetc(stdin);
                modificar(veteranos, dni);
                break;
            case LISTODO:
                mostrar(veteranos);
                break;
            case LISAPELLIDO:
                break;
            case LISFALLECIDOS:
                break;
            case LISFUERZA:
                break;
            case LISPORMES:
                break;
            case SALIR:
                break;
        }
    } while (opcion !=SALIR);

}
