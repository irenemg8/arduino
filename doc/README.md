# Proyecto Arduino - Beacon con Emisión y Medición de CO2

## Descripción General

Este proyecto utiliza un dispositivo basado en Arduino para implementar un sistema de medición de CO2 y emisión de beacons mediante Bluetooth. Se utiliza la biblioteca `bluefruit` para la transmisión de datos por BLE (Bluetooth Low Energy) y las bibliotecas personalizadas `LED`, `PuertoSerie`, `EmisoraBLE`, `Publicador`, y `Medidor` para manejar distintos aspectos del sistema.

El sistema mide valores de CO2 a través de sensores y publica los datos a través de un beacon utilizando el protocolo iBeacon. El LED integrado se utiliza como indicador visual, mientras que la comunicación se gestiona a través de un puerto serie a 115200 baudios.

## Estructura del Código

### 1. `setup()`
La función `setup()` inicializa la placa y configura los componentes esenciales del sistema:
- Configura el puerto serie para la comunicación.
- Enciende la emisora BLE para comenzar la transmisión de los datos del beacon.
- Envía mensajes de depuración al monitor serie para confirmar la correcta inicialización.

### 2. `loop()`
La función `loop()` se ejecuta continuamente y realiza las siguientes tareas:
- Incrementa un contador para llevar un registro del número de iteraciones.
- Hace brillar el LED con una secuencia de encendido/apagado.
- Mide el nivel de CO2 y publica los resultados mediante BLE.
- Muestra en el monitor serie el valor de CO2, además del `Major` y `Minor` del beacon.

### 3. Funciones adicionales
#### `inicializarPlaquita()`
Función vacía reservada para inicializaciones futuras.

#### `lucecitas()`
Controla el comportamiento del LED, haciéndolo brillar en intervalos específicos como indicador de actividad.

## Instalación y Configuración

