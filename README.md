# ESP32WiFiWebServer

Este repositorio contiene un proyecto para el ESP32 que permite configurar y controlar el dispositivo a través de una interfaz web. Utilizando `Preferences`, los usuarios pueden ingresar el SSID y la contraseña de su red Wi-Fi, los cuales son almacenados de manera persistente en la memoria del ESP32. El dispositivo opera en modo dual, funcionando tanto como estación (STA) para conectarse a redes Wi-Fi, como punto de acceso (AP) para permitir la configuración inicial. Incluye ejemplos de manejo de endpoints HTTP para controlar el estado de los pines GPIO y otras funcionalidades.

## Características

- Configuración de red Wi-Fi a través de una interfaz web.
- Almacenamiento persistente de SSID y contraseña usando `Preferences`.
- Modo dual: estación (STA) y punto de acceso (AP).
- Endpoints HTTP para controlar el estado de los pines GPIO.

## Requisitos

- ESP32
- Framework Arduino
- Biblioteca `WiFi.h`
- Biblioteca `WebServer.h`
- Biblioteca `Preferences.h`

## Instalación

1. Clona este repositorio: `git clone https://github.com/AlvarLegaz/ESP32_wifi_web_server.git`
2. Abre el proyecto en tu IDE de Arduino.
3. Configura las dependencias necesarias.
4. Carga el código en tu ESP32.

## Uso

1. Conecta el ESP32 a una fuente de alimentación.
2. Accede al punto de acceso creado por el ESP32.
3. Ingresa el SSID y la contraseña de tu red Wi-Fi a través de la interfaz web.
4. El ESP32 se conectará automáticamente a la red configurada y estará listo para ser controlado.

