#ifndef funciones_H_INCLUDED
#define funciones_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *archivo;

struct personal
{
    char nombre[50];
    char salario[20];
    char horas[20];

}info_personal;

void crear()
{
    char direccion [] = "D:\\informacion_personal";
    archivo = fopen(direccion, "wt");
    if (archivo == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    fprintf(archivo,"\t : Datos del personal : \n");
    printf("\n\t: Ingrese los datos del empleado: \n");
    
    fflush(stdin);
    printf("\nNombre: "); scanf("%s",info_personal.nombre);
    printf("\nhoras: "); scanf("%s",info_personal.horas);
    printf("\nsalario: "); scanf("%s",info_personal.salario);

    fprintf(archivo,"\n\nNombre : ");
    fwrite(info_personal.nombre,1,strlen(info_personal.nombre),archivo);

    fprintf(archivo,"\nhoras : ");
    fwrite(info_personal.horas,1,strlen(info_personal.horas),archivo);
        
    fprintf(archivo,"\nsalario : ");
    fwrite(info_personal.salario,1,strlen(info_personal.salario),archivo);
    
    fclose(archivo);   
}

void agregar()
{
    char direccion [] = "D:\\informacion_personal";
    char rpt = 's';
    archivo = fopen(direccion, "at");   
    if (archivo == NULL)
    {
        printf("Error al tratar de abrir el archivo");
        return 1;
    }
    printf("\n\t: Ingrese los datos del empleado: \n");
    do
    {
        printf("\nNombre: "); scanf("%s",info_personal.nombre);
        printf("\nhoras: "); scanf("%s",info_personal.horas);
        printf("\nsalario: "); scanf("%s",info_personal.salario);

        fprintf(archivo,"\n\nNombre : ");
        fwrite(info_personal.nombre,1,strlen(info_personal.nombre),archivo);

        fprintf(archivo,"\nhoras : ");
        fwrite(info_personal.horas,1,strlen(info_personal.horas),archivo);
        
        fprintf(archivo,"\nsalario : ");
        fwrite(info_personal.salario,1,strlen(info_personal.salario),archivo);
        fflush(stdin);

        printf("Desea agregar mas repuestos (s) : ");
        scanf("%c",&rpt);
    }while(rpt == 's');
    fclose(archivo);   
}

void visualizar()
{
    char direccion [] = "D:\\informacion_personal";
    int c;
    archivo = fopen(direccion, "r");   
    if (archivo == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    while ((c=fgetc(archivo))!=EOF)
    {
        if(c =='\n')
        {
            printf("\n");
        }
        else
        {
            putchar(c);
        }
    }
    
    fclose(archivo);   
}
#endif 