/** funciones de calculos
 *  TP_1
 *
 *
 *  NAZARENO JULIAN LEONE
 *  DIV 1G
 */
#include "calculos.h"

float calculoDebito(float precioDeb)
{
    float p;
    p = precioDeb - ((precioDeb * 10) / 100);
    return p;
}
float calculoCredito(float precioCred)
{
    float p;
    p = precioCred + ((precioCred * 25) / 100);
    return p;
}
float calculoBTC(float precioBTC)
{
    float p;
    p = precioBTC / 4606954.55;
    return p;
}
float calculoPXKm(float precio, float kilometros)
{
    float p;
    p = precio / kilometros;
    return p;
}
float calculoDiferencia(float AA, float Latam)
{
    float p;
    if(AA > Latam)
    {
        p = AA - Latam;
    }
    else
    {
        p = Latam - AA;
    }
    return p;
}
