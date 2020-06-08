#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include "clienteMascota.h"

#define TRUE 1
#define FALSE 0


int menuABM( int lugaresDisponiblesMascotas , int lugaresDisponiblesClientes ) {
    int menu;
    printf( "\n" );
    printf( "\n1) Alta mascota - Lugares Disponibles: %d" , lugaresDisponiblesMascotas );
    printf( "\n2) Alta cliente - Lugares Disponibles: %d" , lugaresDisponiblesClientes );
    printf( "\n3) Baja mascota" );
    printf( "\n4) Baja duenio" );
    printf( "\n5) Modificar mascota" );
    printf( "\n6) Modificar duenio" );
    printf( "\n7) Listado de clientes" );
    printf( "\n8) Listado de mascotas por tipo y con sus duenios" );
    printf( "\n9) Listado de clientes con mas de una mascota" );
    printf( "\n10) Listado de clientes con mascotas." );
    printf( "\n11) Listado de las mascotas." );
    printf( "\n12) Listado de las mascotas de mas de tres anios, con respectivos duenios." );
    printf( "\n13) Listar las mascotas por un tipo en particular{perro,gato,raro}" );
    printf( "\n14) Listar a los duenios por cantidades de mascotas" );
    printf( "\n15) Listar a los duenios por cantidades de mascotas y orden alfabetico" );
    printf( "\n16) Edad promedio de las mascotas" );
    printf( "\n17) Edad promedio de las mascotas por tipo" );
    printf( "\n18) Edad promedio de los clientes" );
    printf( "\n19) Porcentaje que tengo de mujeres sobre el total de clientes" );
    printf( "\n20) Listar los dueños que tienen mascotas del mismo sexo." );
    printf( "\n21) Listado de clientes con mascotas y localidad." );
    printf( "\n22) Listado de clientes por localidad." );
    printf( "\n23) Listado de clientes ordenados por localidad y nombre." );
    printf( "\n24) Salir.\n" );
    printf( "\nSeleccionar una opcion <1-24>: " );
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

void imprimirColumnasTablaMascotasDuenio() {
    printf("\n---------------------------------------------LISTADO DE MASCOTAS---------------------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------------------------------------------");
    printf("\n| ID |        NOMBRE         |        TIPO        |        RAZA        | EDAD |   PESO   | SEXO |        DUEÑO         | ");
    printf("\n-------------------------------------------------------------------------------------------------------------------------");
}

void imprimirColumnasTablaCantidadMascotasPorCliente() {
    printf("\n----------------------------------------------------LISTADO DE CLIENTES----------------------------------------------------------------");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n| ID | CANTIDAD MASCOTAS |        NOMBRE         |        APELLIDO        |  EDAD  | SEXO |       LOCALIDAD        |     TELEFONO     |");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------");
}

void imprimirListadoMascotas( eMascota listadoMascotas[] , eCliente listadoClientes[] , int lenM , int lenC ) {
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        imprimirColumnasTablaMascotasDuenio();
        for( int i = 0 ; i < lenM ; i++ ) {
            for( int j = 0 ; j < lenC ; j++ ) {
                if( (listadoMascotas[i].isEmpty == FALSE) && (listadoClientes[j].isEmpty == FALSE) ) {
                    if( listadoMascotas[i].idCliente == listadoClientes[j].idCliente ) {
                        printf( "\n%3d %16s %22s %22d %9d %9.2f %6c %18s" ,
                                                                            listadoMascotas[i].idMascota ,
                                                                            listadoMascotas[i].name ,
                                                                            listadoMascotas[i].tipo ,
                                                                            listadoMascotas[i].idRaza ,
                                                                            listadoMascotas[i].edad ,
                                                                            listadoMascotas[i].peso ,
                                                                            listadoMascotas[i].sexo ,
                                                                            listadoClientes[j].name );
                    }
                }
            }
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------------");

    }
}

