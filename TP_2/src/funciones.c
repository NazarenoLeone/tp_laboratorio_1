/*
 * funciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int menuPasajeros()
{
    int opcion;

    system("cls");
    printf("    *** ABM Pasajeros ***\n\n");
    printf("1- Alta pasajero\n");
    printf("2- Modificar pasajero\n");
    printf("3- Baja Pasajeros\n");
    printf("4- Listar Pasajeros\n");
    printf("5- Carga Forzada\n");
    printf("0- Salir\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

// Funcion para inicializar los espacios de cada pasajero
// asignandole el valor 1 a isEmpty
int initPassengers(ePasajero vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

// Funcion que Obtiene los datos de un pasajero y los asigna a un ID mediante el puntero pNextId
int addPassengers(ePasajero vec[], int tam, int* pNextId)
{
    int todoOk = 0;
    int indice;
    ePasajero nuevoPasajero;

    if( vec != NULL && pNextId != NULL && tam > 0)
    {
        system("cls");
        printf("    *** Alta Pasajero ***\n");
        buscarLibre(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoPasajero.id = *pNextId;

            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(nuevoPasajero.name);
            while(!isalpha(*nuevoPasajero.name))
            {
                printf("ERROR\n");
                printf("Ingrese Nombre: ");
                fflush(stdin);
                gets(nuevoPasajero.name);
            }

            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(nuevoPasajero.lastname);
            while(!isalpha(*nuevoPasajero.lastname))
            {
                printf("ERROR\n");
                printf("Ingrese Apellido: ");
                fflush(stdin);
                gets(nuevoPasajero.lastname);
            }

            printf("Ingrese Precio: ");
            fflush(stdin);
            while((scanf("%f", &nuevoPasajero.price)) == 0)
            {
                printf("ERROR\n");
                printf("Ingrese Precio: ");
                fflush(stdin);
            }

            printf("Ingrese Tipo de Pasajero:\n1- Economica\n2- Primera\n3- Business\n");
            while((scanf("%d", &nuevoPasajero.typePassenger)) == 0 )
            {
                printf("ERROR\n");
                printf("Ingrese Tipo de Pasajero:\n1- Economica\n2- Primera\n3- Business\n");
                fflush(stdin);
            }
            while(nuevoPasajero.typePassenger != 1 && nuevoPasajero.typePassenger != 2 && nuevoPasajero.typePassenger != 3)
            {
                printf("ERROR\n");
                printf("Ingrese Tipo de Pasajero:\n1- Economica\n2- Primera\n3- Business\n");
                scanf("%d", &nuevoPasajero.typePassenger);
            }
            switch(nuevoPasajero.typePassenger)
            {
            case 1:
                *nuevoPasajero.tipoPasajero = "Economica";
                break;
            case 2:
                *nuevoPasajero.tipoPasajero = "Primera";
                break;
            case 3:
                *nuevoPasajero.tipoPasajero = "Business";
                break;
            default:
                printf("Dato invalido.");
                break;
            }

            printf("Ingrese Codigo de Vuelo: ");
            fflush(stdin);
            gets(nuevoPasajero.flycode);
            while(!isalpha(*nuevoPasajero.flycode))
            {
                printf("ERROR\n");
                printf("Ingrese Codigo de Vuelo: ");
                fflush(stdin);
                gets(nuevoPasajero.flycode);
            }

            printf("Ingrese Estado del vuelo:\n1- Activo\n2- Demorado\n3- Cancelado\n");

            while((scanf("%d", &nuevoPasajero.statusFlight)) == 0 )
            {
                printf("ERROR\n");
                printf("Ingrese Estado del vuelo:\n1- Activo\n2- Demorado\n3- Cancelado\n");
                fflush(stdin);
            }
            while(nuevoPasajero.statusFlight != 1 && nuevoPasajero.statusFlight != 2 && nuevoPasajero.statusFlight != 3)
            {
                printf("ERROR\n");
                printf("Ingrese Estado del vuelo:\n1- Activo\n2- Demorado\n3- Cancelado\n");
                scanf("%d", &nuevoPasajero.statusFlight);
            }
            switch(nuevoPasajero.statusFlight)
            {
            case 1:
                *nuevoPasajero.estadoVuelo = "Activo";
                break;
            case 2:
                *nuevoPasajero.estadoVuelo = "Demorado";
                break;
            case 3:
                *nuevoPasajero.estadoVuelo = "Cancelado";
                break;
            default:
                printf("Dato invalido.");
                break;
            }

            nuevoPasajero.isEmpty = 0;

            vec[indice] = nuevoPasajero;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarLibre(ePasajero vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

// Funcion que muestra los datos de cada pasajero
// dentro de la funcion listarPasajeros
void printPassengers(ePasajero pas)
{
    if(*pas.estadoVuelo == NULL)
    {
        *pas.estadoVuelo = "Activo";
    }
    if(*pas.tipoPasajero == NULL)
    {
        *pas.tipoPasajero = "Economica";
    }
    printf(" %5d %10s %10s %10.2f %14s %15s %15s\n", pas.id, pas.name, pas.lastname, pas.price, *pas.tipoPasajero, pas.flycode, *pas.estadoVuelo);
}

// Funcion que muestra el listado y datos de los pasajeros
int sortPassengers(ePasajero vec[], int tam)
{
    int todoOk = 0;
    int flag = 1;

    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("        *** Listado de Pasajeros ***\n");
        printf("    ID     Nombre   Apellido     Precio  Tipo de Vuelo Codigo de Vuelo Estado de Vuelo\n");
        printf("------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                printPassengers(vec[i]);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("    No hay Pasajeros en el sistema\n");
        }
        todoOk = 1;
    }

    return todoOk;
}


// Funcion Para la Carga Forzada y Testeos
int hardcodearPasajeros(ePasajero vec[], int tam)
{
    int todoOk = 1;

    ePasajero pasajeros[50] =
    {
        {1000, "Angie", "Silva", 500000, "MDQ1979"},
        {1001, "Matias", "Rados", 570000, "ARG3556"},
        {1002, "Federico", "Gutierrez", 780000, "CHI5764"},
        {1003, "Jimena", "Rodriguez", 715000, "URU8479"},
        {1004, "Marta", "Perez", 150000, "FRA2578"},
        {1005, "Ezequiel", "Ledesma", 650000, "ESP1063"},
        {1006, "Juan", "Paolucci", 459000, "JPN7912"},
        {1007, "Judith", "Mansilla", 440000, "MDQ3467"},
        {1008, "Luffy", "Monkey D.", 487000, "ONE3D2Y"},
        {1009, "Martin", "Palermo", 590000, "CBJ0009"}
    };
    sortPassengers(pasajeros, 10);
    return todoOk;
}

// Funcion que recorre en busca de coincidencia con ID
int findPassengerById(ePasajero vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

// Funcion para dar de baja a un pasajero
// el usuario ingresa un numero de Id,
// la funcion hace un recorrido mediante la funcion findPassengerById
// Si encuentra un Id que coincida lo elimina
int removePassenger(ePasajero vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if( vec != NULL && tam > 0 )
    {
        sortPassengers(vec, tam );
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(findPassengerById(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No existe un pasajero con id: %d en el sistema\n", id);
            }
            else
            {
                mostrarPasajero(vec[indice]);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                }
                else if(confirma == 'n' || confirma == 'N')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    printf("Dato Invalido.\n");
                }

            }
            todoOk = 1;
        }

    }
    return todoOk;
}
////////////////////////////////////////////////////////////////////////////////////////

int modificarPasajero (ePasajero vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxCad[100];
    float price;
    int tipoPas;
    int estadoVuelo;
    ePasajero nuevoPasajero;

    if( vec != NULL && tam > 0 )
    {
        sortPassengers(vec, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( findPassengerById(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe un pasajero con id %d en el sistema\n", id);
            }
            else
            {

                mostrarPasajero(vec[indice]);

                switch(menuModificarPasajero())
                {

                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                    //valido nombre

                    while(!isalpha(*auxCad))
                    {
                        printf("ERROR\n");
                        printf("Ingrese Nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                    }
                    strcpy(vec[indice].name, auxCad);
                    printf("Nombre modificado!\n");
                    break;
                case 2:
                    printf("Ingrese nuevo Apellido: ");
                    fflush(stdin);
                    gets(auxCad);
                    //valido nombre
                    while(!isalpha(*auxCad))
                    {
                        printf("ERROR\n");
                        printf("Ingrese nuevo Apellido: ");
                        fflush(stdin);
                        gets(auxCad);
                    }
                    strcpy(vec[indice].lastname, auxCad);
                    printf("Apellido modificado!\n");
                    break;
                case 3:
                    printf("Ingrese nuevo Precio: ");
                    // validar price

                    fflush(stdin);
                    while((scanf("%f", &price)) == 0)
                    {
                        printf("ERROR\n");
                        printf("Ingrese Precio: ");
                        fflush(stdin);
                    }

                    vec[indice].price = price;
                    printf("Precio modificado!\n");
                    break;
                case 4:
                    printf("Ingrese nuevo Tipo de Pasajero:\n1- Economica\n2- Primera\n3- Business\n");
                    // validar tipoPas
                    while((scanf("%d", &tipoPas)) == 0 )
                    {
                        printf("ERROR\n");
                        printf("Ingrese Tipo de Pasajero:\n1- Economica\n2- Primera\n3- Business\n");
                        fflush(stdin);
                    }

                    while(tipoPas != 1 && tipoPas != 2 && tipoPas != 3)
                    {
                        printf("Error\n");
                        printf("Ingrese Tipo de Pasajero:\n1- Economica\n2- Primera\n3- Business\n");
                        scanf("%d", &tipoPas);
                    }
                    switch(tipoPas)
                    {
                    case 1:
                        *nuevoPasajero.tipoPasajero = "Economica";
                        break;
                    case 2:
                        *nuevoPasajero.tipoPasajero = "Primera";
                        break;
                    case 3:
                        *nuevoPasajero.tipoPasajero = "Business";
                        break;
                    default:
                        printf("Dato invalido.");
                        break;
                    }

                    *vec[indice].tipoPasajero = *nuevoPasajero.tipoPasajero;
                    vec[indice].typePassenger = tipoPas;
                    printf("Tipo de pasajero modificado!\n");
                    break;
                case 5:
                    printf("Ingrese nuevo Codigo de Vuelo: ");
                    fflush(stdin);
                    gets(auxCad);
                    //valido Codvuelo
                    while(!isalpha(*auxCad))
                    {
                        printf("ERROR\n");
                        printf("Ingrese nuevo Codigo de Vuelo: ");
                        fflush(stdin);
                        gets(auxCad);
                    }

                    strcpy(vec[indice].flycode, auxCad);
                    printf("Codigo de Vuelo modificado!\n");
                    break;
                case 6:
                    printf("Ingrese nuevo Estado de Vuelo:\n1- Activo\n2- Demorado\n3- Cancelado\n");
                    // validar statusFlight
                    while((scanf("%d", &estadoVuelo)) == 0 )
                    {
                        printf("ERROR\n");
                        printf("Ingrese Estado del vuelo:\n1- Activo\n2- Demorado\n3- Cancelado\n");
                        fflush(stdin);
                    }
                    while(estadoVuelo != 1 && estadoVuelo != 2 && estadoVuelo != 3)
                    {
                        printf("Error\n");
                        printf("Ingrese nuevo Estado de Vuelo:\n1- Activo\n2- Demorado\n3- Cancelado\n");
                        scanf("%d", &estadoVuelo);
                    }
                    switch(estadoVuelo)
                    {
                    case 1:
                        *nuevoPasajero.estadoVuelo = "Activo";
                        break;
                    case 2:
                        *nuevoPasajero.estadoVuelo = "Demorado";
                        break;
                    case 3:
                        *nuevoPasajero.estadoVuelo = "Cancelado";
                        break;
                    default:
                        printf("Dato invalido.\n");
                        break;
                    }

                    *vec[indice].estadoVuelo = *nuevoPasajero.estadoVuelo;
                    vec[indice].statusFlight = estadoVuelo;
                    printf("Estado de vuelo modificado\n");
                    break;
                case 0:
                    printf("Modificacion Cancelada\n");
                    break;
                default:
                    printf("Opcion Invalida.\n");
                    break;
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}


int menuModificarPasajero()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Precio\n");
    printf("4. Tipo de Pasajero\n");
    printf("5. Codigo de Vuelo\n");
    printf("6. Estado de Vuelo\n");
    printf("0. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

////////////////////////////////////////////////////////////////////////////////////////

int cargarPasajero(ePasajero* pPasajero)
{
    int todoOk = 0;
    if( pPasajero != NULL )
    {
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(pPasajero->name);

        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(pPasajero->lastname);

        printf("Ingrese Precio: ");
        scanf("%f", &pPasajero->price);


        printf("Ingrese Tipo de Vuelo:\n1- Economica\n2- Primera\n3- Business\n");
        scanf("%d", &pPasajero->typePassenger);

        printf("Ingrese Codigo de Vuelo: ");
        fflush(stdin);
        gets(pPasajero->flycode);

        printf("Ingrese Estado del vuelo:\n1- Activo\n2- Demorado\n3- Cancelado\n");
        scanf("%d", &pPasajero->statusFlight);

        todoOk = 1;
    }
    return todoOk;
}

void mostrarPasajero(ePasajero pas)
{
    printf("ID: %d\n", pas.id);
    printf("Nombre: %s\n", pas.name);
    printf("Apellido: %s\n", pas.lastname);
    printf("Precio: %.2f\n", pas.price);
    printf("Tipo de Pasajero: %d\n", pas.typePassenger);
    printf("Codigo de vuelo: %s\n", pas.flycode);
    printf("Estado de Vuelo: %d\n", pas.statusFlight);
}

int ordenarPasajerosCodVueloId(ePasajero vec[], int tam)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if((vec[i].flycode == vec[j].flycode && (vec[i].id > vec[j].id))
                        || (vec[i].flycode != vec[j].flycode && (vec[i].flycode > vec[j].flycode)))
                {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarPasajeros(ePasajero vec[], int tam)
{
    int todoOk = 0;

    if( vec != NULL)
    {
        for(int i = 0; i < tam; i++ )
        {
            printf("Ingrese id: ");
            scanf("%d", &vec[i].id);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[i].name);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[i].lastname);

            printf("Ingrese precio: ");
            scanf("%f", &vec[i].price);

            printf("Ingrese Tipo de pasajero: ");
            scanf("%d", &vec[i].typePassenger);

            printf("Ingrese Codigo de Vuelo: ");
            fflush(stdin);
            gets(vec[i].flycode);

            printf("Ingrese Estado de vuelo: ");
            scanf("%d", &vec[i].statusFlight);

            todoOk = 1;
        }
    }
    return todoOk;
}

int menuOpcion4()
{
    int opcion;

    printf("\n\n");
    printf("    *** Opciones ***\n\n");
    printf("1- Listar pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n");
    printf("2- Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
    printf("3- Listar pasajeros por Codigo de vuelo y estados de vuelos ACTIVO\n");
    printf("0- Volver al menu principal\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int ordenarPasajerosApellido(ePasajero vec[], int tam)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if( vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(vec[i].lastname, vec[j].lastname) > 0) //strcmp(vec[i].tipoPasajero, vec[j].tipoPasajero) > 0
                {
                    {
                        auxPasajero = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxPasajero;
                    }
                }
            }
        }
        system("cls");
        sortPassengers(vec, tam);
        todoOk = 1;
    }
    return todoOk;
}

//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
int promedioPasajes(ePasajero vec[], int tam)
{
    int todoOk = 0;
    float sumaPrecios = 0;
    int acumulador = 0;
    int acumPrice = 0;
    float promedio;



    if( vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            sumaPrecios += vec[i].price;
            if( vec[i].isEmpty == 0)
            {
                acumulador++;
            }
        }
        todoOk = 1;
    }

    promedio = sumaPrecios / acumulador;

    for(int i = 0; i < tam; i++)
    {
        if( vec[i].price > promedio )
        {
            acumPrice++;
        }
    }

    printf("\nEl precio de todos los pasajes es de $%.2f\n", sumaPrecios);
    printf("El promedio de todos los pasajes es de $%.2f\n", promedio);
    printf("Pasajeros que superan el precio promedio: %d\n", acumPrice);

    return todoOk;
}

int sortPassengersByCode(ePasajero vec[], int tam)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if( vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(vec[i].flycode, vec[j].flycode) > 0 )//strcmp(vec[i].estadoVuelo, vec[j].estadoVuelo) > 0
                {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                    if(strcmp(vec[i].flycode, vec[j].flycode) > 0 )//strcmp(vec[i].estadoVuelo, vec[j].estadoVuelo) > 0
                    {
                        auxPasajero = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxPasajero;
                    }
                }
            }
        }
        system("cls");
        sortPassengers(vec, tam);
        todoOk = 1;
    }
    return todoOk;
}

