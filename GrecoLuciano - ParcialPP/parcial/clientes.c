#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "clienteMascota.h"

#define TRUE 1
#define FALSE 0

void harcodeoListadoClientes( eCliente listadoClientes[] , int len ) {
    int i;
    int idCliente[7] = { 100 , 101 , 102 , 103 , 104 , 105 , 106 };
    char name[7][30] = { "nombreUNO" , "nombreDOS" , "nombreTRES" , "nombreCUATRO" , "nombreCINCO" , "nombreSEIS" , "nombreSIETE" };
    char lastName[7][30] = { "apellidoUNO" , "apellidoDOS" , "apellidoTRES" , "apellidoCUATRO" , "apellidoCINCO" , "apellidoSEIS" , "apellidoSIETE" };
    int localidad[7] = { 1 , 2 , 3 , 1 , 2 , 3 , 1 };
    long int telefono[7] = { 1143189434 , 1156346789 , 1198345632 , 1134567843 , 1134567430 , 1134567430 , 1134567430 };
    int edad[7] = { 34 , 12 , 53 , 22 , 26 , 53 , 22 };
    char sexo[7] = { 'f' , 'm' , 'f' , 'm' , 'm' , 'f' , 'm' };
    int isEmpty[7] = { FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE };

    for( i = 0 ; i <= len ; i++ ) {
        listadoClientes[i].idCliente = idCliente[i];
        formatearString( listadoClientes[i].name );
        formatearString( listadoClientes[i].lastName );
        strcpy( listadoClientes[i].name , name[i] );
        strcpy( listadoClientes[i].lastName , lastName[i] );
        listadoClientes[i].idLocalidad = localidad[i];
        listadoClientes[i].telefono = telefono[i];
        listadoClientes[i].edad = edad[i];
        listadoClientes[i].sexo = sexo[i];
        listadoClientes[i].isEmpty = isEmpty[i];
    };
}

void harcodeoListadoLocalidades( eLocalidad listadoLocalidades[] , int len ) {
    int idLocalidad[3] = { 1 , 2 , 3 };
    char provincia[3][30] = { "Buenos Aires" , "Rosario" , "La Pampa" };
    char descripcion[3][30] = { "Quilmes" , "Rosario" , "Santa Rosa" };
    int codPostal[3] = { 1832 , 1833 , 1834 };
    int isEmpty[3] = { FALSE , FALSE , FALSE };

    for( int i = 0 ; i < len ; i++ ) {
        listadoLocalidades[i].idLocalidad = idLocalidad[i];
        strcpy( listadoLocalidades[i].provincia , provincia[i] );
        strcpy( listadoLocalidades[i].descripcion , descripcion[i] );
        listadoLocalidades[i].codPostal = codPostal[i];
        listadoLocalidades[i].isEmpty = isEmpty[i];
    };
}

