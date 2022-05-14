/*
 ============================================================================
 Name        : TP_2.c
 Author      : Nazareno Leone
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 2000 // Esto Deberia ir en 2000
int main()
{
	setbuf(stdout, NULL);
    char salir = 0;
    int proximoId = 1000;
    int altaFlag = 0;

    ePasajero  lista[TAM];    // tipoDeDato   nombreDelTipoDeDato
    initPassengers(lista, TAM);

    do
    {
        switch(menuPasajeros())
        {
        case 1:
            if(addPassengers(lista, TAM, &proximoId))
            {
                printf("Pasajero cargado con exito\n");
                altaFlag = 1;
            }
            else
            {
                printf("No se pudo cargar el pasajero\n");
            }
            break;
        case 2:
            if(altaFlag)
            {
                modificarPasajero (lista, TAM);
            }
            else
            {
                printf("Primero debe dar de alta al menos un pasajero\n");
            }
            break;
        case 3:
            if(altaFlag)
            {
                removePassenger(lista, TAM);
            }
            else
            {
                printf("Primero debe dar de alta al menos un pasajero\n");
            }
            break;
        case 4:
            if(altaFlag)
            {
                sortPassengers(lista, TAM);

                switch(menuOpcion4())
                {
                case 1:
                    ordenarPasajerosApellido(lista, TAM);
                    break;
                case 2:
                    promedioPasajes(lista, TAM);
                    break;
                case 3:
                    sortPassengersByCode(lista, TAM);
                    break;
                case 0:
                    printf("Volver al menu principal\n");
                    break;
                default:
                    printf("Opcion Invalida.\n");
                    break;
                }
            }
            else
            {
                printf("Primero debe dar de alta al menos un pasajero\n");
            }
            break;
        case 5:
            hardcodearPasajeros(lista, TAM);
            salir = 's';
            break;
        case 0:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');

    return EXIT_SUCCESS;
}

