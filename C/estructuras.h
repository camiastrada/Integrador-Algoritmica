#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define NMAX 250

typedef enum {FALSO, VERDADERO} Logico;

typedef struct Tfecha_{
    int dia;
    int mes;
    int año;
} Tfecha;

typedef enum {MARINA, GENDARMERIA, EJERCITO, AERONAUTICA} Tfuerza;

typedef struct Tpersona_{
    int DNI;
    char nombre[20];
    char apellido[20];
    Tfecha nacimiento;
    int edad;
    char ciudad[20];
    char ciudadAntes[20];
    char DP[30];
    char CE[20];
    char tel[15];
    Logico VF;
    Tfecha fallecimiento;
    char beneficio[20];
    char CP[10];
    char provincia[50];
    Tfuerza fuerza;
    char destino[50];
    char funcionMalvinas[100];
    char grado[20];
    char secuelas[200];
} Tpersona;

struct Tveteranos_{
    Tpersona personas[NMAX];
    int cant;
};

typedef struct Tveteranos_* Tveteranos;

typedef struct Tfallecidos_{
    Tpersona info;
    Tpersona* next;
} Tfallecidos;

typedef struct TlistaFuerza_{
    Tpersona persona;
    Tpersona* back;
    Tpersona* next;
} TlistaFuerza;

void inicializarVeteranos(Tveteranos);
void cargarArreglo(const Tveteranos);
void cargarArchivo(const Tveteranos);
Logico vacia(const Tveteranos);
Logico llena(const Tveteranos);
Logico validacionFecha(Tfecha);
int buscarPosicion(const Tveteranos, const Tpersona*);
void insertar(Tveteranos);
void suprimir(Tveteranos, int dni);
void mostrar(const Tveteranos);
void mostrarPorApellido(const Tveteranos, char* apellido);
void modificar(Tveteranos, int dni);
void mostrarFallecidos(const Tveteranos);
void mostrarPorFuerza(const Tveteranos, Tfuerza fuerza);

#endif