int menuClientes( int espaciosLibres ) {
    int menu;
    printf( "\n" );
    printf( "\n1) Alta cliente - Lugares Disponibles: %d" , espaciosLibres );
    printf( "\n2) Baja dueño" );
    printf( "\n3) Listado de mascotas por tipo y con sus dueños" );
    printf( "\n4) Salir.\n" );
    printf( "\nSeleccionar una opcion <1-4>: " );
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

int menuModificarCliente() {
    int menu;
    printf( "\n" );
    printf( "\n1) Nombre" );
    printf( "\n2) Apellido" );
    printf( "\n3) Localidad" );
    printf( "\n4) Telefono" );
    printf( "\n5) Edad" );
    printf( "\n6) Sexo" );
    printf( "\n7) Salir.\n" );
    printf( "\nSeleccionar una opcion <1-7>: " );
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

int initLocalidades( eLocalidad listadoLocalidades[] , int len ) {
    int salida = -1;
    int i;
    if( listadoLocalidades != NULL && len > 0 ) {
        for( i = 0 ; i < len ; i++ ) {
            listadoLocalidades[i].isEmpty = TRUE;
        }
        salida = 0;
    }
    return salida;
};

int initClientes( eCliente listadoClientes[] , int len ) {
    int salida = -1;
    int i;
    if( listadoClientes != NULL && len > 0 ) {
        for( i = 0 ; i < len ; i++ ) {
            listadoClientes[i].isEmpty = TRUE;
        }
        salida = 0;
    }
    return salida;
};

int initClientesLibres( eCliente listadoClientes[] , int len ) {
    int salida = -1;
    int i;
    if( listadoClientes != NULL && len > 0 ) {
        for( i = 0 ; i < len ; i++ ) {
            if( listadoClientes[i].isEmpty != FALSE ) {
                listadoClientes[i].isEmpty = TRUE;
            }
        }
        salida = 0;
    }
    return salida;
};

int imprimirUnCliente( eCliente cliente ) {
    int salida = -1;
    if( cliente.isEmpty == FALSE ) {
        printf( "\n%4d %17s %25s %11d %6c %21d %20li" , cliente.idCliente , cliente.name , cliente.lastName , cliente.edad , cliente.sexo , cliente.idLocalidad , cliente.telefono );
        salida = 0;
    }
    return salida;
};

void imprimirColumnasTablaClientes() {
    printf("\n------------------------------------------LISTADO DE CLIENTES------------------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------------------------------------");
    printf("\n| ID |        NOMBRE         |        APELLIDO        |  EDAD  | SEXO |       LOCALIDAD        |     TELEFONO     |");
    printf("\n-------------------------------------------------------------------------------------------------------------------");
}

void imprimirColumnasDatosCliente() {
    printf("\n-----------------------------------------DATOS DEL CLIENTE---------------------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------------------------------------");
    printf("\n| ID |        NOMBRE         |        APELLIDO        |  EDAD  | SEXO |       LOCALIDAD        |     TELEFONO     |");
    printf("\n-------------------------------------------------------------------------------------------------------------------");
}

void imprimirColumnasDatosLocalidades() {
    printf("\n--------------------------DATOS LOCALIDADES---------------------------------");
    printf("\n----------------------------------------------------------------------------");
    printf("\n| ID |        PROVINCIA         |        DESCRIPCION        |  COD.POSTAL  |");
    printf("\n----------------------------------------------------------------------------");
}

int imprimirClientes( eCliente listadoClientes[] , int len ) {
    int salida = -1;
    int i;
    if( listadoClientes != NULL && len > 0 ) {
        imprimirColumnasTablaClientes();
        for( i = 0 ; i < len ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                imprimirUnCliente( listadoClientes[i] );
            }
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------");
        salida = 0;
    }
    return salida;
};

int buscarClientePorID( eCliente listadoClientes[] , int len , int id ) {
    int salida = -1;
    if( listadoClientes != NULL && len > 0 && id >= 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoClientes[i].idCliente == id ) {
                salida = i;
                break;
            }
        }
    }
    return salida;
}

int findFreeSpaceCliente( eCliente listadoClientes[] , int len  ) {
    int salida = -1;
    if( listadoClientes != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoClientes[i].isEmpty == TRUE ) {
                salida = i;
                break;
            }
        }
    }
    return salida;
}

int aumentarIDCliente( eCliente listadoClientes[] , int len ) {
    int maximo = 0;
    for( int i = 0 ; i < len ; i++ ) {
        if( (listadoClientes[i].isEmpty == 0) && (listadoClientes[i].idCliente > maximo) ) {
            maximo = listadoClientes[i].idCliente;
        }
    }
    return maximo+1;
}

int addCliente( eCliente listadoClientes[] , int len , char name[] , char lastName[] , int localidad , long int telefono , int edad , char sexo ) {
    int salida = -1;
    int index = findFreeSpaceCliente( listadoClientes , len );
    if( index != salida && listadoClientes != NULL && len > 0 ) {
        listadoClientes[index].idCliente = aumentarIDCliente( listadoClientes , len );
        formatearString( name );
        formatearString( lastName );
        strcpy( listadoClientes[index].name , name );
        strcpy( listadoClientes[index].lastName , lastName );
        listadoClientes[index].idLocalidad = localidad;
        listadoClientes[index].telefono = telefono;
        listadoClientes[index].edad = edad;
        listadoClientes[index].sexo = sexo;
        listadoClientes[index].isEmpty = 0;
        salida = 0;
    }
    return salida;
}

