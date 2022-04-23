/** funciones para entrada y salida de datos
 *  TP_1
 *
 *
 *  NAZARENO JULIAN LEONE
 *  DIV 1G
 */

#include <conio.h>
#include "funciones.h"

int menu()
{
    int ops;
    printf("1- Ingresar Kilometros: \n");
    printf("2- Ingresar Precio de Vuelos: \n");
    printf("3- Calcular Todos los Costos: \n");
    printf("4- Informar Resultados: \n");
    printf("5- Carga Forzada de Datos: \n");
    printf("6- Salir \n");
    scanf("%d", &ops);

    return ops;
}
int validarKms()
{
    int kms;
    printf("Por favor ingrese los Kms: \n");
    scanf("%d", &kms);
    while( kms < 1 ) // Validacion para que no ingresen numeros negativos
    {
        fflush(stdin);
        printf("Kilometraje invalido. Por favor ingrese de nuevo los Kms: \n");
        scanf("%d", &kms);
    }
    return kms;
}
float vueloAA(float precioAA)
{
    printf("1- Ingrese el precio por Aerolineas Argentinas: \n");
    fflush(stdin);
    scanf("%f", &precioAA);
    while(precioAA < 1)// Validacion para que no ingresen numeros negativos
    {
        printf("1- Precio invalido. Reingrese el precio por Aerolineas Argentinas: \n");
        fflush(stdin);
        scanf("%f", &precioAA);
    }

    return precioAA;
}
float vueloLatam(float precioLatam)
{
    printf("2- Ingrese el precio por Latam: \n");
    fflush(stdin);
    scanf("%f", &precioLatam);
     while(precioLatam < 1)// Validacion para que no ingresen numeros negativos
    {
        printf("1- Precio invalido. Reingrese el precio por Latam: \n");
        fflush(stdin);
        scanf("%f", &precioLatam);
    }

    return precioLatam;
}


float mostrarResultados(float tarjetaDebitoAA, float tarjetaDebitoLatam,
                        float tarjetaCreditoAA, float tarjetaCreditoLatam,
                        float BTCAA, float BTCLatam,
                        float precioXKmAA, float precioXKmLatam,
                        float diferenciaDePrecio,
                        float precioOpcAA, float precioOpcLatam,
                        int kmIngresados) // Fin de Parametros mostrarResultados()
{
    float ok = 1;
    printf("\nKilometros ingresados: %d\n\n", kmIngresados);
    printf("Precio Aerolineas Argentinas: $%.2f\n", precioOpcAA);
    printf("El precio de Aerolineas Argentinas con tarjeta debito es $%.2f\n", tarjetaDebitoAA);
    printf("Con tarjeta credito es $%.2f\n", tarjetaCreditoAA);
    printf("Con Bitcoin es BTC %f\n", BTCAA);
    printf("El precio por kilometro es $%.2f\n\n", precioXKmAA);


    printf("Precio Latam: $%.2f\n", precioOpcLatam);
    printf("El precio de Latam con tarjeta debito es $%.2f\n", tarjetaDebitoLatam);
    printf("Con tarjeta de credito es $%.2f\n", tarjetaCreditoLatam);
    printf("Con Bitcoin es BTC %f\n", BTCLatam);
    printf("El precio por kilometros es de $%.2f\n\n", precioXKmLatam);
    if (precioOpcAA > precioOpcLatam) // mensaje para diferencia de precio entre AA y Latam
    {
        printf("El precio de Aerolineas Argentinas es $%.2f mayor que Latam\n\n", diferenciaDePrecio);
    }
    else if (precioOpcAA == precioOpcLatam)
    {
        printf("La diferencia es de %f. No hay diferencia\n\n", diferenciaDePrecio);
    }
    else
    {
        printf("El precio de Latam es $%.2f mayor que Aerolineas Argentinas\n\n", diferenciaDePrecio);
    } // FIN mensaje para diferencia de precio entre AA y Latam

    return ok;
}

float cargaForzada(float tarjetaDebitoAA, float tarjetaDebitoLatam,
                   float tarjetaCreditoAA, float tarjetaCreditoLatam,
                   float BTCAA, float BTCLatam,
                   float diferenciaDePrecio,
                   float precioOpcAA, float precioOpcLatam,
                   int kmIngresados) // Fin parametros cargaForzada()
{
    int ok=1;
    printf("Kilometros ingresados: %d\n\n", kmIngresados);
    printf("Precio Aerolineas Argentinas $%.2f\n", precioOpcAA);
    printf("Aerolineas con debito es $%.2f\n", tarjetaDebitoAA);
    printf("Aerolineas con credito es $%.2f\n", tarjetaCreditoAA);
    printf("Precio con Bitcoin %.2f\n\n", BTCAA);
    printf("Precio unitario %f\n", 10799.88);

    printf("Precio Latam $%.2f\n", precioOpcLatam);
    printf("Latam con debito es $%.2f\n", tarjetaDebitoLatam);
    printf("Latam con credito es $%.2f\n", tarjetaCreditoLatam);
    printf("Precio con Bitcoin %.2f\n", BTCLatam);
    printf("Precio unitario %f\n", 10799.88);

    printf("La diferencia de precio es: $%.2f\n", diferenciaDePrecio);

    return ok;
}
