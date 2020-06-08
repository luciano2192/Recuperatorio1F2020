typedef struct {
    int idLocalidad;
    char provincia[30];
    char descripcion[50];
    int codPostal;
    int isEmpty;
} eLocalidad;


typedef struct {
    int idCliente;
    char name[30];
    char lastName[30];
    //char localidad[51];
    int idLocalidad;
    long int telefono;
    int edad;
    char sexo;
    int isEmpty;
} eCliente;

void harcodeoListadoClientes( eCliente listadoClientes[] , int len );

void harcodeoListadoLocalidades( eLocalidad listadoLocalidades[] , int len );

int initClientes( eCliente listadoClientes[] , int len );

int initClientesLibres( eCliente listadoClientes[] , int len );

void imprimirColumnasTablaClientes();

void imprimirColumnasDatosCliente();

void imprimirColumnasDatosLocalidades();

int imprimirUnCliente( eCliente cliente );

int imprimirClientes( eCliente listadoClientes[] , int len );

int imprimirLocalidades( eLocalidad listadoLocalidades[] , int len );

int buscarClientePorID( eCliente listadoClientes[] , int len , int id );

int bajaCliente( eCliente listadoClientes[] , int len , int id );

int seCargoCliente( eCliente listadoClientes[] , int len );

int ingresarDatosDeXClientes( eCliente listadoClientes[] , int len , eLocalidad listadoLocalidades[] , int lenL );

int ingresarDatosDeUnCliente( eCliente listadoClientes[] , int len , eLocalidad listadoLocalidades[] , int lenL );

int cantidadLugaresDisponiblesClientes( eCliente listadoClientes[] , int len );

int aumentarIDCliente( eCliente listadoClientes[] , int len );

int findFreeSpaceCliente( eCliente listadoClientes[] , int len  );

void getTelefono( long int* dato , char mensaje[] , char error[] , long int min , long int max );

int addCliente( eCliente listadoClientes[] , int len , char name[] , char lastName[] , int localidad , long int telefono , int edad , char sexo );

int modificarCliente( eCliente listadoClientes[] , int len , eLocalidad listadoLocalidades[] , int lenL );

void edadPromedioVaronesYMujeres( eCliente listadoClientes[] , int len );

void porcentajeDeMujeres( eCliente listadoClientes[] , int len );
