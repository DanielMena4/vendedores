
#include "funciones.h"

int main()
{
    int opc;
    do
    {
        fflush(stdin);
        printf("\n\t :MENU: \n");
        printf("1.Crear\n2.Agregar\n3.Visualizar\n4.Salir\n");
        printf("\nOpcion : ");
        scanf("%i",&opc);
        
        switch (opc)
        {
        case 1:
            crear();
            break;
        case 2:
            agregar();
            break;
        case 3:
            visualizar();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Ingrese una opcion valida");
            break;
        }
    } while (opc != 4);
}
