#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include <string.h>

void cargarArreglo(Tveteranos veteranos)
{
    FILE *f;
    Tpersona aux;
    veteranos->cant = 0;
    f = fopen("malvinas.dat", "r");

    while (!feof(f))
    {
        fread(f, sizeof(Tpersona), 1, &aux);
        veteranos->personas[veteranos->cant + 1] = aux;
        veteranos->cant++;
    }
    fclose(f);
}

void cargarArchivo(const Tveteranos veteranos)
{
    FILE *f;
    Tpersona aux;
    int pos;

    f = fopen("malvinas.dat", "w");
    for (pos = 0; pos < veteranos->cant; pos++)
    {
        aux = veteranos->personas[pos];
        fwrite(f, sizeof(Tpersona), 1, &aux);
    }

    fclose(f);
}
Logico vacia(const Tveteranos veteranos)
{

    if (veteranos->cant == 0)
    {
        return VERDADERO;
    }
    else
    {
        return FALSO;
    }
}
Logico llena(const Tveteranos veteranos)
{
    if (veteranos->cant = NMAX)
    {
        return VERDADERO;
    }
    else
    {

        return FALSO;
    }
}
Logico validacionFecha(Tfecha fecha){

    if (fecha.mes < 0 || fecha.mes >12 || ) {
        return Falso;
    }
    if (fecha.mes != 1 || fecha.mes != 3 || fecha.mes != 5 || fecha.mes != 7 ||
            fecha.mes != 8 || fecha.mes != 10 || fecha.mes != 12){
        return FALSO;
    }
    if (fecha.mes == 2 && ((fecha.anio%4 == 0 && !(fecha.anio%100 == 0)) || 
            (fecha.anio%100 == 0 && fecha.anio%400 == 0)) && fecha.dia > 29){
        return FALSO;
    }
    if (fecha.mes == 2 && !((fecha.anio%4 == 0 && !(fecha.anio%100 == 0)) || 
            (fecha.anio%100 == 0 && fecha.anio%400 == 0)) && fecha.dia > 28){
        return FALSO;
    }
    
    return VERDADERO;
}

int buscarPosicion(const Tveteranos veteranos, const Tpersona *persona){
    int pos = 0;
    Logico posEncontrada = FALSO;

    while (strcmp(persona->apellido, veteranos->personas[pos].apellido) == 1 && pos < veteranos.cant)
        pos++;

    if (strcmp(persona->apellido, veteranos->personas[pos].apellido) == 0){
        do {
            if (strcmp(persona->nombre, veteranos->personas[pos].nombre) == -1)
                posEncontrada = VERDADERO;
            else if (strcmp(persona->nombre, veteranos->personas[pos].nombre) == 1)
                pos++;
            else {
                if (persona.DNI < veteranos->personas[pos].DNI)
                    posEncontrada = VERDADERO;
                else if (persona.DNI > veteranos->personas[pos].DNI)
                    pos++;
                else printf("DNI Repetido, operacion fallida");
            }
        } while (pos <= veteranos->cant || strcmp(persona.apellido, veteranos->personas[pos].apellido) == 0 || posEncontrada == VERDADERO);
    }
    return pos;
}

Logico dniRepetido(const Tveteranos, int dni){
    int pos = 0;
    while (pos < veteranos->cant){
        if (dni == veteranos->personas[pos].DNI)
            return VERDADERO;
        pos++;
    }
    return FALSO;
}

