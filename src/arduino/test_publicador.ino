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
  Publicador publicadorPrueba;

// 1. Preparación
   void pruebaPublicador(){
    Serial.println("Iniciando pruebas para la clase Publicador...");
    
    // Prueba de encender la emisora
    Serial.println("Prueba de encender la emisora...");
    publicadorPrueba.encenderEmisora();

    // 2. Ejecución
    int16_t valorCO2Fake = 400; // Valor de CO2 a publicar
    uint8_t contadorFake = 1; // Contador para el anuncio
    long tiempoEsperaFake = 2000; // Tiempo de espera en milisegundos

    // Publicar CO2
    Serial.println("Prueba de publicar CO2...");
    publicadorPrueba.publicarCO2(valorCO2Fake, contadorFake, tiempoEsperaFake);

    // 3. Expectativas
    Serial.println("Expectativas:");
    Serial.println(" - Se espera que la emisora se encienda correctamente.");
    Serial.println(" - Se espera que se emita un anuncio IBeacon con el valor de CO2.");
    Serial.println(" - Se espera que el anuncio se detenga después del tiempo especificado.");
    
    // 4. Aserción (comprobación)
    // Aquí se pueden implementar aserciones según el contexto, pero como estamos usando Serial
    // Las salidas deben ser revisadas manualmente

   }
