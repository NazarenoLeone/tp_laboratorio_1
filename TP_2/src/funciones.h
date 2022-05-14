/*
 * funciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: Usuario
 */
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct  //typedef (definicion de tipo)
{
    int id;
    char name[51];
    char lastname[51];
    float price;
    char flycode[10];
    int typePassenger;
    char* tipoPasajero[51];
    int statusFlight;
    char* estadoVuelo[51];
    int isEmpty;
} ePasajero;    // nombre del nuevo tipo de dato

#endif // FUNCIONES_H_INCLUDED

int menuPasajeros();
int addPassengers(ePasajero vec[], int tam, int* pNextId);
int buscarLibre(ePasajero vec[], int tam, int* pIndex);
void printPassengers(ePasajero pas);
int sortPassengers(ePasajero vec[], int tam);
int cargarPasajero(ePasajero* pPasajero);
void mostrarPasajero(ePasajero pas);
int hardcodearPasajeros(ePasajero vec[], int tam);
int initPassengers(ePasajero vec[], int tam);
int ordenarPasajerosCodVueloId(ePasajero vec[], int tam);
int findPassengerById(ePasajero vec[], int tam, int id, int* pIndex);
int removePassenger(ePasajero vec[], int tam);
int cargarPasajeros(ePasajero vec[], int tam);
int modificarPasajero (ePasajero vec[], int tam);
int menuModificarPasajero();
int menuOpcion4();
int ordenarPasajerosApellido(ePasajero vec[], int tam);
int promedioPasajes(ePasajero vec[], int tam);
int sortPassengersByCode(ePasajero vec[], int tam);



