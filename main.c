#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
};

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

void inicializarParque(struct Parque *parque) {
    int i;
    /* funcion de inicializado de parque 0 o null hasta input del usuario*/
    parque->cantidadZonas = 0;
    parque->visitantesHoy = 0;
    parque->headUsuarios = NULL;
    parque->raizEntradas = NULL;

    for (i = 0; i < MAX_ZONAS; i++) {
        parque->zonas[i] = NULL;
    }
}

void menuIBCLandia(struct Parque *parque) {
    int num;

    do {
        printf("Bienvenido al menu!\n");
        printf("1. Menu de usuarios\n");
        printf("2. Menu de entradas\n");
        printf("3. Menu de zonas\n");
        printf("4. Menu de atracciones\n");
        printf("5. Menu de filas\n");
        printf("6. Menu de reportes\n");
        printf("7. Salir del menu\n");
        printf("Porfavor digite una opcion valida del menu: ");

        scanf(" %d", &num);

        switch (num) {
            default:
                printf("opcion no valida, mejor suerte a la proxima!");
                break;
            case 1:
                printf("usuarios no listo aun");
                break;
            case 2:
                printf("entradas no listo aun");
                break;
            case 3:
                printf("zonas no listo aun");
                break;
            case 4:
                printf("atracciones no listo aun");
                break;
            case 5:
                printf("filas no listo aun");
                break;
            case 6:
                printf("reportes no disponibles");
                break;
            case 7:
                printf("Esperamos hayas disfrutado de IBCLandia!");
                break;
        }
    }while (num != 7);
}


int main(void) {
    struct Parque *parque;
    parque = (struct Parque *)malloc(sizeof(struct Parque))

    if (parque == NULL) {
        printf("No se pudo crear el parque.");
        return 0;
    }

    inicializarParque(parque);
    menuIBCLandia(parque);

    return 0;
}
