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

//Test para probar Led.h
LED led (7);
  // Ejecución
//Test para ver si el led se enciende
void test_LedEncendido() {
  led.apagar();
  esperar(1000);
  // Prueba de encender el LED
    Serial.println("Prueba de encender el LED...");
    led.encender();
    if (digitalRead(7) == HIGH) {
        Serial.println("LED encendido correctamente.");
    } else {
        Serial.println("Error: LED no se encendió.");
    }
    esperar(1000); // Esperar 1 segundo
}

//Test para ver si el led se apaga
void test_LedApagado() {
  led.encender();
  esperar(1000);
  // Prueba de apagar el LED
    Serial.println("Prueba de apagar el LED...");
    led.apagar();
    if (digitalRead(7) == LOW) {
        Serial.println("LED apagado correctamente.");
    } else {
        Serial.println("Error: LED no se apagó.");
    }
    esperar(1000); // Esperar 1 segundo
}



//Test para ver que alterna la iluminación el led
void test_alternar() {
  Serial.println("Prueba de alternar el LED...");
    led.alternar(); // Debería encender el LED
    if (digitalRead(7) == HIGH) {
        Serial.println("LED encendido tras alternar.");
    } else {
        Serial.println("Error: LED no se encendió tras alternar.");
    }
    esperar(1000); // Esperar 1 segundo
    led.alternar(); // Debería apagar el LED
    if (digitalRead(7) == LOW) {
        Serial.println("LED apagado tras alternar.");
    } else {
        Serial.println("Error: LED no se apagó tras alternar.");
    }
    esperar(1000); // Esperar 1 segundo
}