void mostrarClientesConSusMascotas( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    int tieneMascota;
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                tieneMascota = FALSE;
                printf("\n---------------------------------------------------------------------------------------------");
                printf("\nCLIENTE : | ID: %d | %s %s |" , listadoClientes[i].idCliente
                                                        , listadoClientes[i].name
                                                        , listadoClientes[i].lastName);
                printf("\nLISTADO DE SUS MASCOTAS");
                imprimirColumnasTablaMascotas();
                for( int j = 0 ; j < lenM ; j++ ) {
                    if( (listadoMascotas[j].isEmpty == FALSE) && (listadoClientes[i].idCliente == listadoMascotas[j].idCliente) ) {
                        tieneMascota = TRUE;
                        printf( "\n%3d %16s %22s %22d %9d %7.2f %4c" ,
                                                                        listadoMascotas[j].idMascota ,
                                                                        listadoMascotas[j].name ,
                                                                        listadoMascotas[j].tipo ,
                                                                        listadoMascotas[j].idRaza ,
                                                                        listadoMascotas[j].edad ,
                                                                        listadoMascotas[j].peso ,
                                                                        listadoMascotas[j].sexo );
                    }
                }
                if( tieneMascota == FALSE ) {
                    printf("\nNO TIENE MASCOTAS");
                }
                printf("\n---------------------------------------------------------------------------------------------");
            }
        }

    }
}

void mostrarClientesDisponibles( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    int i,j;
    eCliente auxCliente[lenC];

    for ( i = 0 ; i < lenC ; i++ ) {
        auxCliente[i].isEmpty = TRUE;
    }

    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        imprimirColumnasTablaClientes();
        for ( j = 0 ; j < lenC ; j++ ) {
            if( listadoClientes[j].isEmpty == FALSE ) {
                for( i = 0 ; i < lenM ; i++ ) {
                    if( (listadoMascotas[i].idCliente == listadoClientes[j].idCliente) ) {
                        auxCliente[j] = listadoClientes[j];
                        auxCliente[j].isEmpty = FALSE;
                    }
                }
            }
        }

        for ( j = 0 ; j < lenC ; j++ ) {
            if( listadoClientes[j].idCliente != auxCliente[j].idCliente ) {
                imprimirUnCliente( listadoClientes[j] );
            }
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------");
    }
}

int eliminarDuenioConMascotas( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    int salida = -1;
    int auxID;
    int mascotaEliminada;
    int clienteEliminado;
    //mostrarClientesConSusMascotas( listadoMascotas , lenM , listadoClientes , lenC );
    imprimirClientes(listadoClientes,lenC);
    getDatoGenericoInt( &auxID , "\nIngrese ID del cliente a borrar: " , "ERROR ! ingrese nuevamente el ID" , 100 , 200 , 3 );
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        for ( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].idCliente == auxID ) {
                for( int j = 0 ; j < lenM ; j++ ) {
                    if( (listadoMascotas[j].isEmpty == FALSE) && (listadoClientes[i].idCliente == listadoMascotas[j].idCliente)  ) {
                        clienteEliminado = bajaCliente( listadoClientes , lenC , auxID );
                        mascotaEliminada = bajaMascota( listadoMascotas , lenM , j );
                    }
                }
            }
        }
    }

    if( clienteEliminado == 0 && mascotaEliminada == 0 ) {
        salida = 0;
        imprimirListadoMascotas( listadoMascotas , listadoClientes , lenM , lenC );
        printf( "\nCLIENTE ELIMINADO CON EXITO.\n" );
    } else {
        printf( "\nERROR ! NO SE ELIMINO EL CLIENTE.\n" );
    }

    return salida;
}