int cantidadLugaresDisponiblesClientes( eCliente listadoClientes[] , int len ) {
    int lugaresDisponibles = 0;
    if( listadoClientes != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoClientes[i].isEmpty == TRUE ) {
                lugaresDisponibles++;
            }
        }
    }
    return lugaresDisponibles;
}

void getTelefono( long int* dato , char mensaje[] , char error[] , long int min , long int max ) {
    char aux[strlen(mensaje)];
    long int valor;
    int salida = -1;
    do {
        printf( "\n%s" , mensaje );
        scanf( "%s" , aux );
        valor = toLongInt( aux );
        if( valor != 0 && valor >= min && valor <= max ) {
            salida = 0;
            *dato = valor;
        } else {
            printf( "%s\n" , error );
        }
    } while( salida != 0 );
}

int ingresarDatosDeUnCliente( eCliente listadoClientes[] , int len , eLocalidad listadoLocalidades[] , int lenL ) {
    int salida = -1;
    char auxName[30];
    char auxLastName[30];
    int auxLocalidad;
    long int auxTelefono;
    int auxEdad;
    char auxSexo;
    if( listadoClientes != NULL && len > 0 ) {
        if( cantidadLugaresDisponiblesClientes(listadoClientes,len) > 0 ) {
            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente el nombre" , 30 );
            getDatoGenericoString( auxLastName , "Ingrese apellido: " , "ERROR ! ingrese nuevamente el apellido" , 30 );
            imprimirLocalidades(listadoLocalidades,lenL);
            getDatoGenericoInt( &auxLocalidad , "Ingrese localidad: " , "ERROR ! ingrese nuevamente la localidad" , 1 , 3 , 3 );
            getTelefono( &auxTelefono , "Ingrese el telefono: " , "ERROR ! ingrese nuevamente el telefono" , 0 , 2147483647 );
            formatearString( auxName );
            formatearString( auxLastName );
            getDatoGenericoInt( &auxEdad , "Ingrese edad: " , "ERROR ! ingrese nuevamente la edad" , 0 , 100 , 3 );
            auxSexo = getDatoGenericoChar("Ingrese el sexo <m-f>: ","ERROR ! ingrese el caracter correspondiente",'m','f');
            addCliente( listadoClientes , len , auxName , auxLastName , auxLocalidad , auxTelefono , auxEdad , auxSexo );
            salida = 0;
        } else {
            printf("\nERROR ! No hay lugar disponible.\n");
        }
    }
    return salida;
}

int ingresarDatosDeXClientes( eCliente listadoClientes[] , int len , eLocalidad listadoLocalidades[] , int lenL ) {
    int salida = -1;
    char respuesta;
    if( listadoClientes != NULL && len > 0 ) {
        do{
            if( ingresarDatosDeUnCliente(listadoClientes,len,listadoLocalidades,lenL) == 0 ) {
                printf("\nCliente ingresado con exito.\n");
            }
            if( cantidadLugaresDisponiblesClientes(listadoClientes,len) > 0 ){
                respuesta = getDatoGenericoChar("Desea ingresar otro cliente? <s-n>: ","ERROR ! ingrese el caracter correspondiente",'s','n');
                if( respuesta == 'N' || cantidadLugaresDisponiblesClientes(listadoClientes,len) == 0 ) {
                    salida = 0;
                }
            } else {
                salida = 0;
            }
        } while( salida != 0 );
    }
    return salida;
}

int seCargoCliente( eCliente listadoClientes[] , int len ) {
    int salida = -1;
    if( listadoClientes != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                salida = 0;
                break;
            }
        }
    }
    return salida;
};

int bajaCliente( eCliente listadoClientes[] , int len , int id ) {
    int salida = -1;
    int index = buscarClientePorID( listadoClientes , len , id );
    if( index != -1 ) {
        listadoClientes[index].isEmpty = 1;
        salida = 0;
    }
    return salida;
}