void cargarDatos(Tpersona* nuevo){
    int opcion;

    printf("Ingrese el nombre");
    fgets(nuevo->nombre, 20, stdin);
    nuevo->nombre[strlen(nuevo->nombre)-1] = '/0';

    printf("Ingrese el apellido");
    fgets(nuevo->apellido, 20, stdin);
    nuevo->apellido[strlen(nuevo->apellido)-1] = '/0';

    do{
        printf("Ingrese el DNI: ");
        scanf("%d", &nuevo->DNI);
        fgetc(stdin);
    } while (dniRepetido(nuevo->DNI));

    do {
        printf("Ingrese el dia de nacimiento: ");
        scanf("%d", &nuevo->nacimiento.dia);

        printf("Ingrese el mes de nacimiento: ");
        scanf("%d", &nuevo->nacimiento.mes);

        printf("Ingrese el año de nacimiento: ");
        scanf("%d", &nuevo->nacimiento.anio);
        fgetc(stdin);
    } while (!validacionFecha(nuevo->nacimiento));

    printf("Ingrese el ciudad");
    fgets(nuevo->ciudad, 20, stdin);
    nuevo->ciudad[strlen(nuevo->ciudad)-1] = '/0';

    printf("Ingrese el ciudad antes");
    fgets(nuevo->ciudadAntes, 20, stdin);
    nuevo->ciudadAntes[strlen(nuevo->ciudadAntes)-1] = '/0';

    printf("Ingrese el dirección postal");
    fgets(nuevo->DP, 30, stdin);
    nuevo->DP[strlen(nuevo->DP)-1] = '/0';

    printf("Ingrese el correo electrónico");
    fgets(nuevo->CE, 20, stdin);
    nuevo->CE[strlen(nuevo->CE)-1] = '/0';

    printf("Ingrese el teléfono");
    fgets(nuevo->tel, 15, stdin);
    nuevo->tel[strlen(nuevo->tel)-1] = '/0';

    do{
        printf("Fallecido (0), vivo (1)");
        scanf("%d", &opcion);
        fgetc(stdin);
        switch (opcion){
            case 0:
                nuevo->VF = FALSO;
                break;
            case 1:
                nuevo->VF = VERDADERO;
                break,
            default:
                printf("Opcion incorrecta\n");
                break;
    } while (opcion != 0 || opcion != 1);

    if (!nuevo->VF){
        do {
            printf("Ingrese el dia de fallecimiento: ");
            scanf("%d", &nuevo->fallecimiento.dia);

            printf("Ingrese el mes de fallecimiento: ");
            scanf("%d", &nuevo->fallecimiento.mes);

            printf("Ingrese el año de fallecimiento: ");
            scanf("%d", &nuevo->fallecimiento.anio);
        } while (!validacionFecha(nuevo->fallecimiento));
    }

    printf("Ingrese el beneficio");
    fgets(nuevo->beneficio, 20, stdin);
    nuevo->beneficio[strlen(nuevo->beneficio)-1] = '/0';

    printf("Ingrese el codigo posta");
    fgets(nuevo->CP, 10, stdin);
    nuevo->CP[strlen(nuevo->CP)-1] = '/0';

    printf("Ingrese la provincia");
    fgets(nuevo->provincia, 50, stdin);
    nuevo->provincia[strlen(nuevo->provincia)-1] = '/0';

    do{
        printf("Ingrese la fuerza a la que pertenecio:\n");
        printf("1) Marina\n");
        printf("2) Gendarmeria\n");
        printf("3) Ejército\n");
        printf("4) Aeronáutica\n");
        scanf("%d", &opcion);
        fgetc(stdin);
        switch (opcion){
            case MARINA:
                nuevo->fuerza = MARINA;
                break;
            case GENDARMERIA:
                nuevo->fuerza = GENDARMERIA;
                break;
            case EJERCITO:
                nuevo->fuerza = EJERCITO;
                break;
            case AERONAUTICA:
                nuevo->fuerza = AERONAUTICA;
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
    } while (opcion < 1 || opcion > 4);

    printf("Ingrese el destino malvinas");
    fgets(nuevo->destino, 50, stdin);
    nuevo->destino[strlen(nuevo->destino)-1] = '/0';

    printf("Ingrese el funcion malvinas");
    fgets(nuevo->funcionMalvinas, 100, stdin);
    nuevo->funcionMalvinas[strlen(nuevo->funcionMalvinas)-1] = '/0';

    printf("Ingrese el grado");
    fgets(nuevo->grado, 20, stdin);
    nuevo->grado[strlen(nuevo->grado)-1] = '/0';

    printf("Ingrese el secuelas");
    fgets(nuevo->secuelas, 200, stdin);
    nuevo->secuelas[strlen(nuevo->secuelas)-1] = '/0';
}

void insertar(Tveteranos veteranos){
    Tpersona nuevo;
    int pos, aux;

    if (llena(veteranos))
        printf("No es posible agregar miembros, lista llena");
    else {
        cargarDatos(&nuevo);
        pos = buscarPosicion(veteranos, &nuevo);
        for (aux = veteranos->cant -1; pos <= aux, aux--)
            veteranos->personas[aux+1] = veteranos->personas[aux];
        veteranos->personas[pos] = nuevo;
        veteranos->cant++;
    }
}

void suprimir(Tveteranos, int dni);
void mostrar(const Tveteranos);
void mostrarPorApellido(const Tveteranos, char *apellido);
void modificar(Tveteranos, int dni);
void mostrarFallecidos(const Tveteranos);
void mostrarPorFuerza(const Tveteranos, Tfuerza fuerza);