void mostrarMascotasOrdenadasPorTipoConCliente( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    eMascota aux;
    for( int i = 0 ; i < lenM-1 ; i++ ) {
        for( int j = i+1 ; j < lenM ; j++ ) {
            if( strcmp(listadoMascotas[i].tipo , listadoMascotas[j].tipo) > 0 ) {
                aux = listadoMascotas[i];
                listadoMascotas[i] = listadoMascotas[j];
                listadoMascotas[j] = aux;
            }
        }
    }
    imprimirColumnasTablaMascotasDuenio();
    for( int i = 0 ; i < lenM ; i++ ) {
        for( int j = 0 ; j < lenC ; j++ ) {
            if( (listadoMascotas[i].isEmpty == FALSE) && (listadoClientes[j].isEmpty == FALSE) ) {
                if( listadoMascotas[i].idCliente == listadoClientes[j].idCliente ) {
                    printf( "\n%3d %16s %22s %22d %9d %9.2f %6c %18s" ,
                                                                        listadoMascotas[i].idMascota ,
                                                                        listadoMascotas[i].name ,
                                                                        listadoMascotas[i].tipo ,
                                                                        listadoMascotas[i].idRaza ,
                                                                        listadoMascotas[i].edad ,
                                                                        listadoMascotas[i].peso ,
                                                                        listadoMascotas[i].sexo ,
                                                                        listadoClientes[j].name );
                }
            }
        }
    }
    printf("\n-------------------------------------------------------------------------------------------------------------------------");

}

void clientesConMasDeUnaMascota( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    int contadorMascotas[lenM];
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        for(int i=0;i<lenM;i++) {
            contadorMascotas[i] = 0;
        }
        imprimirColumnasTablaClientes();
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                for( int j = 0 ; j < lenM ; j++ ) {
                    if( (listadoMascotas[j].isEmpty == FALSE) && (listadoClientes[i].idCliente == listadoMascotas[j].idCliente) ) {
                        contadorMascotas[i]++;
                    }
                }
                if( contadorMascotas[i] > 2 ) {
                    imprimirUnCliente(listadoClientes[i]);
                }
            }
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------");
    }
}

void imprimirListadoMascotasMayoresATresAnios( eMascota listadoMascotas[] , eCliente listadoClientes[] , int lenM , int lenC ) {
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        imprimirColumnasTablaMascotasDuenio();
        for( int i = 0 ; i < lenM ; i++ ) {
            for( int j = 0 ; j < lenC ; j++ ) {
                if( (listadoMascotas[i].isEmpty == FALSE) && (listadoClientes[j].isEmpty == FALSE) ) {
                    if( (listadoMascotas[i].idCliente == listadoClientes[j].idCliente) && (listadoMascotas[i].edad > 3) ) {
                        printf( "\n%3d %16s %22s %22d %9d %9.2f %6c %18s" ,
                                                                            listadoMascotas[i].idMascota ,
                                                                            listadoMascotas[i].name ,
                                                                            listadoMascotas[i].tipo ,
                                                                            listadoMascotas[i].idRaza ,
                                                                            listadoMascotas[i].edad ,
                                                                            listadoMascotas[i].peso ,
                                                                            listadoMascotas[i].sexo ,
                                                                            listadoClientes[j].name );
                    }
                }
            }
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------------");

    }
}

void mostrarClientesOrdenadosPorCantidadDeMascotas( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    int contadorMascotas[lenM];
    int auxContador;
    eCliente auxCliente;
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        for(int i=0;i<lenM;i++) {
            contadorMascotas[i] = 0;
        }
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                for( int j = 0 ; j < lenM ; j++ ) {
                    if( (listadoMascotas[j].isEmpty == FALSE) && (listadoClientes[i].idCliente == listadoMascotas[j].idCliente) ) {
                        contadorMascotas[i]++;
                    }
                }
            }
        }

        for( int j = 0 ; j < lenC-1 ; j++ ) {
            for( int i = j+1 ; i < lenC ; i++ ) {
                if( contadorMascotas[j] > contadorMascotas[i] ) {

                    auxContador = contadorMascotas[j];
                    contadorMascotas[j] = contadorMascotas[i];
                    contadorMascotas[i] = auxContador;

                    auxCliente = listadoClientes[j];
                    listadoClientes[j] = listadoClientes[i];
                    listadoClientes[i] = auxCliente;
                }
            }
        }
        imprimirColumnasTablaCantidadMascotasPorCliente();
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                printf( "\n%4d %10d %28s %22s %12d %7c %20d %20li" , listadoClientes[i].idCliente
                                                                      , contadorMascotas[i]
                                                                      , listadoClientes[i].name
                                                                      , listadoClientes[i].lastName
                                                                      , listadoClientes[i].edad
                                                                      , listadoClientes[i].sexo
                                                                      , listadoClientes[i].idLocalidad
                                                                      , listadoClientes[i].telefono );
            }
        }
    }
}

