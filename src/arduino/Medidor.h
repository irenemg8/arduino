// -*- mode: c++ -*-

#ifndef MEDIDOR_H_INCLUIDO
#define MEDIDOR_H_INCLUIDO
#define pin_gas 28 // pin de lectura del sensor de gas
#define pin_vref 5 // pin de referencia del sensor de gas
#define TIAGain 499 // ganancia, viene en el datasheet del sensor
float sensitivityCode = -41.26;

// El diseño completo de la clase está en la carpeta doc

class Medidor {
  private:

  public:
  // .....................................................
  // constructor
  // .....................................................
  // -> constructor() ->
  Medidor(  ) {
  } // ()

  // .....................................................
  // .....................................................
  // -> iniciarMedidor() ->
  void iniciarMedidor() {
	// las cosas que no se puedan hacer en el constructor, if any
  } // ()
  
  // medirCO2() -> float
  // Esta función devuelve el valor de CO2 en ppm, pero por ahora solo enviaremos un dato fijo
  float medirCO2() {
    return 2111;   //----------- CAMBIAR ESTE DATO
  } // ()

  // .....................................................
  // .....................................................
 
  
  
}; // class

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
#endif
