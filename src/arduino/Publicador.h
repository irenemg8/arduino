// -*- mode: c++ -*-

// --------------------------------------------------------------
// Jordi Bataller i Mascarell
// --------------------------------------------------------------

#ifndef PUBLICADOR_H_INCLUIDO
#define PUBLICADOR_H_INCLUIDO

// --------------------------------------------------------------
// --------------------------------------------------------------
// // El diseño completo de la clase está en la carpeta doc

class Publicador {

  // ............................................................
  // ............................................................
private:

// Esto es el UUID del Beacon
uint8_t beaconUUID[16] = { //UUID del Beacon // --------------------------------------------- CAMBIAR
 'E', 'L', 'E', 'C', 'T', 'R', 'O', 'D', 'O', 'M', 'E', 'S', 'T', 'I', 'C', 'O'
 };
  

  // ............................................................
  // ............................................................
public:
// Esto es la emisora. La clase EmisoraBLE está en EmisoraBLE.h
  EmisoraBLE laEmisora {
	"Pvchipu", //  nombre emisora   //Nombre que aparece como dispositivo en nRFConnect ----------- CAMBIAR
	  0x004c, // fabricanteID (Apple)
	  4 // txPower
	  };
  
  const int RSSI = -53; 

  // ............................................................
  // ............................................................
public:

  // ............................................................
  // ............................................................
  enum MedicionesID  {  // --------------------------------------------- CAMBIAR
	CO2 = 11,
	};

  // ............................................................
  // ............................................................
  Publicador( ) {
	// ATENCION: no hacerlo aquí. (*this).laEmisora.encenderEmisora();
	// Pondremos un método para llamarlo desde el setup() más tarde
  } // ()

  // ............................................................
  // ............................................................
  // -> encenderEmisora() ->
  // Esta función enciende la emisora
  void encenderEmisora() {
	(*this).laEmisora.encenderEmisora();
  } // ()

  // ............................................................
  // ............................................................
  // Z, Z, Z -> publicarCO2() ->
  // Esta función publica un valor de CO2 con un contador y un tiempo de espera. Los valores se publican en un iBeacon
  void publicarCO2( int16_t valorCO2, uint8_t contador, long tiempoEspera ) {

	//
	// 1. empezamos anuncio
	//
	uint16_t major = (MedicionesID::CO2 << 8) + contador;  				//Lo que se envía en el major
	(*this).laEmisora.emitirAnuncioIBeacon( (*this).beaconUUID, 		//Contenido del beacon
											major,
											valorCO2, // minor
											(*this).RSSI // rssi
									);

	/*
	Globales::elPuerto.escribir( "   publicarCO2(): valor=" );
	Globales::elPuerto.escribir( valorCO2 );
	Globales::elPuerto.escribir( "   contador=" );
	Globales::elPuerto.escribir( contador );
	Globales::elPuerto.escribir( "   todo="  );
	Globales::elPuerto.escribir( major );
	Globales::elPuerto.escribir( "\n" );
	*/

	//
	// 2. esperamos el tiempo que nos digan
	//
	esperar( tiempoEspera );

	//
	// 3. paramos anuncio
	//
	(*this).laEmisora.detenerAnuncio();
  } // ()

 
}; // class

// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
#endif