void mostrarClientesOrdenadosPorCantidadDeMascotasYNombreCliente( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    int contadorMascotas[lenM];
    int auxContador;
    eCliente auxCliente;
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        for(int i=0;i<lenM;i++) {
            contadorMascotas[i] = 0;
        }
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                for( int j = 0 ; j < lenM ; j++ ) {
                    if( (listadoMascotas[j].isEmpty == FALSE) && (listadoClientes[i].idCliente == listadoMascotas[j].idCliente) ) {
                        contadorMascotas[i]++;
                    }
                }
            }
        }

        for( int j = 0 ; j < lenC-1 ; j++ ) {
            for( int i = j+1 ; i < lenC ; i++ ) {
                if( contadorMascotas[j] > contadorMascotas[i] ) {
                    auxContador = contadorMascotas[j];
                    contadorMascotas[j] = contadorMascotas[i];
                    contadorMascotas[i] = auxContador;

                    auxCliente = listadoClientes[j];
                    listadoClientes[j] = listadoClientes[i];
                    listadoClientes[i] = auxCliente;
                } else {
                    if( contadorMascotas[j] == contadorMascotas[i] && strcmp(listadoClientes[j].name,listadoClientes[i].name) < 0 ) {
                        auxContador = contadorMascotas[j];
                        contadorMascotas[j] = contadorMascotas[i];
                        contadorMascotas[i] = auxContador;

                        auxCliente = listadoClientes[j];
                        listadoClientes[j] = listadoClientes[i];
                        listadoClientes[i] = auxCliente;
                    }
                }
            }
        }
        imprimirColumnasTablaCantidadMascotasPorCliente();
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                printf( "\n%4d %10d %28s %22s %12d %7c %20d %20li" , listadoClientes[i].idCliente
                                                                      , contadorMascotas[i]
                                                                      , listadoClientes[i].name
                                                                      , listadoClientes[i].lastName
                                                                      , listadoClientes[i].edad
                                                                      , listadoClientes[i].sexo
                                                                      , listadoClientes[i].idLocalidad
                                                                      , listadoClientes[i].telefono );
            }
        }
    }
}

