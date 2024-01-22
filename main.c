
#include "funciones.h"

int main() {
    FILE *archivo;
    FILE *archivoBajas;
    FILE *archivoCambiosSueldo;
    FILE *archivoCambiosHoras;

    archivo = fopen("empleados.txt", "a+");
    archivoBajas = fopen("empleados_bajas.txt", "a+");
    archivoCambiosSueldo = fopen("empleados_cambios_sueldo.txt", "a+");
    archivoCambiosHoras = fopen("empleados_cambios_horas.txt", "a+");

    if (archivo == NULL || archivoBajas == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    int opcion;
    int contadorId = 1;

    while (opcion != 8) {
        printf("\nMenu:\n");
        printf("1 - Alta empleado\n");
        printf("2 - Baja empleado\n");
        printf("3 - Lista de empleados\n");
        printf("4 - Consultar datos de empleado\n");
        printf("5 - Modificar salario\n");
        printf("6 - Modificar horas\n");
        printf("7 - Consultar modificaciones\n");
        printf("8 - Salir\n");

        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                altaEmpleado(archivo, &contadorId);
                break;
            case 2:
                bajaEmpleado(archivo, archivoBajas);
                break;
            case 3:
                listaEmpleados(archivo);
                break;
            case 4:
                consultarDatos(archivo);
                break;
            case 5:
                modificarSalario(archivo, archivoCambiosSueldo);
                break;
            case 6:
                modificarHoras(archivo, archivoCambiosHoras);
                break;
            case 7:
                 consultarModificaciones(archivoBajas, archivoCambiosSueldo, archivoCambiosHoras);
                break;
            case 8:
                break;
            default:
                printf("Opcion no valida.\n");
        }

        rewind(archivo);
        rewind(archivoBajas);
        rewind(archivoCambiosSueldo);
        rewind(archivoCambiosHoras);
    }

    fclose(archivo);
    fclose(archivoBajas);
    fclose(archivoCambiosSueldo);
    rewind(archivoCambiosHoras);

    return 0;
}