1. **Requisitos del hardware**: Se necesita un dispositivo Arduino compatible con BLE, como la placa [nRF52840](https://learn.sparkfun.com/tutorials/nrf52840-development-with-arduino-and-circuitpython).
2. **Bibliotecas**: Asegúrate de incluir las siguientes bibliotecas en tu proyecto:
    - `bluefruit.h`
    - `LED.h`
    - `PuertoSerie.h`
    - `EmisoraBLE.h`
    - `Publicador.h`
    - `Medidor.h`

Para instalar estas bibliotecas, agrégalas a tu IDE de Arduino o colócalas en la carpeta `libraries`.

## Ejecución de Tests

Para ejecutar las pruebas automáticas de tu proyecto:
1. Dirígete a la carpeta `tests` donde encontrarás los archivos correspondientes.
2. Sube el código de pruebas al dispositivo Arduino.
3. Observa los resultados en el monitor serie.

Las pruebas cubren:
- Verificación de la emisión correcta de datos por BLE.
- Validación de las mediciones de CO2.
- Funcionamiento del LED y del puerto serie.

## Documentación Adicional

Puedes encontrar más información y diagramas de diseño en la carpeta `docs`. Los archivos ahí incluidos proporcionan diagramas de flujo y explicaciones detalladas de las funciones.

### Estructura de la carpeta `docs`:
- `funciones.md`: Explica cada una de las funciones y sus interacciones.
- `diagramas/`: Contiene diagramas de bloques y de flujo.
- `manual_de_uso.pdf`: Manual completo de uso del sistema.

## Contribuciones

Si deseas contribuir a este proyecto, sigue estos pasos:
1. Haz un fork del repositorio.
2. Crea una rama con el nombre de tu característica o corrección: `git checkout -b nombre-rama`.
3. Realiza tus cambios y asegúrate de que pasen los tests.
4. Crea un Pull Request y describe los cambios realizados.

## Licencia

Este proyecto está bajo la licencia MIT. Para más información, consulta el archivo `LICENSE`.




### `EmisoraBLE.h`

Este archivo contiene la implementación de la clase `EmisoraBLE`, que se encarga de gestionar la emisora Bluetooth Low Energy (BLE) para la transmisión de beacons. La clase permite configurar, encender y apagar la emisora, además de emitir anuncios utilizando el protocolo iBeacon. 

#### Funcionalidades principales:
- **Encendido y apagado de la emisora**: Control del inicio y detención de la emisión de datos por BLE.
- **Emisión de beacons**: Emisión de tramas iBeacon con UUID, major, minor, y rssi.
- **Emisión con carga libre**: Posibilidad de personalizar la carga del anuncio iBeacon para enviar información específica.
- **Servicios BLE**: Soporte para añadir servicios BLE personalizados y sus características.
- **Callbacks de conexión**: Instalación de funciones de callback para manejar eventos de conexión y desconexión BLE.

#### Métodos destacados:
- `void encenderEmisora()`: Inicia la emisora BLE y detiene cualquier anuncio activo.
- `void detenerAnuncio()`: Detiene la emisión de anuncios BLE.
- `void emitirAnuncioIBeacon()`: Emite un anuncio iBeacon con los parámetros UUID, major, minor, y rssi.
- `void emitirAnuncioIBeaconLibre()`: Permite emitir un anuncio iBeacon con una carga libre personalizada.
- `bool anyadirServicio()`: Añade un servicio BLE a la emisora.
- `void instalarCallbackConexionEstablecida()`: Instala un callback para eventos de conexión BLE.
- `void instalarCallbackConexionTerminada()`: Instala un callback para eventos de desconexión BLE.

#### Documentación adicional:
El diseño completo de esta clase se encuentra documentado en la carpeta `docs`, donde se explican las interacciones internas y la arquitectura de la emisora BLE.
### `LED.h`

Este archivo define la clase `LED`, la cual permite controlar un LED conectado a un pin específico de la placa. La clase proporciona métodos para encender, apagar, alternar el estado y hacer brillar el LED por un período determinado.

#### Funcionalidades principales:
- **Encendido y apagado del LED**: Control directo para encender o apagar el LED conectado a un pin.
- **Alternar el estado del LED**: Posibilidad de cambiar el estado del LED entre encendido y apagado.
- **Brillar por un tiempo específico**: Permite encender el LED por un número determinado de milisegundos y luego apagarlo automáticamente.

#### Métodos destacados:
- `void encender()`: Enciende el LED.
- `void apagar()`: Apaga el LED.
- `void alternar()`: Alterna entre los estados encendido y apagado del LED.
- `void brillar(long tiempo)`: Enciende el LED durante un tiempo específico (en milisegundos) y luego lo apaga.

#### Documentación adicional:
El diseño completo de la clase se encuentra en la carpeta `docs`, donde se detalla la arquitectura y los casos de uso de la clase LED.



### `Medidor.h`

Este archivo define la clase `Medidor`, que se encarga de obtener mediciones de CO2 a partir de un sensor conectado a la placa. Por ahora, la función de medición devuelve un valor fijo, pero está preparada para leer datos reales del sensor de gas conectado a los pines definidos.

#### Funcionalidades principales:
- **Inicialización del medidor**: Se prepara el sensor de gas para tomar lecturas.
- **Medición del nivel de CO2**: Devuelve el valor de CO2 en partes por millón (ppm). Actualmente, devuelve un valor fijo, pero puede ser configurada para leer del sensor.

#### Variables destacadas:
- `pin_gas`: Pin de la placa donde está conectado el sensor de gas.
- `pin_vref`: Pin de referencia del sensor de gas.
- `TIAGain`: Ganancia del amplificador, según el datasheet del sensor.
- `sensitivityCode`: Código de sensibilidad del sensor, utilizado para ajustar las lecturas.

#### Métodos destacados:
- `void iniciarMedidor()`: Inicializa el medidor de gas.
- `float medirCO2()`: Devuelve un valor de CO2 en ppm (valor actualmente fijo, pero se puede cambiar para devolver mediciones reales del sensor).

#### Documentación adicional:
El diseño completo de la clase se encuentra en la carpeta `docs`, donde se detallan las especificaciones del sensor y la forma de realizar lecturas más precisas.



### `Publicador.h`

Este archivo define la clase `Publicador`, la cual gestiona la publicación de datos mediante iBeacon, utilizando la clase `EmisoraBLE`. En este proyecto, la clase `Publicador` se utiliza para enviar valores de CO2 junto con otros datos a través de Bluetooth Low Energy (BLE).

#### Funcionalidades principales:
- **Gestión de la emisora BLE**: Encendido y control de la emisora BLE para la transmisión de información en formato iBeacon.
- **Publicación de datos CO2**: Publica los valores de CO2 medidos junto con un contador utilizando la trama iBeacon.
- **Configuración del UUID y otros parámetros del beacon**: Define un UUID específico, y configura los valores `major` y `minor` del iBeacon para transmitir la información.

#### Variables destacadas:
- `uint8_t beaconUUID[16]`: UUID personalizado que identifica la emisora iBeacon.
- `EmisoraBLE laEmisora`: Instancia de la clase `EmisoraBLE`, que maneja las emisiones BLE.
- `const int RSSI`: Valor RSSI (Received Signal Strength Indicator) para la señal emitida.

#### Métodos destacados:
- `void encenderEmisora()`: Enciende la emisora BLE.
- `void publicarCO2(int16_t valorCO2, uint8_t contador, long tiempoEspera)`: Publica el valor de CO2 en un beacon utilizando los campos `major` y `minor` del iBeacon, y detiene la emisión después de un intervalo de tiempo.

#### Documentación adicional:
El diseño completo de la clase `Publicador` y sus interacciones con la emisora BLE se encuentra en la carpeta `docs`.




### `PuertoSerie.h`

Este archivo define la clase `PuertoSerie`, que facilita la comunicación a través del puerto serie del dispositivo Arduino. La clase permite inicializar el puerto a una velocidad de baudios especificada y proporciona métodos para escribir datos en el puerto serie.

#### Funcionalidades principales:
- **Inicialización del puerto serie**: Configura el puerto serie a la velocidad de baudios deseada.
- **Escritura en el puerto serie**: Enviar mensajes y datos a través del puerto serie para la depuración o monitoreo.

#### Métodos destacados:
- `PuertoSerie(long baudios)`: Constructor que inicializa el puerto serie con la velocidad de baudios especificada (por ejemplo, 115200 baudios).
- `void esperarDisponible()`: Añade un pequeño retardo para asegurar que el puerto serie esté listo.
- `template<typename T> void escribir(T mensaje)`: Permite escribir mensajes de cualquier tipo (por ejemplo, texto o números) en el puerto serie.

#### Documentación adicional:
El diseño completo de la clase `PuertoSerie` se encuentra en la carpeta `docs`, donde se explica su implementación y uso en el contexto de la comunicación serie.



### `ServicioEnEmisora.h`

Este archivo define la clase `ServicioEnEmisora`, que permite crear y gestionar servicios BLE personalizados en la emisora. Además, proporciona la capacidad de definir características BLE, las cuales pueden tener propiedades como lectura, escritura y notificación.

#### Funcionalidades principales:
- **Gestión de servicios BLE**: Permite definir un servicio BLE con un UUID único y añadir características al mismo.
- **Características BLE**: Se pueden definir varias características dentro de un servicio, con propiedades y permisos de lectura/escritura.
- **Notificaciones y callbacks**: Las características pueden notificar cambios de datos o instalar callbacks que se activan cuando se escriben datos en ellas.

#### Métodos destacados:
- `ServicioEnEmisora(const char *nombreServicio)`: Constructor que inicializa un servicio BLE utilizando un UUID derivado del nombre del servicio.
- `void anyadirCaracteristica(Caracteristica &car)`: Añade una característica al servicio BLE.
- `void activarServicio()`: Activa el servicio BLE junto con todas sus características.
- `operator BLEService&()`: Convierte una instancia de `ServicioEnEmisora` en un objeto `BLEService`, lo que permite usarla como tal en otras partes del código.

#### Clase `Caracteristica`:
La clase anidada `Caracteristica` permite definir las características BLE, con las siguientes funcionalidades:
- **Definir UUIDs y propiedades**: Los UUID de las características se configuran a partir de un string, y se pueden asignar propiedades (lectura, escritura, notificación) y permisos de acceso.
- **Escritura y notificación de datos**: Se puede escribir en la característica y notificar los datos a otros dispositivos BLE.
- **Instalación de callbacks**: Permite instalar callbacks que se activan cuando se escriben datos en la característica.

#### Métodos principales de la clase `Caracteristica`:
- `Caracteristica(const char *nombreCaracteristica)`: Constructor que inicializa una característica con un UUID.
- `void asignarPropiedadesPermisosYTamanyoDatos(uint8_t props, SecureMode_t permisoRead, SecureMode_t permisoWrite, uint8_t tam)`: Asigna propiedades, permisos y tamaño de los datos.
- `uint16_t escribirDatos(const char *str)`: Escribe datos en la característica.
- `uint16_t notificarDatos(const char *str)`: Notifica los datos a otros dispositivos BLE.
- `void instalarCallbackCaracteristicaEscrita(CallbackCaracteristicaEscrita cb)`: Instala un callback para gestionar la escritura de datos en la característica.

#### Funciones auxiliares:
- `T* alReves(T* p, int n)`: Invierte el contenido de un array.
- `uint8_t* stringAUint8AlReves(const char* pString, uint8_t* pUint, int tamMax)`: Copia un string en un array de números al revés.

#### Documentación adicional:
El diseño completo de la clase `ServicioEnEmisora` se encuentra en la carpeta `docs`, donde se explican las interacciones con los servicios y características BLE.





## Ejecución de Tests

Los tests para este proyecto permiten validar el funcionamiento correcto de diferentes componentes, como el LED controlado por la clase `LED`. A continuación se describen los tests implementados y cómo ejecutarlos.

### Preparación

1. Conecta tu dispositivo Arduino y asegúrate de que el pin 7 está conectado a un LED.
2. Sube el código de pruebas al dispositivo.
3. Abre el **Monitor Serie** en el IDE de Arduino para observar los resultados de las pruebas.

### Tests Implementados

#### Test: `test_LedEncendido()`
Este test verifica si el LED puede encenderse correctamente cuando se llama a la función `encender()`.

- **Ejecución**: El LED se apaga inicialmente, luego se enciende.
- **Expectativa**: El LED debería encenderse, y el Monitor Serie debería mostrar `LED encendido correctamente.`
- **Comprobación**: Se verifica si el estado del pin es `HIGH`.

#### Test: `test_LedApagado()`
Este test valida que el LED se apaga correctamente cuando se llama a la función `apagar()`.

- **Ejecución**: El LED se enciende inicialmente, luego se apaga.
- **Expectativa**: El LED debería apagarse, y el Monitor Serie debería mostrar `LED apagado correctamente.`
- **Comprobación**: Se verifica si el estado del pin es `LOW`.

#### Test: `test_alternar()`
Este test verifica si el método `alternar()` cambia correctamente el estado del LED entre encendido y apagado.

- **Ejecución**: Se alterna el estado del LED (de apagado a encendido, y luego de encendido a apagado).
- **Expectativa**: El LED debería alternar su estado, mostrando `LED encendido tras alternar` y luego `LED apagado tras alternar` en el Monitor Serie.
- **Comprobación**: Se comprueba el estado del pin después de cada alternancia.

### Ejecución de Tests

Para ejecutar estos tests:

1. Sube el código de prueba al dispositivo Arduino.
2. Abre el Monitor Serie en el IDE de Arduino para observar los resultados.
3. Los tests se ejecutarán automáticamente y mostrarán los resultados en el Monitor Serie.

### Desmontaje (Teardown)

Al finalizar cada test, los estados de los componentes (como el LED) vuelven a su estado inicial para evitar interferencias entre tests. El LED debería quedar apagado al final de cada prueba.




### Test: `test_getMedicionCO2()`
Este test valida que la función `medirCO2()` de la clase `Medidor` devuelve el valor de CO2 en ppm correctamente, que por ahora está configurado para devolver un valor fijo (2222 ppm).

- **Preparación**: Se instancia un objeto `Medidor`.
- **Ejecución**: Se llama al método `medirCO2()` y se imprime el valor medido en el Monitor Serie.
- **Expectativa**: Se espera que el valor devuelto por la función sea `2222`.
- **Comprobación**: Si el valor retornado es diferente a `2222`, el Monitor Serie mostrará el mensaje `Funciona mal Medidor.h`.
- **Desmontaje**: No es necesario desmontaje adicional, ya que no hay cambios en el estado que afecten a otras pruebas.

### Ejecución de Tests

Para ejecutar este test:
1. Sube el código al dispositivo Arduino.
2. Abre el Monitor Serie en el IDE de Arduino.
3. El valor medido debería aparecer en el Monitor Serie, y si no es `2222`, se mostrará un mensaje de error.



### Test: `pruebaPublicador()`
Este test verifica el funcionamiento de la clase `Publicador`, específicamente la capacidad de encender la emisora y publicar datos de CO2 a través de un anuncio iBeacon.

- **Preparación**: Se inicializa un objeto `Publicador` y se enciende la emisora BLE.
- **Ejecución**: 
  - Publica un valor ficticio de CO2 (`400 ppm`) con un contador (`1`) durante un tiempo especificado de 2000 ms.
  - La prueba emite los datos a través del iBeacon y espera el tiempo definido antes de detener el anuncio.
- **Expectativa**:
  - La emisora debe encenderse correctamente.
  - Se debe emitir un anuncio iBeacon que incluya el valor de CO2.
  - El anuncio debe detenerse después del tiempo especificado.
- **Comprobación**: Debido a la naturaleza de esta prueba, las salidas deben ser revisadas manualmente en el Monitor Serie. Se espera ver mensajes que confirmen la emisión del anuncio y la detención después de los 2000 ms.
- **Desmontaje**: Se asegura que la emisora se detiene correctamente al finalizar la prueba.

### Ejecución de Tests

Para ejecutar esta prueba:
1. Sube el código al dispositivo Arduino.
2. Abre el Monitor Serie en el IDE de Arduino.
3. Verifica los mensajes impresos que confirmen que la emisora se encendió, emitió el valor de CO2 y luego detuvo el anuncio.

