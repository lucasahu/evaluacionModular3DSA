#include <stdio.h>
#define MAX_ZONAS 15

/* struct principal */
struct Parque {
    struct Zona *zonas[MAX_ZONAS];/* arreglo no dinamico de zonas */
    int cantidadZonas;
    int visitantesHoy;
    struct NodoUsuario *headUsuarios; /* lista simple enlazada de usuarios */
    struct NodoEntrada *raizEntradas; /* arbol binario de busqueda de entradas */
};

struct NodoEntrada {
    struct Entrada *datosEntrada; /* puntero a los datos de la entrada */
    struct NodoEntrada *izq, *der; /* puntero a los nodos del arbol de entradas */
};

struct Entrada {
    int id;
    int valor;
    int tipo; /* infantil, pase rapido,normal,familiar */
    int estado; /* activa,utilizada,anunalada o vencida */
    struct NodoUsuarioEntrada *headUsuarios; /* lista simplemente enlazada de los usuarios linkeados a esta entrada */
};

struct NodoUsuarioEntrada {
    struct Usuario *datosUsuario;
    struct NodoUsuarioEntrada *sig;
}

struct NodoUsuario {
    struct Usuario *datosUsuario; /* puntero a los datos del usuario*/
    struct NodoUsuario *sig; /* puntero al siguiente nodo de usuarios */
};

struct Usuario {
    char *nombre;
    int id;
    int edad;
    int estaEnParque; /* esta o no en el parque */
    int estuvoEnParque; /* estuvo o no en el parque */
    float estatura;
};

struct Zona {
    char *nombre;
    int codigo;
    char *tematica;
    int capacidadMax;
    int ocupacionActual;
    char *horario;
    struct NodoAtraccion *headAtracciones; /* lista doblemente enlazada de atracciones con nodo fantasma */
};

struct NodoAtraccion {
    struct Atraccion *datosAtraccion; /* puntero a datos */
    struct NodoAtraccion *sig, *ant;
};

struct Atraccion {
    char *nombre;
    int codigo;
    int capacidadMax;
    int ocupacionActual;
    int estado; /*en mantenimiento o funcionando */
    struct NodoFila *headFila; /* lista simple enlazada de fila con nodo fantasma */
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