int modificarMascota( eMascota listadoMascotas[] , int len , eCliente listadoClientes[] , int lenC , eRaza listadoRazas[] , int lenR ) {
    int salida = -1;
    int menuMod;
    int indexMascota;
    int auxID;
    int auxIDCliente;
    char auxName[30];
    char auxTipo[30];
    int auxRaza;
    int auxEdad;
    float auxPeso;
    char auxSexo;
    imprimirMascotas( listadoMascotas , len );
    getDatoGenericoInt( &auxID , "\nIngrese ID de la mascota: " , "ERROR ! ingrese nuevamente el ID" , 0 , len , 3 );
    printf( "\nQue desea modificar ?\n" );
    menuMod = menuModificarMascota();
    indexMascota = buscarMascotaPorID( listadoMascotas , len , auxID );
    switch(menuMod) {
        case 1:
            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 30 );
            formatearString(auxName);
            strcpy( listadoMascotas[indexMascota].name , auxName );
            printf( "\nNombre modificado con exito.\n" );
            imprimirColumnasDatosMascota();
            imprimirUnaMascota( listadoMascotas[indexMascota] );
            salida = 0;
            break;
        case 2:
            getDatoGenericoString( auxTipo , "Ingrese tipo mascota <PERRO-GATO-RARO>: " , "ERROR ! ingrese nuevamente el tipo" , 30 );
            formatearString(auxTipo);
            strcpy( listadoMascotas[indexMascota].tipo , auxTipo );
            printf( "\nTipo modificado con exito.\n" );
            imprimirColumnasDatosMascota();
            imprimirUnaMascota( listadoMascotas[indexMascota] );
            salida = 0;
            break;
        case 3:
            imprimirRazas(listadoRazas,lenR);
            getDatoGenericoInt( &auxRaza , "Ingrese el id de la raza: " , "ERROR ! ingrese nuevamente el id" , 1 , lenR , 3 );
            listadoMascotas[indexMascota].idRaza = auxRaza;
            printf( "\nRaza modificada con exito.\n" );
            imprimirColumnasDatosMascota();
            imprimirUnaMascota( listadoMascotas[indexMascota] );
            salida = 0;
            break;
        case 4:
            getDatoGenericoInt( &auxEdad , "Ingrese edad: " , "ERROR ! ingrese nuevamente la edad" , 0 , 30 , 3 );
            listadoMascotas[indexMascota].edad = auxEdad;
            printf( "\nEdad modificada con exito.\n" );
            imprimirColumnasDatosMascota();
            imprimirUnaMascota( listadoMascotas[indexMascota] );
            salida = 0;
            break;
        case 5:
            getDatoGenericoFloat( &auxPeso , "Ingrese el peso: " , "ERROR ! ingrese nuevamente el peso" , 0.0 , 3000.0 , 3 );
            listadoMascotas[indexMascota].peso = auxPeso;
            printf( "\nPeso modificado con exito.\n" );
            imprimirColumnasDatosMascota();
            imprimirUnaMascota( listadoMascotas[indexMascota] );
            salida = 0;
            break;
        case 6:
            auxSexo = getDatoGenericoChar("Ingrese el sexo <m-f>: ","ERROR ! ingrese el caracter correspondiente",'m','f');
            listadoMascotas[indexMascota].sexo = auxSexo;
            printf( "\nSexo modificado con exito.\n" );
            imprimirColumnasDatosMascota();
            imprimirUnaMascota( listadoMascotas[indexMascota] );
            salida = 0;
            break;
        case 7:
            //mostrarClientesDisponibles(listadoMascotas,len,listadoClientes,lenC);
            imprimirClientes(listadoClientes,lenC);
            getDatoGenericoInt( &auxIDCliente, "Ingrese id del cliente: " , "ERROR ! ingrese nuevamente el id" , 100 , 200 , 3 );
            listadoMascotas[indexMascota].idCliente = auxIDCliente;
            printf( "\nDuenio modificado con exito.\n" );
            imprimirListadoMascotas( listadoMascotas , listadoClientes , len , lenC );
            salida = 0;
            break;
        case 8:
            salida = 0;
            break;
    }
    return salida;
}

