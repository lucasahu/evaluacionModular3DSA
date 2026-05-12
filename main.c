#include <stdio.h>
#define MAX_ZONAS 15

/* struct principal */
struct Parque {
    struct Zona *zonas[MAX_ZONAS];/* arreglo no dinamico de zonas */
    int cantidadZonas;
    int visitantesHoy;
    struct NodoUsuario *headUsuarios; /* lista simple enlazada de usuarios */
    struct NodoEntrada *headEntradas; /* arbol binario de busqueda de entradas */
};

struct NodoEntrada {
    struct Entrada *datosEntrada; /* puntero a los datos de la entrada */
    struct NodoEntrada *izq, *der; /* puntero a los nodos del arbol de entradas */
};

struct Entrada {
    int id;
    int valor;
    int tipo; /* infantil, pase rapido,normal */
    int estado; /* vencida,usada,sin usar,reembolsada/anulada */
    struct Usuario *datosUsuario; /* puntero a los datos del usuario propietario */
};

struct NodoUsuario {
    struct Usuario *datosUsuario; /* puntero a los datos del usuario*/
    struct NodoUsuario *sig; /* putero al siguiente nodo de usuarios */
};

struct Usuario {
    char *nombre;
    int id;
    int edad;
    float estatura;
};

struct Zona {
    char *nombre;
    int codigo;
    char *tematica;
    struct NodoAtraccion *headAtracciones; /* lista doblemente enlazada de atracciones */
};

struct NodoAtraccion {
    struct Atraccion *datosAtraccion; /* puntero a datos */
    struct NodoAtraccion *sig, *ant;
};

struct Atraccion {
    char *nombre;
    int codigo;
    int capacidad;
    int ocupacionActual;
    int estado; /*en mantenimiento o funcionando */
    struct NodoFila *headFila; /* lista simple enlazada de fila */
};

struct NodoFila {
    struct Usuario *datosUsuario; /* puntero a los datos del usuario */
    struct NodoFila *sig; /* puntero al siguiente nodo de la fila */
};

/*main de test*/
int main(void) {
    printf("test\n");
    return 0;
}
