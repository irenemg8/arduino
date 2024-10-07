// -*-c++-*-

// --------------------------------------------------------------
//
// Jordi Bataller i Mascarell
// 2019-07-07
//
// --------------------------------------------------------------

// https://learn.sparkfun.com/tutorials/nrf52840-development-with-arduino-and-circuitpython

// https://stackoverflow.com/questions/29246805/can-an-ibeacon-have-a-data-payload

// --------------------------------------------------------------
// --------------------------------------------------------------
#include <bluefruit.h>

#undef min // vaya tela, están definidos en bluefruit.h y  !
#undef max // colisionan con los de la biblioteca estándar
#define PIN_O3 5
// --------------------------------------------------------------
// --------------------------------------------------------------
#include "LED.h"
#include "PuertoSerie.h"

// --------------------------------------------------------------
// --------------------------------------------------------------
namespace Globales {
  LED elLED ( 7 ); // pin 7
  PuertoSerie elPuerto ( 115200 ); // 115200 baudios
};

// --------------------------------------------------------------
// --------------------------------------------------------------
#include "EmisoraBLE.h" // para el beacon
#include "Publicador.h" // para publicar valores
#include "Medidor.h" // para medir valores


// --------------------------------------------------------------
// --------------------------------------------------------------
namespace Globales {          // declaración de variables globales para que sea accesible desde cualquier parte
  Publicador elPublicador;
  Medidor elMedidor;
}; // namespace

// --------------------------------------------------------------
// --------------------------------------------------------------
//  -> inicializrPlaquita() ->
void inicializarPlaquita () {   

  // de momento nada

} // ()

// --------------------------------------------------------------
// --------------------------------------------------------------
// -> setup() ->
void setup() {

  Globales::elPuerto.esperarDisponible();   // espera a que el puerto serie esté disponible

  inicializarPlaquita();  

  // Suspend Loop() to save power
  // suspendLoop();

  Globales::elPublicador.encenderEmisora();   // enciende la emisora
  // Globales::elPublicador.laEmisora.pruebaEmision();
  
  esperar( 1000 );

  Globales::elPuerto.escribir( "---- setup(): fin ---- \n " );    // mensaje de fin de setup


  //-----------------------------------------------------------------------
  //--------- Probar funcionamiento mandar beacon valores major minor -----
/* Agrega aquí el bloque de código
    Globales::elPuerto.escribir("UUID: ");
    for (int i = 0; i < 16; i++) {
        Globales::elPuerto.escribir(Globales::elPublicador.beaconUUID[i]);
    }*/
    Globales::elPuerto.escribir("\n");

    // Si tienes un valor mayor inicial, puedes usarlo aquí
    uint16_t major = 0; // O algún valor por defecto
    Globales::elPuerto.escribir("Major: ");
    Globales::elPuerto.escribir(major);
    Globales::elPuerto.escribir("\n");

    Globales::elPuerto.escribir("Minor: ");
    Globales::elPuerto.escribir(0); // Coloca un valor por defecto o inicial aquí
    Globales::elPuerto.escribir("\n");
} // setup ()

// --------------------------------------------------------------
// --------------------------------------------------------------
// -> lucecitas() ->
// Esta función se encarga de hacer brillar el LED 100 ms y apagarlo 400 ms 
inline void lucecitas() {     //inline significa que el compilador copia el código en el lugar donde se llama
  using namespace Globales;

  elLED.brillar( 100 ); // 100 encendido
  esperar ( 400 ); //  100 apagado
  elLED.brillar( 100 ); // 100 encendido
  esperar ( 400 ); //  100 apagado
  Globales::elLED.brillar( 100 ); // 100 encendido
  esperar ( 400 ); //  100 apagado
  Globales::elLED.brillar( 1000 ); // 1000 encendido
  esperar ( 1000 ); //  100 apagado

  Globales::elMedidor.iniciarMedidor();
} // ()

// --------------------------------------------------------------
// loop ()
// --------------------------------------------------------------
// Este contador se incrementa en cada iteración del loop.
// Se usa para saber cuántas veces se ha ejecutado el loop -> Lo podemos ver en el monitor serie.
namespace Loop {
  uint8_t cont = 0;
};

// --------------------------------------------------------------
// --------------------------------------------------------------

// -> loop() ->
void loop () {

  using namespace Loop;
  using namespace Globales;

  cont++;

  elPuerto.escribir( "\n---- loop(): empieza " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );


  lucecitas();

  // mido el valor del gas y publico el resutlado
  float valorCO2 = elMedidor.medirCO2();
  
  elPublicador.publicarCO2( valorCO2, cont, 1000 // intervalo de emisión
							);


//-----------------------------------------------------------------------------
// Código para mostrar el UUID, Major y Minor
    uint16_t major = (Publicador::MedicionesID::CO2 << 8) + cont; // Obtén el Major
    /*Globales::elPuerto.escribir("UUID: ");
    for (int i = 0; i < 16; i++) {
        Globales::elPuerto.escribir(Globales::elPublicador.beaconUUID[i]);
    }*/
    Globales::elPuerto.escribir("\nMajor: ");
    Globales::elPuerto.escribir(major);
    Globales::elPuerto.escribir("\nMinor: ");
    Globales::elPuerto.escribir(valorCO2); // Usando el valor de CO2 como Minor
    Globales::elPuerto.escribir("\n");

  
  
  // 
  // prueba para emitir un iBeacon y poner
  // en la carga (21 bytes = uuid 16 major 2 minor 2 txPower 1 )
  // lo que queramos (sin seguir dicho formato)
  // 
  // Al terminar la prueba hay que hacer Publicador::laEmisora privado
  //
  char datos[21] = {   //Mensaje que llega al movil --------- CAMBIAR
    'L', 'a', 
    'C', 'a', 's', 'a',
    'D', 'e',
    'L', 'a',
    'A', 'b', 'u', 'e', 'l', 'a',
    'J', 'u', 'a', 'n', 'a'
    };    

  // elPublicador.laEmisora.emitirAnuncioIBeaconLibre ( &datos[0], 21 );
  elPublicador.laEmisora.emitirAnuncioIBeaconLibre ( &datos[0], 21 );

// --------------------------------------------------------------
// --------------------------------------------------------------
// Mostrar el valor de CO2 en el monitor serie
  Serial.print("Gas: ");
  Serial.println(valorCO2);
 
  // Añade un retardo para evitar saturar el puerto serie
  delay(1000);
  
//------------------------------------------------------------------------

  esperar( 2000 );

  elPublicador.laEmisora.detenerAnuncio();

  // 
  // 
  // 
  elPuerto.escribir( "---- loop(): acaba **** " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );
  
  
} // loop ()
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