int modificarCliente( eCliente listadoClientes[] , int len , eLocalidad listadoLocalidades[] , int lenL ) {
    int salida = -1;
    int menuMod;
    int indexCliente;
    int auxID;
    char auxName[30];
    char auxLastName[30];
    int auxLocalidad;
    long int auxTelefono;
    int auxEdad;
    char auxSexo;
    imprimirClientes( listadoClientes , len );
    getDatoGenericoInt( &auxID , "\nIngrese ID del cliente: " , "ERROR ! ingrese nuevamente el ID" , 100 , 200 , 3 );
    printf( "\nQue desea modificar ?\n" );
    menuMod = menuModificarCliente();
    indexCliente = buscarClientePorID( listadoClientes , len , auxID );
    switch(menuMod) {
        case 1:
            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente el nombre" , 30 );
            formatearString(auxName);
            strcpy( listadoClientes[indexCliente].name , auxName );
            printf( "\nNombre modificado con exito.\n" );
            imprimirColumnasTablaClientes();
            imprimirUnCliente( listadoClientes[indexCliente] );
            salida = 0;
            break;
        case 2:
            getDatoGenericoString( auxLastName , "Ingrese apellido: " , "ERROR ! ingrese nuevamente el apellido" , 30 );
            formatearString(auxLastName);
            strcpy( listadoClientes[indexCliente].lastName , auxLastName );
            printf( "\nApellido modificado con exito.\n" );
            imprimirColumnasTablaClientes();
            imprimirUnCliente( listadoClientes[indexCliente] );
            salida = 0;
            break;
        case 3:
            imprimirLocalidades(listadoLocalidades,lenL);
            getDatoGenericoInt( &auxLocalidad , "Ingrese localidad: " , "ERROR ! ingrese nuevamente la localidad" , 1 , 3 , 3 );
            listadoClientes[indexCliente].idLocalidad = auxLocalidad;
            printf( "\nLocalidad modificada con exito.\n" );
            imprimirColumnasTablaClientes();
            imprimirUnCliente( listadoClientes[indexCliente] );
            salida = 0;
            break;
        case 4:
            getTelefono( &auxTelefono , "Ingrese el telefono: " , "ERROR ! ingrese nuevamente el telefono" , 0 , 2147483647 );
            listadoClientes[indexCliente].telefono = auxTelefono;
            printf( "\nTelefono modificado con exito.\n" );
            imprimirColumnasTablaClientes();
            imprimirUnCliente( listadoClientes[indexCliente] );
            salida = 0;
            break;
        case 5:
            getDatoGenericoInt( &auxEdad , "Ingrese edad: " , "ERROR ! ingrese nuevamente la edad" , 0 , 100 , 3 );
            listadoClientes[indexCliente].edad = auxEdad;
            printf( "\nEdad modificada con exito.\n" );
            imprimirColumnasTablaClientes();
            imprimirUnCliente( listadoClientes[indexCliente] );
            salida = 0;
            break;
        case 6:
            auxSexo = getDatoGenericoChar("Ingrese el sexo <m-f>: ","ERROR ! ingrese el caracter correspondiente",'m','f');
            listadoClientes[indexCliente].sexo = auxSexo;
            printf( "\nSexo modificado con exito.\n" );
            imprimirColumnasTablaClientes();
            imprimirUnCliente( listadoClientes[indexCliente] );
            salida = 0;
            break;
        case 7:
            salida = 0;
            break;
    }
    return salida;
}

