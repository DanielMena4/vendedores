#ifndef funciones_H_INCLUDED
#define funciones_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLEADOS 100

#include <stdio.h>
#include <stdlib.h>

void altaEmpleado(FILE *archivo, int *contadorId) {
    int ultimoID;
    int id1;

    // Inicializar el último ID en 0
    ultimoID = 0;

    // Buscar el último ID en el archivo
    while (fscanf(archivo, "%d,%*[^,],%*f,%*d\n", &id1) == 1) {
        ultimoID = id1;
    }

    // Obtener el último ID presente en el archivo
    //obtenerUltimoID(archivo, &ultimoID);

    // Asignar el siguiente ID al nuevo empleado
    int id = ultimoID + 1;

    char nombre[50];
    float sueldo;
    int horas;

    // Solicitar información del nuevo empleado
    printf("Ingrese el nombre del empleado: ");
    scanf("%s", nombre);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &sueldo);
    printf("Ingrese las horas semanales de trabajo: ");
    scanf("%d", &horas);

    // Escribir la información del nuevo empleado en el archivo
    fprintf(archivo, "%d,%s,%.2f,%d\n", id, nombre, sueldo, horas);
    printf("Empleado dado de alta con ID: %d\n", id);
}

void bajaEmpleado(FILE *archivo, FILE *archivoBajas) {

    int idBuscar;
    printf("Ingrese el ID del empleado a dar de baja: ");
    scanf("%d", &idBuscar);

    int id, encontrado = 0;
    char nombre[50];
    float sueldo;
    int horas;

    // Crear un archivo temporal para almacenar empleados temporales
    FILE *temporal = fopen("temporal.txt", "w");
    if (temporal == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        exit(1);
    }

    while (fscanf(archivo, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        if (id == idBuscar) {
            fprintf(archivoBajas, "%d,%s,%.2f,%d\n", id, nombre, sueldo, horas);
            encontrado = 1;
        } else {
            fprintf(temporal, "%d,%s,%.2f,%d\n", id, nombre, sueldo, horas);
        }
    }

    fclose(archivo);
    fclose(temporal);
    remove("empleados.txt");
    rename("temporal.txt", "empleados.txt");
    archivo = fopen("empleados.txt", "a+");

    if (encontrado) {
        printf("Empleado dado de baja exitosamente.\n");
    } else {
        printf("Empleado no encontrado.\n");
    }
}

void listaEmpleados(FILE *archivo) {
    int id;
    char nombre[50];
    float sueldo;
    int horas;

    printf("\nLista de empleados:\n");

    while (fscanf(archivo, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        printf("\nID: %d\n", id);
        printf("Nombre: %s\n", nombre);
        printf("Sueldo: %.2f\n", sueldo);
        printf("Horas semanales: %d\n", horas);
    }
}

void consultarDatos(FILE *archivo) {
    int idBuscar;
    printf("Ingrese el ID del empleado a consultar: ");
    scanf("%d", &idBuscar);

    int id, encontrado = 0;
    char nombre[50];
    float sueldo;
    int horas;

    while (fscanf(archivo, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        if (id == idBuscar) {
            printf("\nID: %d\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Sueldo: %.2f\n", sueldo);
            printf("Horas semanales: %d\n", horas);
            encontrado = 1;
            break;
        }
    }


    if (!encontrado) {
        printf("Empleado no encontrado.\n");
    }
}

void modificarSalario(FILE *archivo, FILE *archivoCambiosSueldo) {

    int idBuscar;
    printf("Ingrese el ID del empleado cuyo salario desea modificar: ");
    scanf("%d", &idBuscar);

    int id, encontrado = 0;
    char nombre[50];
    float sueldo;
    int horas;

    // Crear un archivo temporal para almacenar empleados temporales
    FILE *temporal = fopen("temporal.txt", "w");
    if (temporal == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        exit(1);
    }

    while (fscanf(archivo, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        if (id == idBuscar) {
            printf("Ingrese el nuevo salario: ");
            scanf("%f", &sueldo);
            encontrado = 1;
            fprintf(archivoCambiosSueldo, "%d,%s,%.2f,%d\n", id, nombre, sueldo, horas);
        }

        fprintf(temporal, "%d,%s,%.2f,%d\n", id, nombre, sueldo, horas);
    }

    fclose(archivo);
    fclose(temporal);

    remove("empleados.txt");
    rename("temporal.txt", "empleados.txt");
    archivo = fopen("empleados.txt", "a+");

    if (encontrado) {
        printf("Salario modificado exitosamente.\n");
    } else {
        printf("Empleado no encontrado.\n");
    }
}

void modificarHoras(FILE *archivo, FILE *archivoCambiosHoras) {
    int idBuscar;
    printf("Ingrese el ID del empleado cuyas horas desea modificar: ");
    scanf("%d", &idBuscar);

    int id, encontrado = 0;
    char nombre[50];
    float sueldo;
    int horas;

    // Crear un archivo temporal para almacenar empleados temporales
    FILE *temporal = fopen("temporal.txt", "w");
    if (temporal == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        exit(1);
    }

    while (fscanf(archivo, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        if (id == idBuscar) {
            printf("Ingrese las nuevas horas semanales: ");
            scanf("%d", &horas);
            encontrado = 1;
            fprintf(archivoCambiosHoras, "%d,%s,%.2f,%d\n", id, nombre, sueldo, horas);
        }

        fprintf(temporal, "%d,%s,%.2f,%d\n", id, nombre, sueldo, horas);
    }

    fclose(archivo);
    fclose(temporal);

    remove("empleados.txt");
    rename("temporal.txt", "empleados.txt");
    archivo = fopen("empleados.txt", "a+");

    if (encontrado) {
        printf("Horas modificadas exitosamente.\n");
    } else {
        printf("Empleado no encontrado.\n");
    }
}

void consultarModificaciones(FILE *archivoBajas, FILE *archivoCambiosSueldo, FILE *archivoCambiosHoras) {
    int id;
    char nombre[50];
    float sueldo;
    int horas;

    printf("\nLista de modificaciones:\n");

    printf("\nEmpleados dados de baja:\n");
    while (fscanf(archivoBajas, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        printf("\nID: %d\n", id);
        printf("Nombre: %s\n", nombre);
        printf("Sueldo: %.2f\n", sueldo);
        printf("Horas semanales: %d\n", horas);
    }

    printf("\nCambios de sueldo y horas:\n");
    while (fscanf(archivoCambiosHoras, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        printf("\nID: %d\n", id);
        printf("Nombre: %s\n", nombre);
        printf("Sueldo: %.2f\n", sueldo);
        printf("Horas semanales: %d\n", horas);
    }

    printf("\nCambios de horas:\n");
    while (fscanf(archivoCambiosSueldo, "%d,%[^,],%f,%d\n", &id, nombre, &sueldo, &horas) == 4) {
        printf("\nID: %d\n", id);
        printf("Nombre: %s\n", nombre);
        printf("Sueldo: %.2f\n", sueldo);
        printf("Horas semanales: %d\n", horas);
    }
}
#endif 
