#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "clienteMascota.h"

#define TLCLIENTES 10
#define TLMASCOTAS 20
#define TLRAZAS 8

int main()
{
    eRaza listadoRazas[TLMASCOTAS];
    eMascota listadoMascotas[TLMASCOTAS];
    eCliente listadoClientes[TLCLIENTES];

    harcodeoListadoClientes( listadoClientes , TLCLIENTES );
    initClientesLibres( listadoClientes , TLCLIENTES );

    initRazas( listadoRazas , TLRAZAS );
    harcodeoListadoRaza( listadoRazas , TLMASCOTAS );

    harcodeoListadoMascotas( listadoMascotas , TLMASCOTAS );
    initMascotaLibres( listadoMascotas , TLMASCOTAS );

    menuAdministracionClienteMascota( listadoMascotas , TLMASCOTAS , listadoClientes , TLCLIENTES , listadoRazas , TLRAZAS );

    return 0;
}