void edadPromedioVaronesYMujeres( eCliente listadoClientes[] , int len ) {
    int sumaEdadesVarones=0;
    int sumaEdadesMujeres=0;
    int contadorVarones=0;
    int contadorMujeres=0;
    int promedioTotal;
    int promedioVarones;
    int promedioMujeres;
    if( listadoClientes != NULL && len > 0 ) {
        for( int j = 0 ; j < len ; j++ ) {
            if( listadoClientes[j].isEmpty == FALSE ) {
                if( listadoClientes[j].sexo == 'f' ) {
                    sumaEdadesMujeres+=listadoClientes[j].edad;
                    contadorMujeres++;
                } else {
                    sumaEdadesVarones+=listadoClientes[j].edad;
                    contadorVarones++;
                }
            }
        }
        if( sumaEdadesVarones > 0 && contadorVarones > 0 && sumaEdadesMujeres > 0 && contadorMujeres > 0 ) {
            promedioTotal = (sumaEdadesMujeres+sumaEdadesVarones) / (contadorMujeres+contadorVarones);
            promedioVarones = sumaEdadesVarones / contadorVarones;
            promedioMujeres = sumaEdadesMujeres / contadorMujeres;
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------");
        printf(" \nLA EDAD PROMEDIO DE LOS CLIENTES ES: %d" , promedioTotal );
        printf("\n-------------------------------------------------------------------------------------------------------------------");
        printf(" \nLA EDAD PROMEDIO DE LOS VARONES ES: %d" , promedioVarones );
        printf("\n-------------------------------------------------------------------------------------------------------------------");
        printf(" \nLA EDAD PROMEDIO DE LAS MUJERES ES: %d" , promedioMujeres );
        printf("\n-------------------------------------------------------------------------------------------------------------------");
    }
}

void porcentajeDeMujeres( eCliente listadoClientes[] , int len ) {
    int contadorClientes=0;
    int contadorMujeres=0;
    float porcentaje;
    if( listadoClientes != NULL && len > 0 ) {
        for( int j = 0 ; j < len ; j++ ) {
            if( listadoClientes[j].isEmpty == FALSE ) {
                contadorClientes++;
                if( listadoClientes[j].sexo == 'f' ) {
                    contadorMujeres++;
                }
            }
        }
        if( contadorMujeres > 0 && contadorClientes > 0 ) {
            porcentaje = (contadorMujeres*100)/contadorClientes;
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------");
        printf(" \nEl porcentaje que tengo de mujeres sobre el total de clientes es: %.2f" , porcentaje );
        printf("\n-------------------------------------------------------------------------------------------------------------------");
    }
}

int imprimirLocalidades( eLocalidad listadoLocalidades[] , int len ) {
    int salida = -1;
    if( listadoLocalidades != NULL && len > 0 ) {
        imprimirColumnasDatosLocalidades();
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoLocalidades[i].isEmpty == FALSE ) {
                printf( "\n%4d %17s %25s %25d" , listadoLocalidades[i].idLocalidad
                                               , listadoLocalidades[i].provincia
                                               , listadoLocalidades[i].descripcion
                                               , listadoLocalidades[i].codPostal);
            }
        }
        printf("\n----------------------------------------------------------------------------");
        salida = 0;
    }
    return salida;
};


void mostrarClientesOrdenadosPorLocalidadYNombreCliente( eCliente listadoClientes[] , int lenC ) {
    eCliente auxCliente;
    if( listadoClientes != NULL && lenC > 0 ) {
        for( int j = 0 ; j < lenC-1 ; j++ ) {
            for( int i = j+1 ; i < lenC ; i++ ) {
                if( listadoClientes[j].idLocalidad > listadoClientes[i].idLocalidad ) {
                    auxCliente = listadoClientes[j];
                    listadoClientes[j] = listadoClientes[i];
                    listadoClientes[i] = auxCliente;
                } else {
                    if( listadoClientes[j].idLocalidad == listadoClientes[i].idLocalidad && strcmp(listadoClientes[j].name,listadoClientes[i].name) < 0 ) {
                        auxCliente = listadoClientes[j];
                        listadoClientes[j] = listadoClientes[i];
                        listadoClientes[i] = auxCliente;
                    }
                }
            }
        }
        imprimirColumnasTablaClientes();
        for( int i = 0 ; i < lenC ; i++ ) {
            if( listadoClientes[i].isEmpty == FALSE ) {
                printf( "\n%4d %20s %22s %12d %7c %20d %20li" , listadoClientes[i].idCliente
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



