
// -*- mode: c++ -*-

// ----------------------------------------------------------
// Jordi Bataller i Mascarell
// 2019-07-07
// ----------------------------------------------------------

#ifndef PUERTO_SERIE_H_INCLUIDO
#define PUERTO_SERIE_H_INCLUIDO

// ----------------------------------------------------------
// ----------------------------------------------------------
// // El diseño completo de la clase está en la carpeta doc
class PuertoSerie  {

public:
  // .........................................................
  // .........................................................
  PuertoSerie (long baudios) {  //115200 baudios
	Serial.begin( baudios );
	// mejor no poner esto aquí: while ( !Serial ) delay(10);   
  } // ()

  // .........................................................
  // .........................................................
  // -> esperarDisponible() ->
  void esperarDisponible() {
	delay(10);   

  } // ()

  // .........................................................
  // .........................................................
  template<typename T>

  // T -> escribir() ->
  // Esta función escribe un mensaje en el puerto serie
  void escribir (T mensaje) {
	Serial.print( mensaje );   //Imprime el mensaje en el puerto serie
  } // ()
  
}; // class PuertoSerie

// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
#endif
