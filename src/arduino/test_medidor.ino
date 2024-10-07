/*
 * Preparación (setup)
 * Ejecución
 * Expectativas
 * Aserción (comprobación)
 * Desmontaje (teardown) - OJO dejar todo como estaba al principio cuando finalice el test
 */

 /* 
  *  Posibles test a realizar y comprobaciones:
  *  - Casos en los que funciona / no funciona
  *  - Longitud del resultado de salida
  *  - Tipo de dato de salida
  *  - Casos de éxito / fallo, y qué pasa si falla
  */

//Test para probar Medidor.h
void test_getMedicionCO2() {
  // Preparación
  Medidor medidor;
  // Ejecución
  float medicion = medidor.medirCO2();
  Serial.println(medicion);
  // Expectativas
  // Debe aparecer un 2222 en el puerto serie
  // Aserción
  if(medicion != 2222){
    Serial.println("Funciona mal Medidor.h");
  }
  // Desmontaje
}