void mostrarClientesConMascotasDelMismoSexo( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC ) {
    char auxSexo;
    char opcionSexo;
    int idsMascotas[lenM];
    int idsClientes[lenC];
    for(int i=0;i<lenM;i++) {
        idsMascotas[i] = 0;
    }
    for(int i=0;i<lenC;i++) {
        idsClientes[i] = 0;
    }
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        auxSexo = getDatoGenericoChar("Ingrese el sexo de la mascota <m-f>: ","ERROR ! ingrese el caracter correspondiente",'m','f');
        opcionSexo=tolower(auxSexo);
        for( int i = 0 ; i < lenM ; i++ ) {
            if( listadoMascotas[i].isEmpty == FALSE && listadoMascotas[i].sexo == opcionSexo ) {
                idsMascotas[i] = listadoMascotas[i].idMascota;
            }
        }
        for( int j = 0 ; j < lenC ; j++ ) {
            if( listadoClientes[j].isEmpty == FALSE ) {
                for( int i = 0 ; i < lenM ; i++ ) {
                    if( listadoMascotas[i].isEmpty == FALSE && listadoClientes[j].idCliente == listadoMascotas[i].idCliente && listadoMascotas[i].idMascota == idsMascotas[i] ) {
                        idsClientes[j] = listadoClientes[j].idCliente;
                    }
                }
            }
        }
        for( int j = 0 ; j < lenC ; j++ ) {
            if( idsClientes[j] != 0 ) {
                imprimirColumnasDatosCliente();
                imprimirUnCliente(listadoClientes[buscarClientePorID(listadoClientes,lenC,idsClientes[j])]);
                printf("\n-------------------------------------------------------------------------------------------------------------------");
                printf("\n");
                printf("\n---------------------------LISTADO DE MASCOTAS DEL CLIENTE ID: %d-------------------------------",listadoClientes[buscarClientePorID(listadoClientes,lenC,idsClientes[j])].idCliente);
                printf("\n-------------------------------------------------------------------------------------------------");
                printf("\n| ID |        NOMBRE         |        TIPO        |        RAZA        | EDAD |   PESO   | SEXO |");
                printf("\n-------------------------------------------------------------------------------------------------");
                for( int i = 0 ; i < lenM ; i++ ) {
                    if( listadoMascotas[i].isEmpty == FALSE && idsClientes[j] == listadoMascotas[i].idCliente && listadoMascotas[i].idMascota == idsMascotas[i] ) {
                        imprimirUnaMascota(listadoMascotas[buscarMascotaPorID(listadoMascotas,lenM,idsMascotas[i])]);
                    }
                }
                printf("\n-------------------------------------------------------------------------------------------------");
                printf("\n");
                printf("\n");
                printf("\n");
            }
        }
    }
}

int ingresarDatosDeUnaMascota( eMascota listadoMascotas[] , int lenM , eRaza listadoRazas[] , int lenR , eCliente listadoClientes[] , int lenC ) {
    int salida = -1;
    int auxIdCliente;
    char auxName[30];
    char auxTipo[30];
    int auxIDRaza;
    int auxEdad;
    float auxPeso;
    char auxSexo;
    if( listadoMascotas != NULL && lenM > 0 ) {
        if( cantidadLugaresDisponiblesMascotas(listadoMascotas,lenM) > 0 ) {
            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 30 );
            getDatoGenericoString( auxTipo , "Ingrese tipo mascota <PERRO-GATO-RARO>: " , "ERROR ! ingrese nuevamente el tipo" , 30 );
            imprimirRazas(listadoRazas,lenR);
            //getDatoGenericoString( auxRaza , "Ingrese raza: " , "ERROR ! ingrese nuevamente la raza" , 30 );
            getDatoGenericoInt( &auxIDRaza , "Ingrese id de la raza: " , "ERROR ! ingrese nuevamente el id" , 1 , 8 , 3 );
            formatearString( auxName );
            formatearString( auxTipo );
            getDatoGenericoInt( &auxEdad , "Ingrese edad: " , "ERROR ! ingrese nuevamente la edad" , 0 , 30 , 3 );
            getDatoGenericoFloat( &auxPeso , "Ingrese el peso: " , "ERROR ! ingrese nuevamente el peso" , 0.0 , 3000.0 , 3 );
            auxSexo = getDatoGenericoChar("Ingrese el sexo <m-f>: ","ERROR ! ingrese el caracter correspondiente",'m','f');
            auxSexo = tolower(auxSexo);
            imprimirClientes(listadoClientes,lenC);
            getDatoGenericoInt( &auxIdCliente , "Ingrese ID del Cliente: " , "ERROR ! ingrese nuevamente el ID" , 100 , 200 , 3 );
            addMascota( listadoMascotas , lenM , auxIdCliente , auxName , auxTipo , auxIDRaza , auxEdad , auxPeso , auxSexo );
            salida = 0;
        } else {
            printf("\nERROR ! No hay lugar disponible.\n");
        }
    }
    return salida;
}

