#include "mascotas.h"
#include "clientes.h"
#include "utn_funciones.h"

void mostrarClientesConSusMascotas( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

void imprimirColumnasTablaMascotasDuenio();

void imprimirListadoMascotas( eMascota listadoMascotas[] , eCliente listadoClientes[] , int lenM , int lenC );

void mostrarClientesDisponibles( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

void menuAdministracionClienteMascota( eMascota listadoMascotas[] , int lenM , eCliente listadoClientes[] , int lenC , eRaza listadoRazas[] , int lenR , eLocalidad listadoLocalidades[] , int lenL );

void mostrarMascotasOrdenadasPorTipoConCliente( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

int eliminarDuenioConMascotas( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

void clientesConMasDeUnaMascota( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

void imprimirListadoMascotasMayoresATresAnios( eMascota listadoMascotas[] , eCliente listadoClientes[] , int lenM , int lenC );

void mostrarClientesOrdenadosPorCantidadDeMascotas( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

void mostrarClientesOrdenadosPorCantidadDeMascotasYNombreCliente( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

int ingresarDatosDeUnaMascota( eMascota listadoMascotas[] , int lenM , eRaza listadoRazas[] , int lenR , eCliente listadoClientes[] , int lenC );

int modificarMascota( eMascota listadoMascotas[] , int len , eCliente listadoClientes[] , int lenC , eRaza listadoRazas[] , int lenR );

void mostrarClientesConMascotasDelMismoSexo( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC );

void mostrarClientesConSusMascotasYLocalidad( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC , eLocalidad listadoLocalidades[] , int lenL );

void mostrarClientesPorLocalidad(eCliente listadoClientes[] , int lenC , eLocalidad listadoLocalidades[] , int lenL );
