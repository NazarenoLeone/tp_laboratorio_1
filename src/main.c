/** main
 *  TP_1
 *
 *
 *  NAZARENO JULIAN LEONE
 *  DIV 1G
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#include "calculos.h"

int main()
{

	setbuf(stdout, NULL);
    // Variables
    int menuPrincipal;
    int kmIngresados;
    int kmFlag;

    float precioOpcAA;
    float precioOpcLatam;
    float precioAA=0;
    float precioLatam=0;
    int pFlag;


    float tarjetaDebitoAA;
    float tarjetaDebitoLatam;
    float tarjetaCreditoAA;
    float tarjetaCreditoLatam;
    float BTCAA;
    float BTCLatam;
    float precioXKmAA;
    float precioXKmLatam;
    float diferenciaDePrecio;
    int calculosFlag;

    char salir = 's';
    // Fin variables

    do
    {
        menuPrincipal = menu();

        switch(menuPrincipal)
        {
        case 1:
            kmIngresados = validarKms();
            kmFlag = 1;
            break;
        case 2:
            if(kmFlag == 1)
            {
                precioOpcAA = vueloAA(precioAA);
                precioOpcLatam = vueloLatam(precioLatam);
                fflush(stdin);
                pFlag = 1;
            }
            else
            {
                printf("Primero debe ingresar los kms, presione una tecla para continuar.\n\n");
                fflush(stdin);
            }
            break;

        case 3:
            if(kmFlag == 1 && pFlag == 1)
            {
                tarjetaDebitoAA = calculoDebito(precioOpcAA);
                tarjetaDebitoLatam = calculoDebito(precioOpcLatam);
                tarjetaCreditoAA = calculoCredito(precioOpcAA);
                tarjetaCreditoLatam = calculoCredito(precioOpcLatam);
                BTCAA = calculoBTC(precioOpcAA);
                BTCLatam = calculoBTC(precioOpcLatam);
                precioXKmAA = calculoPXKm(precioOpcAA, kmIngresados);
                precioXKmLatam = calculoPXKm(precioOpcLatam, kmIngresados);
                diferenciaDePrecio = calculoDiferencia(precioOpcAA, precioOpcLatam);
                calculosFlag = 1;
                printf("Calculos realizados con exito!!. Presione una tecla para continuar.\n\n");
                fflush(stdin);
            }
            else
            {
                printf("Primero debe ingresar los kms y los precios, presione una tecla para continuar.\n\n");
                fflush(stdin);
            }
            break;
        case 4:
            if(kmFlag == 1 && pFlag == 1 && calculosFlag == 1)
            {

                mostrarResultados(tarjetaDebitoAA,tarjetaDebitoLatam,
                                  tarjetaCreditoAA, tarjetaCreditoLatam,
                                  BTCAA, BTCLatam,
                                  precioXKmAA, precioXKmLatam,
                                  diferenciaDePrecio,
                                  precioOpcAA, precioOpcLatam,
                                  kmIngresados); // Fin de parametros de mostrarResultados()

                printf("Desea continuar ingresando vuelos? S/N: \n");
                fflush(stdin);
                scanf("%c", &salir);
                // Reinicio de Flags
                kmFlag = 0;
                pFlag = 0;
                calculosFlag = 0;

            }
            else
            {
                printf("Primero debe ingresar los kms, los precios y calcular los costos, presione una tecla para continuar.\n\n");
                fflush(stdin);
            }
            break;
        case 5:
            // Ingreso de datos para carga forzada
            kmIngresados = 7090;
            precioOpcAA = 1335000.66;
            precioOpcLatam = 1350000.76;
            tarjetaDebitoAA = 120255.66;
            tarjetaDebitoLatam = 120255.66;
            tarjetaCreditoAA = 150666.76;
            tarjetaCreditoLatam = 150666.76;
            BTCAA = 33.66;
            BTCLatam = 33.66;
            diferenciaDePrecio = 30006.66; // Fin ingreso de datos para carga forzada

            // Llamada a la funcion de cargaForzada
            cargaForzada(tarjetaDebitoAA,tarjetaDebitoLatam,
                         tarjetaCreditoAA, tarjetaCreditoLatam,
                         BTCAA, BTCLatam,
                         diferenciaDePrecio,
                         precioOpcAA, precioOpcLatam,
                         kmIngresados);
            // Fin de carga forzada
            printf("\nDesea continuar ingresando vuelos? S/N: \n");
            fflush(stdin);
            scanf("%c", &salir);
            break;
        case 6:
            printf("\nRealmente desea salir? S/N: ");
            fflush(stdin);
            scanf("%c", &salir);
            if(salir == 's')
            {
                salir = 'n';
            }
            else
            {
                salir = 's';
            }
            fflush(stdin);
            break;

        default:
            printf("Opcion incorrecta. Por favor ingrese una opcion en la lista. \n\n");
            break;
        }
    }
    while(salir == 's');


    return EXIT_SUCCESS;
}