int ingresarDatosDeXMascotas( eMascota listadoMascotas[] , int lenM , eRaza listadoRazas[] , int lenR , eCliente listadoClientes[] , int lenC ) {
    int salida = -1;
    char respuesta;
    if( listadoMascotas != NULL && lenM > 0 && listadoRazas != NULL && lenR > 0) {
        do{
            if( ingresarDatosDeUnaMascota(listadoMascotas,lenM,listadoRazas,lenR,listadoClientes,lenC) == 0 ) {
                printf("\nMascota ingresada con exito.\n");
            }
            if( cantidadLugaresDisponiblesMascotas(listadoMascotas,lenM) > 0 ){
                respuesta = getDatoGenericoChar("Desea ingresar otra mascota? <s-n>: ","ERROR ! ingrese el caracter correspondiente",'s','n');
                if( respuesta == 'N' || cantidadLugaresDisponiblesMascotas(listadoMascotas,lenM) == 0 ) {
                    salida = 0;
                }
            } else {
                salida = 0;
            }
        } while( salida != 0 );
    }
    return salida;
}

void mostrarClientesConSusMascotasYLocalidad( eMascota listadoMascotas[] , int lenM ,  eCliente listadoClientes[] , int lenC , eLocalidad listadoLocalidades[] , int lenL ) {
    int tieneMascota;
    if( listadoMascotas != NULL && lenM > 0 && listadoClientes != NULL && lenC > 0 ) {
        for( int i = 0 ; i < lenC ; i++ ) {
            for( int k = 0 ; k < lenL ; k++ ) {
                if( listadoClientes[i].isEmpty == FALSE && listadoLocalidades[k].isEmpty == FALSE ) {
                tieneMascota = FALSE;
                printf("\n---------------------------------------------------------------------------------------------");
                printf("\nCLIENTE : | ID: %d | %s %s | LOCALIDAD: %s" , listadoClientes[i].idCliente
                                                        , listadoClientes[i].name
                                                        , listadoClientes[i].lastName
                                                        , listadoLocalidades[k].descripcion);
                printf("\nLISTADO DE SUS MASCOTAS");
                imprimirColumnasTablaMascotas();
                for( int j = 0 ; j < lenM ; j++ ) {
                    if( (listadoMascotas[j].isEmpty == FALSE) && (listadoClientes[i].idCliente == listadoMascotas[j].idCliente) ) {
                        tieneMascota = TRUE;
                        printf( "\n%3d %16s %22s %22d %9d %7.2f %4c" ,
                                                                        listadoMascotas[j].idMascota ,
                                                                        listadoMascotas[j].name ,
                                                                        listadoMascotas[j].tipo ,
                                                                        listadoMascotas[j].idRaza ,
                                                                        listadoMascotas[j].edad ,
                                                                        listadoMascotas[j].peso ,
                                                                        listadoMascotas[j].sexo );
                    }
                }
                if( tieneMascota == FALSE ) {
                    printf("\nNO TIENE MASCOTAS");
                }
                printf("\n---------------------------------------------------------------------------------------------");
            }
            }
        }

    }
}

void mostrarClientesPorLocalidad( eCliente listadoClientes[] , int lenC , eLocalidad listadoLocalidades[] , int lenL ) {
    int auxLocalidad;
    if( listadoClientes != NULL && listadoLocalidades != NULL && lenC > 0 && lenL > 0 ) {
        imprimirLocalidades(listadoLocalidades,lenL);
        getDatoGenericoInt( &auxLocalidad , "Ingrese id localidad: " , "ERROR ! ingrese nuevamente la localidad" , 1 , lenL , 3 );
        imprimirColumnasTablaClientes();
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE && listadoClientes[i].idLocalidad == auxLocalidad ) {
                imprimirUnCliente(listadoClientes[i]);
            }
        }
    }
}

void menuAdministracionClienteMascota( eMascota listadoMascotas[] , int lenM , eCliente listadoClientes[] , int lenC , eRaza listadoRazas[] , int lenR , eLocalidad listadoLocalidades[] , int lenL ) {
    int menu;
    int mascotaCargada;
    int clienteCargado;
    do{
        menu = menuABM( cantidadLugaresDisponiblesMascotas(listadoMascotas,lenM) , cantidadLugaresDisponiblesClientes(listadoClientes,lenC) );
        mascotaCargada = seCargoMascota( listadoMascotas , lenM );
        clienteCargado = seCargoCliente( listadoClientes , lenC );
        switch( menu ) {
            case 1:
                printf("\nINGRESANDO DATOS DE LA MASCOTA --->\n");
                //mostrarClientesDisponibles( listadoMascotas , lenM , listadoClientes , lenC );
                /*if( ingresarDatosDeXMascotas( listadoMascotas , lenM , listadoRazas , lenR , listadoClientes , lenC ) == 0 ) {
                    imprimirListadoMascotas( listadoMascotas , listadoClientes , lenM , lenC );
                }*/
                ingresarDatosDeXMascotas( listadoMascotas , lenM , listadoRazas , lenR , listadoClientes , lenC );
                break;
            case 2:
                imprimirClientes( listadoClientes , lenC );
                if( ingresarDatosDeXClientes( listadoClientes , lenC,listadoLocalidades,lenL) == 0 ) {
                    imprimirClientes( listadoClientes , lenC );
                }
                break;
            if( mascotaCargada == 0 ) {
                case 3:
                    eliminarMascota( listadoMascotas , lenM );
                    break;
            }
            if( clienteCargado == 0 ) {
                case 4:
                    eliminarDuenioConMascotas( listadoMascotas , lenM , listadoClientes , lenC );
                    break;
            }
            if( mascotaCargada == 0 ) {
                case 5:
                    modificarMascota( listadoMascotas , lenM , listadoClientes , lenC , listadoRazas , lenR );
                    break;
            }
            case 6:
                modificarCliente( listadoClientes , lenC , listadoLocalidades , lenL );
                break;
            case 7:
                imprimirClientes( listadoClientes , lenC );
                break;
            case 8:
                mostrarMascotasOrdenadasPorTipoConCliente( listadoMascotas , lenM , listadoClientes , lenC );
                break;
            case 9:
                clientesConMasDeUnaMascota( listadoMascotas , lenM , listadoClientes , lenC );
                break;
            case 10:
                mostrarClientesConSusMascotas( listadoMascotas , lenM , listadoClientes , lenC );
                break;
            case 11:
                imprimirListadoMascotas( listadoMascotas , listadoClientes , lenM , lenC );
                break;
            case 12:
                imprimirListadoMascotasMayoresATresAnios( listadoMascotas , listadoClientes , lenM , lenC );
                break;
            case 13:
                imprimirListadoMascotasPorTipo( listadoMascotas , lenM );
                break;
            case 14:
                mostrarClientesOrdenadosPorCantidadDeMascotas( listadoMascotas , lenM , listadoClientes , lenC );
                break;
            case 15:
                mostrarClientesOrdenadosPorCantidadDeMascotasYNombreCliente( listadoMascotas , lenM , listadoClientes , lenC );
                break;
            case 16:
                edadPromedioMascotas( listadoMascotas , lenM );
                break;
            case 17:
                edadPromedioMascotasPorTipo( listadoMascotas , lenM );
                break;
            case 18:
                edadPromedioVaronesYMujeres( listadoClientes , lenC );
                break;
            case 19:
                porcentajeDeMujeres( listadoClientes , lenC );
                break;
            case 20:
                mostrarClientesConMascotasDelMismoSexo( listadoMascotas , lenM , listadoClientes , lenC );
                break;
            case 21:
                mostrarClientesConSusMascotasYLocalidad( listadoMascotas , lenM , listadoClientes , lenC , listadoLocalidades , lenL );
                break;
            case 22:
                mostrarClientesPorLocalidad(listadoClientes , lenC , listadoLocalidades, lenL );
                break;
            case 23:
                mostrarClientesOrdenadosPorLocalidadYNombreCliente( listadoClientes , lenC );
                break;
            case 24:
                break;
        }

    } while( menu != 24 );
}
